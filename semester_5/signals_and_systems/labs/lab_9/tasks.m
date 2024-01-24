%% Task 1
f1 = 400; f2 = 800; Fs = 20 * f2;
t = 0:1 / Fs:0.05;
x = sin(2 * pi * f1 * t) + sin(2 * pi * f2 * t);
X = fftshift(fft(x, length(t)));
L = length(t);
df = Fs / L;
index = -L / 2:(L / 2) - 1;
frequency_axis = df * index;

subplot(311)
plot(t, x, 'LineWidth', 1.1)
grid
title('Original Function x(t)')
xlabel('time (s)')
ylabel('x(t)')

subplot(312)
plot(frequency_axis, abs(X), 'LineWidth', 1.1)
grid
title('Amplitude Spectrum of FFT of x(t)')
xlabel('Frequency (Hz)')
ylabel('Amplitude')

subplot(313)
plot(2 * pi * frequency_axis, abs(X), 'LineWidth', 1.1)
grid
title('Amplitude Spectrum of FFT of x(t)')
xlabel('Frequency (radians)')
ylabel('Amplitude')

%% Task 2
n = 100;
t = 0:1/n:5;
x = exp(-2 * t) .* (t > 0);
X = 1 / n * fftshift(fft(x, length(t)));
L = length(t);
df = n / L;
index = -L / 2:(L / 2) - 1;
frequency_axis = df * index;

subplot(311)
plot(t, x, 'LineWidth', 1.1)
grid
title('Original Function x(t)')
xlabel('time (s)')
ylabel('x(t)')

subplot(312)
plot(frequency_axis, abs(X), 'LineWidth', 1.1)
grid
title('Amplitude Spectrum of FFT of x(t)')
xlabel('Frequency (Hz)')
ylabel('Amplitude')

subplot(313)
plot(frequency_axis, angle(X), 'LineWidth', 1.1)
axis([-4 4 -pi/1.8 pi/1.8])
grid
title('Phase Spectrum of FFT of x(t)')
xlabel('Frequency (Hz)')
ylabel('Amplitude')

%% Task 3
t = linspace(-5, 50, 100);
x_1 = exp(0.5 * t) .* (t > 0);
x_2 = sin(t) .* (t > 0);
L = length(t);
timeplot = conv(x_1, x_2, 'full');
f = (-L / 2:0.001:(L / 2) - 1) / L;
freqplot = fftshift(fft(x_1, length(f))) .* fftshift(fft(x_2, length(f)));

subplot(211)
plot(f, abs(fftshift(fft(timeplot, length(f)))));
grid
title('Frequency Domain Plot of Time Domain Convolution')
xlabel('Frequency (Hz)')
ylabel('Amplitude')

subplot(212)
plot(f, abs(freqplot));
grid
title('Frequeency Domain Plot of Frequency Domain Multiplication')
xlabel('Frequency (Hz)')
ylabel('Amplitude')