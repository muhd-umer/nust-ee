%% Task 6.1.2
b = [0.5, 0.5]; % filter coeffs
w = -pi:(pi / 100):pi;
H = freqz(b, 1, w); % <--freekz.m is an alternative
subplot(2, 1, 1);
plot(w, abs(H))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Task 1.ab
n = -5:5;
x_n = (n == 0);
L = 4;
y_n = zeros(1, length(n));

w = -pi:(pi / 400):pi;
H = ((2*cos(0.5*w) + 2*cos(1.5*w))/4).*exp(-1i*1.5*w);

subplot(2, 1, 1);
plot(w, abs(H))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Task 1.c
b = 1/4*ones(1, 4);
H = freqz(b, 1, w);

subplot(2, 1, 1);
plot(w, abs(H))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Task 6.1.5
mag_zeros = find(abs(H) < 1e-6);

%% Task 6.1.6
n = 0:9;
alpha = 0.8;

%% Filter 1
b1 = alpha.^n;
w = -pi:(pi / 400):pi;
H1 = freqz(b1, 1, w);

figure
subplot(2, 1, 1);
plot(w, abs(H1))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H1))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Filter 2
b2 = [1, -alpha, zeros(1, 8)];
H2 = freqz(b2, 1, w);

figure
subplot(2, 1, 1);
plot(w, abs(H2))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H2))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Cascade
H = H1.*H2;
figure
subplot(2, 1, 1);
plot(w, abs(H))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Task 2.a
b_p44pi = [1 -2 * cos(0.44 * pi) 1];
b_7pi = [1 -2 * cos(0.7 * pi) 1];
b = conv(b_044, b_07);
w = -pi:(pi / 400):pi;
H = freqz(b, 1, w);

figure
subplot(2, 1, 1);
plot(w, abs(H))
title('Magnitude Response')
grid
subplot(2, 1, 2);
plot(w, angle(H))
title('Phase Response')
xlabel('Normalized Radian Frequency')
grid

%% Task 2.b
n = 0:149;
x_n = 5*cos(0.3*pi*n) + 22*cos(0.44*pi*n - pi/3) ...
    + 22*cos(0.7*pi*n - pi/4);
figure
stem(n, x_n)
title('Task 2.b')
xlabel('Sample Points [n]')
grid

%% Task 2.c
y_n = filter(b, 1, x_n);
stem(n, y_n)
title('Task 2.c')
xlabel('Sample Points [n]')
grid

%% Task 2.d
n_obv = 5:40;
figure
filtered_x_n = 10*cos(0.3*pi*(n_obv-2));
stem(n_obv, filtered_x_n)
title('Task 2.d')
xlabel('Sample Points [n]')
grid

