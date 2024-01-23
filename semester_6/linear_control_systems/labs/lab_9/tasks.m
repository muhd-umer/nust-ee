%% Pre-Lab
close all
G = zpk([], [-1, -2, -3], 1)
figure
rlocus(G)
K = 18;
Gcl = feedback(series(K, G), 1) %#ok<*NOPTS>

%% Exercise 1
close all
G = tf([1 4 4.25], [1 -1 -1 15])
figure
rlocus(G)
K = 3.38;
Gcl1 = feedback(series(K, G), 1)
figure
rlocus(Gcl1)
K = 3.89;
Gcl2 = feedback(series(K, G), 1)
figure
rlocus(Gcl2)

%% Exercise 2
close all
num = 0.0334;
den = [1.566e-5, 1.11556e-3];
G = tf(num, den)
stepinfo(G)

figure
rlocus(G)
K = 0.00332;
Gcl = feedback(series(K, G), 1)
stepinfo(Gcl)

%% Exercise 3
close all
num = 0.0334;
den = [1.566e-5, 1.11556e-3, 0];
G = tf(num, den)
stepinfo(G)
figure
rlocus(G)

K = 0.5;
Gcl = feedback(series(K, G), 1)
stepinfo(Gcl)
figure
rlocus(Gcl)

%% Exercise 4
close all
G1 = zpk(roots([1 -2 5]), [-1 -2 -3], 1)
figure
rlocus(G1)
G2 = zpk([-7 1+2*1i 1-2*1i], [-1 -2 -3 2+3*1i 2-3*1i], 1)
figure
rlocus(G2)
G3 = zpk(-2, [-1, -6+5*1i -6-5*1i 2+3*1i 2-3*1i], 1)
figure
rlocus(G3)