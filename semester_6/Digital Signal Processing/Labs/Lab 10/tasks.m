%% Lab Task 1
Td = 2;
w_c = 0.3 * pi;
omega_c = w_c / Td;
N = 4;
k = 0:(N - 1);
s_k = omega_c * exp(1i * (pi / 2 * N) * (2 * k + N - 1));
H_c = zpk([], s_k, omega_c ^ N);
[num, den] = zp2tf([], s_k, omega_c ^ N);

num = real(num); den = real(den);

H = tf(num, den);

% impulse response
figure(1);
impulse(H);
title('Impulse Response');
xlabel('Time (s)');
ylabel('Amplitude');

% magnitude response
w = 0:0.01:pi;
figure(2);
[h, w] = freqz(num, den, w);
plot(w/Td, abs(h));
title('Magnitude Response');
xlabel('Frequency (rad/s)');
ylabel('Magnitude');

% convert to digital filter using impulse invariance
figure(3);
[bz, az] = impinvar(num, den, 1 / Td);
[h, w] = freqz(bz, az, w);

plot(w, abs(h));
title('Magnitude Response');
xlabel('Frequency (rad)');
ylabel('Magnitude');

% convert to digital filter using bilinear transform
figure(4);
[bz, az] = bilinear(num, den, 1 / Td);
[h, w] = freqz(bz, az, w);

plot(w, abs(h));
title('Magnitude Response');
xlabel('Frequency (rad)');
ylabel('Magnitude');

%% Lab Task 2a
fs = 200;
Rp = 1;
Wp = 32/(fs/2);
Ws = 38/(fs/2);
Rs = 25;

% get order and cutoff
[n, Wn] = buttord(Wp, Ws, Rp, Rs);
disp(['Order: ', num2str(n)]);

% define filter
[b, a] = butter(n, Wn);

% show impulse response
[h, t] = impz(b, a);
figure(1);
subplot(311);
stem(t, h);
title('Impulse Response');
xlabel('Time (s)');
ylabel('Amplitude');

% show magnitude response
w = 0:0.01:pi;
[h, w] = freqz(b, a, w);
subplot(312);
plot(w/pi, abs(h));
title('Magnitude Response');
xlabel('Frequency (rad)');
ylabel('Magnitude');

% define discrete filter transfer function
H = tf(b, a, -1, 'variable', 'z^-1');
subplot(313);
pzmap(H);

%% Lab Task 2b
fs = 200;
Rp = 1;
Wp = 32/(fs/2);
Ws = 38/(fs/2);
Rs = 25;

% get order and cutoff
[n, ~] = cheb1ord(Wp, Ws, Rp, Rs);
disp(['Order: ', num2str(n)]);

% define filter
[b, a] = cheby1(n, Rp, Wp);

% show impulse response
[h, t] = impz(b, a);
figure(1);
subplot(311);
stem(t, h);
title('Impulse Response');
xlabel('Time (s)');
ylabel('Amplitude');

% show magnitude response
w = 0:0.01:pi;
[h, w] = freqz(b, a, w);
subplot(312);
plot(w/pi, abs(h));
title('Magnitude Response');
xlabel('Frequency (rad)');
ylabel('Magnitude');

% define discrete filter transfer function
H = tf(b, a, -1, 'variable', 'z^-1');
subplot(313);
pzmap(H);

%% Lab Task 2c
fs = 200;
Rp = 1;
Wp = 32/(fs/2);
Ws = 38/(fs/2);
Rs = 25;

% get order and cutoff
[n, Wn] = ellipord(Wp, Ws, Rp, Rs);
disp(['Order: ', num2str(n)]);

% define filter
[b, a] = ellip(n, Rp, Rs, Wp);

% show impulse response
[h, t] = impz(b, a);
figure(1);
subplot(311);
stem(t, h);
title('Impulse Response');
xlabel('Time (s)');
ylabel('Amplitude');

% show magnitude response
w = 0:0.01:pi;
[h, w] = freqz(b, a, w);
subplot(312);
plot(w/pi, abs(h));
title('Magnitude Response');
xlabel('Frequency (rad)');
ylabel('Magnitude');

% define discrete filter transfer function
H = tf(b, a, -1, 'variable', 'z^-1');
subplot(313);
pzmap(H);