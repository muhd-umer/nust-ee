M1 = 1;
M2 = 0.5;
k = 1;
F = 1;
mu = 0.02;
g = 9.8;

plant = tf([M2, M2*g*mu, k], [M1*M2, 2*mu*M1*M2*g, k*M1 + k*M2 ...
    + mu^2*M1*M2*g^2, mu*M1*g*k + mu*M2*g*k]);

Kp = 33.9712;
Ki = 118.3617;
Kd = 0.09662;