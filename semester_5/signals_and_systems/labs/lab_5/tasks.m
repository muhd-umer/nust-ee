%% Task 1.1
n = -5:5;
% Definitions
x1 = n == 0;
x2 = (2 * n) == 0;
y1 = sin((pi / 2) .* x1);
y2 = sin((pi / 2) .* x2);
y_add = y1 + y2; % Sum of y
x = x1 + x2;
y = sin((pi / 2) .* x); % Additive y

% Plots
subplot(211)
stem(n, y_add, 'filled', 'b')
title('Output: y1[n] + y2[n]')
grid
subplot(212)
stem(n, y, 'filled', 'r')
title('Output: y[n] for x1[n] + x2[n]')
grid
xlabel('n')

%% Task 1.2
n = -5:9;
% Definitions
x = n >= 0;
x_shifted = (n + 1) >= 0;
y = x + x_shifted;

% Plots
subplot(311)
stem(n, x, 'filled', 'b')
title('Input x[n]')
grid
axis([-5 9 0 1])
subplot(312)
stem(n, x_shifted, 'filled', 'r')
title('Shifted input x[n+1]')
axis([-5 9 0 1])
grid
subplot(313)
stem(n, y, 'filled', 'r')
title('Output y')
axis([-5 8 0 2])
grid
xlabel('n')

%% Task 1.3
n_def = -5:5;
% Definitions
x = (n >= -1) - (n > 1);
n1 = 0.5 * n_def;
n2 = (0.5 * n_def) + 1;
n1_p = 0.5 * (n_def + 1);
y = x;

% Plots
subplot(311)
stem(n1, y, 'filled', 'b')
title('y1 = x1[2n]')
grid
subplot(312)
stem(n2, y, 'filled', 'r')
title('y2 = x1[2n-1]')
grid
subplot(313)
stem(n1_p, y, 'filled', 'm')
title('y1_p = y[n-1]')
grid
xlabel('n')

%% Task 2.1
x_n = [1 2 3 4 5];
y_n = [1 1 1 1 1];

lhs = conv(x_n, y_n)
rhs = conv(y_n, x_n)

if lhs == rhs
    disp('Commutative property holds.')
end

%% Task 2.2
x = imread('image.jpg');
h1_n = [0.25 0.5 0.25];
h2_n = [0.25; 0.5; 0.25];

% x[n] * (h1[n] * h2[n]) = (x[n] * h1[n]) * h2[n]
h3_n = convn(h1_n, h2_n);
lhs = convn(x, h3_n);
size_lhs = size(lhs)
h4_n = convn(x, h1_n);
rhs = convn(h4_n, h2_n);
size_rhs = size(rhs)

if lhs == rhs
    disp('Associative property holds.')
end