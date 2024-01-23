%% Design 1
% open loop system
sys = tf(1, [1 10 20]);

% open loop system properties
stepinfo(sys) % step response information of the open loop system
err = abs(1 - dcgain(sys)) % steady state error for a step input ...
% to the open loop system

%% Design 2
% open loop system
sys = tf(1, [1 10 20]);

% open loop system properties
stepinfo(sys) % step response information of the open loop system
abs(1 - dcgain(sys)) % steady state error for a step input ...
% to the open loop system

% proportional controller
rlocus(sys)
Kp = 9; % proportional gain
ctrl = zpk([], [], Kp); % define the proportional controller TF
sys_cl = feedback(series(ctrl, sys), 1); % find the closed loop system
stepinfo(sys_cl)
err = abs(1 - dcgain(sys_cl))

%% Design 3: PD controller design
zero_loc = -15;
compensator = zpk(zero_loc, [], ...
    1);
rlocus(series(compensator, sys));
Kd = 25;
Kp = -Kd * zero_loc;
ctrl_p = zpk([], [], Kp); % proportional part of controller
ctrl_d = zpk(0, [], Kd); % derivate part of controller
ctrl = parallel(ctrl_p, ctrl_d); % controller TF
sys_cl = feedback(series(ctrl, sys), 1); % closed loop sys
stepinfo(sys_cl)
err = abs(1 - dcgain(sys_cl))

%% Design 4: PI controller design
zero_loc = -3;
compensator = zpk(zero_loc, 0, 1);
rlocus(series(compensator, sys));
Kp = 25;
Ki = -Kp * zero_loc;
ctrl_p = zpk([], [], Kp); % proportional part of controller
ctrl_i = zpk([], 0, Ki); % integral part of controller
ctrl = parallel(ctrl_p, ctrl_i); % controller TF
sys_cl = feedback(series(ctrl, sys), 1); % closed loop sys
stepinfo(sys_cl)
err = abs(1 - dcgain(sys_cl))

%% Design 5: PID controller design
zero_loc_pi = -1;
zero_loc_pd = -15;
compensator = zpk([zero_loc_pi, zero_loc_pd], 0, 1);
rlocus(series(compensator, sys));
Kd = 50;
Kp = -(zero_loc_pd + zero_loc_pi) * Kd;
Ki = zero_loc_pd * zero_loc_pi * Kd;
ctrl_p = zpk([], [], Kp); % proportional part of controller
ctrl_i = zpk([], 0, Ki); % integral part of controller
ctrl_d = zpk(0, [], Kd); % derivative part of controller
ctrl = parallel(parallel(ctrl_p, ctrl_i), ctrl_d); % controller TF
sys_cl = feedback(series(ctrl, sys), 1); % closed loop sys
stepinfo(sys_cl)
err = abs(1 - dcgain(sys_cl))
