%% Step 1
close all;
Fs = 44100;
t = -0.1/2:1 / Fs:0.1/2;
f = 10 * Fs / 1024;
x1 = cos(2 * pi * f * t);

figure
plot(t, x1)
title('Step 1: Original Signal')
xlabel("Time (s)")
ylabel('cos(2\pift)')

%% Step 2
figure
plot(t(1:1024), x1(1:1024))
title('Step 2: Initial 1024 Points')
xlabel('Time (s)')
ylabel('cos(2\pift)')

%% Step 3
n = -512:(512 - 1);
N = 1024;
X1 = fftshift(fft(x1, N));

figure
stem(n, abs(X1))
title('Step 3: Sampled FFT')
xlabel('Samples (n)')
ylabel('|X(e^{jw})|')

%% Step 4
df = Fs / N;
index = -N / 2:(N / 2) - 1;
f_axis = (df * index);

figure
stem(f_axis / Fs, abs(X1))
title('Step 4: Normalized FFT')
xlabel('Frequency (rad/sample)')
ylabel('|X(e^{jw})|')

%% Step 5
df = Fs / N;
index = -N / 2:(N / 2) - 1;
f_axis = (df * index);

figure
stem(f_axis, abs(X1))
title('Step 5: Hertz FFT')
xlabel('Frequency (Hz)')
ylabel('|X(e^{jw})|')

%% Step 6
f2 = 10.25 * Fs / 1024; f3 = 13.25 * Fs / 1024;
x2 = cos(2 * pi * f2 * t);
x3 = cos(2 * pi * f3 * t);
X2 = fftshift(fft(x2, N));
X3 = fftshift(fft(x3, N));

figure
hold on
stem(f_axis, abs(X2))
stem(f_axis, abs(X3))
title('Step 6: Spectral Leakage')
xlabel('Frequency (Hz)')
ylabel('|X(e^{jw})|')
legend('X2', 'X3')
axis([-2000 2000 0 600])

%% Step 7
N = 2048;
X1 = fftshift(fft(x1, N));
X2 = fftshift(fft(x2, N));
X3 = fftshift(fft(x3, N));
df = Fs / N;
index = -N / 2:(N / 2) - 1;
f_axis = (df * index);

figure
hold on
stem(f_axis, abs(X1))
stem(f_axis, abs(X2))
stem(f_axis, abs(X3))
title('Step 7: N=2048 FFT')
xlabel('Frequency (Hz)')
ylabel('|X(e^{jw})|')
legend('X1', 'X2', 'X3')
axis([-2e3 2e3 0 1.2e3])

%% Step 8
xc = 50 * x2 + 15 * x3;
N = 1024;
Xc = fftshift(fft(xc, N));
df = Fs / N;
index = -N / 2:(N / 2) - 1;
f_axis = (df * index);

figure
hold on
stem(f_axis, abs(Xc))
title('Step 8: Composite Signal Spectrum')
xlabel('Frequency (Hz)')
ylabel('|X(e^{jw})|')
axis([0 2e3 0 3e4])
grid

%% Step 9
xcw = xc(1:1024) .* hamming(1024)';
Xcw = fftshift(fft(xcw, N));

figure
hold on
stem(f_axis, abs(Xc))
stem(f_axis, abs(Xcw))
title('Step 9: Hamming Window Spectral Comparison')
xlabel('Frequency (Hz)')
ylabel('|X(e^{jw})|')
axis([0 2e3 0 3e4])
legend('Xc', 'Xcw')
grid

%% Step 10
N = 1024;
Fs = 44100;
t = -0.1/2:1 / Fs:0.1/2;
Xr = zeros(1, N);
f = 1291.99;
set_idx = find(min(abs(f_axis - f)) == abs(f_axis - f));
Xr(set_idx) = 500; % to have enough amplitude of x_r(t)
xr = ifft(Xr, N);

figure
stem(f_axis, abs(Xr))
title('Step 10: Spectral Signal')
xlabel('Frequency (Hz)')
ylabel('|X(e^{jw})|')
axis([0 5e3 0 600])

figure
plot(t(1:1024), real(xr))
title('Step 10: Reconstructed x_r(t)')
xlabel('Time (s)')
ylabel('xr(t)')
axis([-0.05 -0.045 -inf inf])
