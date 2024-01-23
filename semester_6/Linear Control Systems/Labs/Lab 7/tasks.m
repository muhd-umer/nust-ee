%% Exercise 1
tf_a = tf([2 2], [1 9 20]);
tf_b = tf([1 1], [1 2 47 60]);
tf_c = tf(1, [1 10]);

step_a = stepinfo(tf_a) %#ok<*NOPTS>
step_b = stepinfo(tf_b)
step_c = stepinfo(tf_c)

%% Exercise 2
sys_a = zpk([], -1, 1);
step(ss(sys_a));
sys_b = zpk([], -2, 2);
hold on
step(ss(sys_b));
sys_c = zpk([], -5, 5);
step(ss(sys_c));
sys_d = zpk([], -10, 10);
step(ss(sys_d));
legend('p=-1', 'p=-2', 'p=-5', 'p=-10');
grid

%% Exercise 3
sys_a = zpk([], -5, 1);
step(ss(sys_a));
sys_b = zpk([], -5, 2);
hold on
step(ss(sys_b));
sys_c = zpk([], -5, 5);
step(ss(sys_c));
sys_d = zpk([], -5, 10);
step(ss(sys_d));
legend('k=1', 'k=2', 'k=5', 'k=10');
grid

%% Exercise 4
sys_a = zpk(-1, -5, 1);
step(ss(sys_a));
sys_b = zpk(-2, -5, 1);
hold on
step(ss(sys_b));
sys_c = zpk(-5, -5, 1);
step(ss(sys_c));
sys_d = zpk(-10, -5, 1);
step(ss(sys_d));
legend('z=-1', 'z=-2', 'z=-5', 'z=-10');
grid

%% Exercise 5
T_r = [0.1, 0.5, 1];
T_s = [1, 1.5 2];
p_a =- (2.2) ./ T_r;
p_b =- (4) ./ T_s;

%% Exercise 6
tf_a = tf(5, [1 -4 5]);
tf_b = tf(2, [1 -2 2]);
tf_c = tf(5, [1 -2 5]);

disp("damp_a: "); damp(tf_a)
disp(newline + "damp_b: "); damp(tf_b)
disp(newline + "damp_c: "); damp(tf_c)

%% Exercise 9
% Set 1
tf_a = my_second_order_tf(0, 1);
tf_b = my_second_order_tf(0, 2);
tf_c = my_second_order_tf(0, 5);
% Set 2
tf_d = my_second_order_tf(1, 1);
tf_e = my_second_order_tf(1, 2);
tf_f = my_second_order_tf(1, 5);
% Set 3
tf_g = my_second_order_tf(0, 1);
tf_h = my_second_order_tf(0.5, 1)
tf_i = my_second_order_tf(1, 1);
tf_j = my_second_order_tf(2, 1);

figure
t = 0:0.01:5;
hold on
step(tf_a, t); step(tf_b, t); step(tf_c, t);
legend('Set 1: 1', 'Set 1: 2', 'Set 1: 3')
grid
figure
hold on
step(tf_d, t); step(tf_e, t); step(tf_f, t);
legend('Set 2: 1', 'Set 2: 2', 'Set 2: 3')
grid
figure
hold on
step(tf_g, t); step(tf_h, t);
step(tf_i, t); step(tf_j, t);
legend('Set 3: 1', 'Set 3: 2', 'Set 3: 3', 'Set 3: 4')
grid

%% Exercise 10
syms T_s T_p p_OS zeta w_n;
eq1 = T_s == 4/(zeta*w_n);
eq2 = T_p == pi/(w_n*sqrt(1-zeta^2));
eq3 = p_OS == 100*exp(-(zeta*pi/sqrt(1-zeta^2)));
eq4 = zeta == -log(p_OS/100)/(sqrt(pi^2+(log(p_OS/100))^2));

eq4 = subs(eq4, p_OS, 10);
zeta_ans = double(solve(eq4, zeta));

eq1 = subs(eq1, {T_s, zeta}, [1, zeta_ans]);
w_n_ans = double(solve(eq1, w_n));

%% Exercise 11
tf_a = tf(1, [1 1 1]);
tf_b = tf([1 1], [1 1 1]);

disp("damp_a: "); damp(tf_a)
disp(newline + "damp_b: "); damp(tf_b)
disp(newline + "step_a: "); stepinfo(tf_a)
disp(newline + "step_b: "); stepinfo(tf_b)
figure
t = 0:0.01:20;
hold on
step(tf_a, t)
step(tf_b, t)
grid
legend('tf_a', 'tf_b')

%% Exercise 12
tf_a = zpk([], -1, 1);
tf_b = zpk([], [-1 -2], 2);
tf_c = zpk([], [-1 -10], 10);
tf_d = zpk([], [-1 -20], 20);
tf_e = zpk([], [-1 -10-5*1i -10+5*1i], 125);

disp("damp_a: "); damp(tf_a)
disp(newline + "damp_b: "); damp(tf_b)
disp(newline + "damp_c: "); damp(tf_c)
disp(newline + "damp_d: "); damp(tf_d)
disp(newline + "damp_e: "); damp(tf_e)
disp(newline + "step_a: "); stepinfo(tf_a)
disp(newline + "step_b: "); stepinfo(tf_b)
disp(newline + "step_c: "); stepinfo(tf_c)
disp(newline + "step_d: "); stepinfo(tf_d)
disp(newline + "step_e: "); stepinfo(tf_e)

figure
t = 0:0.01:8;
hold on
step(tf_a, t)
step(tf_b, t)
step(tf_c, t)
step(tf_d, t)
step(tf_e, t)
grid
legend('tf_a', 'tf_b', 'tf_c', 'tf_d', 'tf_e')

%% Exercise 13
tf_a = zpk([], [-1-2*1i -1+2*1i], 5);
tf_b = zpk([], [-1 -1-2*1i -1+2*1i], 5);
tf_c = zpk([], [-5 -1-2*1i -1+2*1i], 25);
tf_d = zpk([], [-20 -1-2*1i -1+2*1i], 100);

disp("damp_a: "); damp(tf_a)
disp(newline + "damp_b: "); damp(tf_b)
disp(newline + "damp_c: "); damp(tf_c)
disp(newline + "damp_d: "); damp(tf_d)
disp(newline + "step_a: "); stepinfo(tf_a)
disp(newline + "step_b: "); stepinfo(tf_b)
disp(newline + "step_c: "); stepinfo(tf_c)
disp(newline + "step_d: "); stepinfo(tf_d)

figure
t = 0:0.01:8;
hold on
step(tf_a, t)
step(tf_b, t)
step(tf_c, t)
step(tf_d, t)
grid
legend('tf_a', 'tf_b', 'tf_c', 'tf_d')
