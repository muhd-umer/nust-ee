%% Plant
num = 25;
den = [1, 7.5];
plant = tf(num, den);

%% Exercise 1
Kp = 0.038305;
controller = zpk([], [], Kp); % proportional controller
sys = feedback(series(plant, controller), 1);
display(sys)
stepinfo(sys)

%% Exercise 3
Kp = 0.21;
Ki = 1.98;
ctrl_p = zpk([], [], Kp); % proportional part of controller
ctrl_i = zpk([], 0, Ki); % integral part of controller
ctrl = parallel(ctrl_p, ctrl_i); % controller TF
sys_cl = feedback(series(ctrl, plant), 1); % closed loop sys
stepinfo(sys_cl)
err = abs(1 - dcgain(sys_cl));
step(sys_cl)

%% Exercise 5
Kp = 0.5;
controller = zpk([], [], Kp); % proportional controller
sys = feedback(series(plant, controller), 1);
display(sys)
stepinfo(sys)

%% Exercise 5
Kp = 0.5;
controller = zpk([], [], Kp); % proportional controller
sys = feedback(series(plant, controller), 1);
display(sys)
stepinfo(sys)

%% Exercise 6
num = 0.0334;
den = [1.566e-5, 1.11556e-3, 0];
plant = tf(num, den);

Kd = 0.05;
Kp = 0.5;
ctrl_p = zpk([], [], Kp); % proportional part of controller
ctrl_d = zpk(0, [], Kd); % derivate part of controller
ctrl = parallel(ctrl_p, ctrl_d); % controller TF
sys_cl = feedback(series(ctrl, plant), 1); % closed loop sys
stepinfo(sys_cl)

%% Exercise 6
Kd = 0.029039;
Kp = 1.1021;
Ki = 6.3464;
ctrl_p = zpk([], [], Kp); % proportional part of controller
ctrl_i = zpk([], 0, Ki); % integral part of controller
ctrl_d = zpk(0, [], Kd); % derivative part of controller
ctrl = parallel(parallel(ctrl_p, ctrl_i), ctrl_d); % controller TF

sys_cl = feedback(series(ctrl, plant), 1); % closed loop sys
stepinfo(sys_cl)