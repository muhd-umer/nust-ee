%% Pre-Lab
R = 1;
L = 1e-3;
C = 1e-6;

A = [-R/L -1/L; 1/C 0];
B = [1/L; 0];
C = [-R -1];
D = 1;

rlc_ss = ss(A, B, C, D);
rlc_tf = tf(rlc_ss);
rlc_ss2 = ss(rlc_tf);

display(rlc_tf)

%% Exercise 1
% Variables
J_eq = 1.843e-6;
m = 0.0270;
r = 0.0826;
K_g = 1;
J_m = 1.80e-4;
n_g = 1;
n_m = 0.69;
L = 0.0955;
g = 9.9;
K_t = 0.0334;
R = 8.7;

a = J_eq + m*r^2 + n_g*K_g^2*J_m;
b = m*L*r;
c = (4/3)*m*L^2;
d = m*g*L;
e = 2.7183;
f = (n_m*n_g*K_t*K_g) / R;

J_m = 0.01; % moment of inertia
B_m = 0.001; % friction coefficient
Kt_m = 0.01; % torque constant
R_m = 1; % resistance
L_m = 0.01; % inductance

% Define state space matrices
A = [-B_m/J_m, Kt_m/J_m; 0, -1/R_m/L_m];
B = [0; 1/L_m];
C = [1, 0];
D = 0;

% Motor position
num = [-c 0 f*d];
den = [(b^2-a*c) -e*c a*d e*d 0];
position_tf = tf(num, den);

% Pendulum arm angle
num = [-b*f 0 0];
den = [(a*c-b^2) e*c -a*d e*d 0];
arm_tf = tf(num, den);

speed_ss = ss(A, B, C, D);
position_ss = ss(position_tf);
arm_ss = ss(arm_tf);

display(speed_ss)
display(position_ss)
display(arm_ss)

%% Exercise 2
t = 0:0.001:5;

figure
step(speed_tf)
grid
title('Motor Speed Step Response')

figure
step(position_tf)
grid
title('Motor Position Step Response')

figure
step(arm_tf, t)
grid
title('Pendulum Arm Angle Step Response')

%% Exercise 3
t = 0:0.001:5;

figure
impulse(speed_tf, t)
grid
title('Motor Speed Impulse Response')

figure
impulse(position_tf, t)
grid
title('Motor Position Impulse Response')

figure
impulse(arm_tf, t)
grid
title('Pendulum Arm Angle Impulse Response')

%% Exercise 4
t = 0:0.001:5;
u_ramp = t; % ramp
u_square = square(t); % square
u_sine = sin(t); % sine

figure
lsim(speed_ss, u_ramp, t)
grid
title('Motor Speed Ramp Response')

figure
lsim(speed_ss, u_square, t)
grid
title('Motor Speed Square Response')

figure
lsim(speed_ss, u_sine, t)
grid
title('Motor Speed Sine Response')

%% Exercise 5
syms s t;
step_input = 1/s;
impulse_input = 1;
ramp_input = 1/s^2;
speed_tf_syms = 100/(s^2 + 100.1*s + 10);

ilaplace(step_input * speed_tf_syms)
ilaplace(impulse_input * speed_tf_syms)
ilaplace(ramp_input * speed_tf_syms)

%% Exercise 6
K = 5;
sys = feedback(speed_tf, K);
display(sys)
