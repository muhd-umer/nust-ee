%% Task 1.1
syms t;

g1 = (t * sin(2 * t) + exp(2 * t));
g2 = sin(2 * t) * cos(2 * t);
g3 = exp(-t) * cos(3 * t);
g4 = -exp(-t) + 9 * t * exp(-t) + 5 * exp(-2 * t) + (t - 2);
g5 = 5 * (t ^ 2) * cos(3 * t + pi / 4);

fprintf('Laplace of g1(t) = %s\n', laplace(g1))
fprintf('Laplace of g2(t) = %s\n', laplace(g2))
fprintf('Laplace of g3(t) = %s\n', laplace(g3))
fprintf('Laplace of g4(t) = %s\n', laplace(g4))
fprintf('Laplace of g5(t) = %s\n', laplace(g5))

%% Task 1.2
syms s;

G1 = 1 / (s * (s + 1) * (s + 3));
G2 = 10 / ((s + 1) ^ 2 * (s + 3));
G3 = 2 * (s + 1) / (s * (s ^ 2 + s + 2));
G4 = (s + 1) / (s * (s + 2) * (s ^ 2 + 2 * s + 2));

fprintf('Inverse Laplace of G1(s) = %s\n', ilaplace(G1))
fprintf('Inverse Laplace of G2(s) = %s\n', ilaplace(G2))
fprintf('Inverse Laplace of G3(s) = %s\n', ilaplace(G3))
fprintf('Inverse Laplace of G4(s) = %s\n', ilaplace(G4))

%% Task 2
num = [5 10];
den = [1 7 12];

G1 = tf(num, den);
fprintf('Zeroes(s): %d\n', zero(G1))
fprintf('Pole(s): %d\n', pole(G1))

%% Task 3.1
num = [30 -180];
den = [1 4 13 7];

G1 = tf(num, den);
display(G1)
zpk(G1)

%% Task 3.2
num = [1 0 1 1];
den = [1 1 0 6];

G2 = tf(num, den);
display(G2)
zpk(G2)

%% Task 3.3
p = [-4 -2 + 4i -2 - 4i];
z = [2 -4 -5i 5i];

G3 = zpk(p, z, 1);
display(G3)
tf(G3)

%% Task 3.4
num = [1 11 35 250];
den = [1 4 39 108];

G4 = tf(num, den);
display(G4)
zpk(G4)

%% Task 3.5
num = [1 5 6];
den = [1 4 15 35];

G5 = tf(num, den);
display(G5)
zpk(G5)

%% Task 3.6
num = [1 0 -1];
den = [1 0 4 6 4];

G6 = tf(num, den);
display(G6)
zpk(G6)

%% Task 4
figure
pzplot(G1, 'r')
title('Pole-Zero Plot of G1(s)')

figure
pzplot(G2, 'r')
title('Pole-Zero Plot of G2(s)')

figure
pzplot(G3, 'r')
title('Pole-Zero Plot of G3(s)')

%% Task 5
% Performed completely on Simulink

%% Task 6
g = 9.81;
M = 0.5;
m = 0.5;
b = 0.1;
L = 0.3;
I = 0.006;
q = ((M + m) * (I + m * L ^ 2)) - (m * L) ^ 2;

num = [m * L / q 0 0];
den = [1, (b * (I + m * L ^ 2)) / q, - ((M + m) * (m * g * L)) / q, ...
           - (m * g * L) / q 0];

G7 = tf(num, den);
display(G7)