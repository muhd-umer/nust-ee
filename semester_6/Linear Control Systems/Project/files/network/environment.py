"""
Implementation of Multi-Cell Massive MIMO Environment
"""
import numpy as np
import gymnasium as gym
from gymnasium import spaces
from . import network_utils


class MassiveMIMOEnv(gym.Env):
    def __init__(
        self, N=7, M=32, K=10, Ns=10, min_P=-20, max_P=23, num_P=10, dtype=np.float32
    ):
        """
        Initialize the environment
        """
        self.dtype = dtype
        self.N = N  # number of cells is equals to number of BSs
        self.M = M  # number of BS transmission antnneas
        self.K = K  # number of UEs in a cell
        self.Ns = Ns  # number of sample
        self.min_P = min_P  # minimum transmission power [dBm]
        self.max_P = max_P  # maximum transmission power [dBm]
        self.num_P = num_P  # mumber of action space

        # Initialize the action space and observation space
        self.action_value = self.get_power()  # power set
        self.action_num = len(self.action_value)
        self.action_space = spaces.Discrete(self.action_num)
        self.action_length = self.action_num
        self.observation_space = spaces.Box(
            low=np.array(
                [self.min_P, -(np.finfo(np.float32).max), -(np.finfo(np.float32).max)],
                dtype=self.dtype,
            ),
            high=np.array(
                [self.max_P, np.finfo(np.float32).max, np.finfo(np.float32).max],
                dtype=self.dtype,
            ),
            dtype=dtype,
        )

        # Initialize the state
        self.state = None
        self.downlink_rate = None
        self.rate_list = []
        self.count = 0

        # Initialize the channel matrices
        self.H, self.H_gain = network_utils.get_local_scatter(
            self.N, self.M, self.K, self.Ns
        )
        self.precoding = network_utils.get_precoding(self.H)

    def get_power(self):
        power_set = np.hstack(
            [
                np.zeros((1), dtype=self.dtype),
                1e-3
                * pow(10.0, np.linspace(self.min_P, self.max_P, self.num_P - 1) / 10.0),
            ]
        )

        return power_set

    def get_rate(self, channel, precoding, power):
        """
        Calculate the downlink user-rate [bits/s/Hz]

        Args:
            channel: channel matrix
            precoding: precoding matrix
            power: power allocation

        Returns:
            rate: downlink user-rate [bits/s/Hz]
        """
        H, V = channel, precoding
        W = network_utils.complex_normalize(V, -1)

        interval, N, K, M = H.shape[0], H.shape[1], H.shape[3], H.shape[4]
        intercell_intf = np.zeros((N, K))
        intracell_intf = np.zeros((interval, N, K))
        sig = np.zeros((interval, N, K), dtype=self.dtype)

        for n in range(interval):
            for l in range(N):
                H_l = H[n, l]  # (N, K, M)
                for k in range(K):
                    w_l = W[n, l]  # (K, M)
                    H_llk = H_l[l, k]  # (M, ) the channel between l-th BS to user k
                    p_l = np.abs(np.dot(w_l.conj(), H_llk)) ** 2
                    sig[n, l, k] = p_l[k]
                    intracell_intf[n, l, k] = p_l.sum() - p_l[k]
                    if N > 1:
                        idx_othercell = list(range(N))
                        idx_othercell.remove(l)
                        H_intercell = H[
                            n, idx_othercell, l : l + 1, k
                        ]  # (L-1, 1, M) CSI, other cells to this user k
                        w_intercell = W[
                            n, idx_othercell
                        ]  # (L-1, K, M) other cell's precoding vector
                        p_inter = (
                            np.abs(w_intercell @ H_intercell.swapaxes(-1, -2)) ** 2
                        )
                        intercell_intf[l, k] = (
                            intercell_intf[l, k] + p_inter.sum() / interval
                        )

        int_noise = power * intercell_intf + power * intracell_intf + 1
        self.sinr = power * sig / int_noise

        rate = np.log2(1 + self.sinr).mean(axis=0)

        return rate

    def reset(self, seed=None, options=None) -> tuple[np.ndarray, dict]:
        """
        Resets the environment to an initial internal state, returning an initial observation and info.

        Args:
            seed: The seed to use for the environment's random number generator.

        Returns:
            state: The initial state of the environment.
            info: Not implemented.
        """
        super().reset(seed=seed)

        # Initialize the channel matrices
        self.H, self.H_gain = network_utils.get_local_scatter(
            self.N, self.M, self.K, self.Ns
        )
        self.precoding = network_utils.antenna_selection(self.H, ant_sel=False)

        # Reset the counter
        self.count = 0

        # Random allocation to (s_power, s_sinr, s_sumrate)
        self.state = np.random.uniform(low=-0.05, high=0.05, size=(3,))

        # Reset the environment
        self.rate_list = []
        self.action_length = self.action_num

        info = {}

        return np.array(self.state, dtype=self.dtype), info

    def step(self, action: int) -> tuple[np.ndarray, float, bool, bool, dict]:
        """
        Run one timestep of the environment's dynamics using the agent actions.

        When the end of an episode is reached (terminated or truncated), it is
        necessary to call reset to reset this environment's state for the next
        episode.

        Args:
            action: The action taken by the agent.

        Returns:
            next_state: The state of the environment after one
            reward: The reward after one step.
            terminated: Whether the episode has ended.
            truncated: Not implemented.
            info: Contains downlink_rate about the previous action.
        """

        assert self.state is not None, "Call reset before using step method."

        power = self.action_value[action]
        reward = 0

        s_power, s_sinr, s_sumrate = self.state
        downlink_rate = self.get_rate(self.H, self.precoding, power)

        # Append the downlink rate to the rate list
        self.rate_list.append(downlink_rate)

        # Update the state
        s_power, s_sinr, s_sumrate = (power, np.mean(self.sinr), np.mean(downlink_rate))
        self.state = (s_power, s_sinr, s_sumrate)

        # Calculate the reward
        reward = np.mean(downlink_rate)

        self.action_length -= 1
        self.count += 1

        terminated = True if (self.action_length <= 0) else False
        truncated = True if self.action_length <= 0 else False

        info = {
            "downlink_rate": downlink_rate,
        }

        return (
            np.array(self.state, dtype=self.dtype),
            reward,
            terminated,
            truncated,
            info,
        )
