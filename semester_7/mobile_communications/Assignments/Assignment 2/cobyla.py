import math
import sys

import matplotlib.pyplot as plt
import numpy as np
import scipy.optimize as opt
import sympy as sym
from colorama import Back, Fore, Style

plt.rcParams["mathtext.fontset"] = "stix"
plt.rcParams["font.family"] = "STIXGeneral"


class PropagationSimulator:
    """
    A class to simulate path loss propagation.
    """

    def __init__(self, distance_arr, frequency, d0, alpha, N, sigma):
        """
        Constructs all the necessary attributes for the PropagationSimulator object.
        """
        self.distance_arr = distance_arr
        self.frequency = frequency
        self.alpha = alpha
        self.N = N
        self.sigma = sigma
        self.lambda_ = 3e8 / frequency
        self.d0 = d0
        self.d0_loss = 20 * np.log10(4 * np.pi * self.d0 / self.lambda_)

        self.path_loss_arr = np.zeros((len(self.distance_arr), self.N))

        for i, distance in enumerate(self.distance_arr):
            for j in range(self.N):
                self.path_loss_arr[i, j] = self.log_distance(
                    distance, self.alpha, self.sigma
                )

    def log_distance(self, distance, alpha, sigma=None):
        """Log distance path loss model.

        Args:
            distance: Distance between transmitter and receiver.
            alpha: Path loss exponent.
            sigma: Shadow fading standard deviation.

        Returns:
            loss: Path loss in dB.
        """

        loss = self.d0_loss + 10 * alpha * np.log10(distance / self.d0)
        if sigma is not None:
            loss += np.random.normal(0, sigma, np.shape(loss))

        return loss

    def plot_scatter(self):
        """
        Plots a scatter plot of the path loss.
        """

        plt.figure(figsize=(6, 4))
        plt.scatter(
            np.repeat(self.distance_arr, self.N), self.path_loss_arr, s=3, c="black"
        )
        plt.scatter(
            self.distance_arr,
            np.mean(self.path_loss_arr, axis=1),
            s=50,
            marker="x",
            c="red",
        )
        plt.xlabel("Distance [m]")
        plt.ylabel("Path loss [dB]")
        plt.legend(["Samples", "Mean"])
        plt.title("Log-Distance Path Loss")
        plt.grid(alpha=0.35)
        plt.show()


distance_arr = np.array([50, 200, 500, 1000, 2000])
frequency = 10e6
d0 = 50
PL_d0 = 20 * np.log10(4 * np.pi * d0 / (3e8 / frequency))
alpha = 3
N = 50
sigma = 4
lambda_ = 3e8 / frequency

simulator = PropagationSimulator(distance_arr, frequency, d0, alpha, N, sigma)
simulator.plot_scatter()


def optimize_func(x, distance_arr, path_loss_arr):
    alpha, sigma = x
    estimate = np.zeros((len(distance_arr), N))

    for i, distance in enumerate(distance_arr):
        for j in range(N):
            estimate[i, j] = simulator.log_distance(distance, alpha, sigma)

    return np.sum((path_loss_arr - estimate) ** 2)


# initial guess
x0 = [0.5, 5]
res = opt.minimize(
    optimize_func,
    x0,
    args=(distance_arr, simulator.path_loss_arr),
    method="COBYLA",
    bounds=((0, None), (0, None)),
)  # use the Nelder-Mead algorithm
alpha_hat = res.x[0]
sigma_hat = res.x[1]

print("PLE Estimate =", alpha_hat)
print("Sigma Estimate =", sigma_hat)
