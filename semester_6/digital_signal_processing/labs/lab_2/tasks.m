%% Task 1
one_cos(95, 200, pi / 5, 0.025)

%% Task 2
% Define syn_sin.m function.

%% Task 3
[x, t] = syn_sin([0, 100, 250], [10, 14 * exp(-1i * pi / 3), ...
                                 8 * 1i], 100000, 0.1, 0);
plot(t, x, 'LineWidth', 1.15)
ylabel('x(t)')
xlabel('t')
title('Task 3')
grid on

%% Task 4
X1 = 2; X2 = 2 * exp(1i * pi * (-1.25)); X3 = (1 - 1i);
[x, t] = syn_sin([1/2, 1/2, 1/2], [X1, X2, X3], 10000, 6, -0.5);

plot(t, x, 'LineWidth', 1.15)
ylabel('x(t)')
xlabel('t')
title('Task 4')
grid on