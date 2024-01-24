% Muhammad Umer; CMS: 345834: BEE 12C
% Assignment 1 - Signals and Systems (EE-232)
% X = 4

%% Signal definition
tc = gauspuls('cutoff', 50e3, 0.6, [], -40);
t1 = -tc:1e-6:tc;
y1 = gauspuls(t1, 50e3, 0.6);
figure('Name', 'y1 (Original Signal)')
plot(t1 * 1e3, y1)
legend('Original signal')
grid on

%% Task 1: Shift first -> Other transformations
figure('Name', 'Shift first')
t2 = t1 - (3/2 + 4); % Shift signal to left
t2 = t2 / -2; % Compress and inverse
plot(t2, y1, 'red')
legend('Shift first')
grid on

%% Task 2: Other transformations -> Shift last
figure('Name', 'Shift last')
t3 = t1 / -2; % Compress and inverse
t3 = t3 + (3/2 + 4) / 2; % Shift signal to left (/2: to counter compression in line 24)
plot(t3, y1, 'magenta')
legend('Shift last')
grid on

%% Is figure 2 same as figure 3?
fprintf("<strong>Question: Is figure 2 same as figure 3?\n</strong>");
fprintf("Answer: Yes. There is no difference in the two approaches (either\n" + ...
    "shifting first or last), as appropriate measures (i.e. dividing time-shift\n)" + ...
    "by 2 after compressing the signal) are taken to counter the effects on the\n" + ...
    "signal before it. It is also validated by theory; that the resulting signal\n" + ...
    "would be the same, irrespective of the order of transformations.\n");
% Note: We do not create a new function (i.e., y2, y3) with transformations as
% MATLAB rounds, say 1.5000 + 3.4e-05 to just 1.5000, leaving us with a
% straight plot.
