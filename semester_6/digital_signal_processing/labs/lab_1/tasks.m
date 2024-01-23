%% Task 1.1.1
jkl = 0:6;
% This will create a vector array from 0 to 6 with a default spacing of 1.
jkl = 4:4:17;
% This will create a vector array from 4 to 17 with a spacing of 4.
jkl = 99:-1:88;
% This will create a vector array from 99 to 88 with a spacing of -1.
ttt = 2:(1/9):4;
% This will create a vector array from 2 to 4 with a spacing of 1/9.
tpi = pi * (0:0.1:2);
% This will create a vector array from 0 to 2 with a spacing of 0.1, ...
% and then multiply each element with pi.

%% Task 1.1.2
xx = [zeros(1, 3), linspace(0, 1, 5), ones(1, 5)];
[s1, s2] = size(xx)
s3 = length(xx)

%% Task 1.1.3
yy = xx;
yy(4:6) = pi * (1:3)

%% Task 3
x_n = [2 5 -1 4 -5 0];
n = [0 1 2 3 4];
[x_e, x_o, n_o] = evenodd(x_n, n)

%% Task 4
x_n = [2 5 -1 4 -5 0];
y = diffeqn(1, x_n, 0)

%% Task 5
h_n = [1 2 1 2];
x_n = [0 1 2 4 1 1];

% y_n = myconv(x_n, h_n)
y_n = myconv(x_n, h_n, -1:4, -2:1)