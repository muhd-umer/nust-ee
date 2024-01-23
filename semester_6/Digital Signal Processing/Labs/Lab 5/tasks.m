%% Original Signal
[x, Fs] = audioread('sample.wav');
L = length(x);

NFFT = 2 ^ nextpow2(L); % Next power of 2 from length of y
Y1 = fft(x, NFFT) / L;
f = Fs / 2 * linspace(0, 1, NFFT / 2 + 1);
Fc = Fs / 2;

figure
plot(f, 2 * abs(Y1(1:NFFT / 2 + 1))), grid on
title('Single-Sided Spectrum of Original Signal')
xlabel('Frequency (Hz)')
sound(x, Fs)

%% Downsampled by 2
[b, a] = butter(6, Fc / (Fs / 2) - 0.01);
filtered_x = filter(b, a, x);
downsampled_x = filtered_x(1:2:end);

Y2 = fft(downsampled_x, NFFT) / L;
sound(downsampled_x, Fs / 2)

%% Downsampled by 3
filtered_x = filter(b, a, x);
downsampled_x = downsample(filtered_x, 3);

Y3 = fft(downsampled_x, NFFT) / L;
sound(downsampled_x, Fs / 3)

%% Downsampled by 5
filtered_x = filter(b, a, x);
downsampled_x = downsample(filtered_x, 5);

Y4 = fft(downsampled_x, NFFT) / L;
sound(downsampled_x, Fs / 5)

%% Downsampled by 10
filtered_x = filter(b, a, x);
downsampled_x = downsample(filtered_x, 10);

Y5 = fft(downsampled_x, NFFT) / L;
sound(downsampled_x, Fs / 10)

%% Unfiltered Downsampling by 10
downsampled_x = downsample(x, 10);

Y6 = fft(downsampled_x, NFFT) / L;
sound(downsampled_x, Fs / 10)

%% Plots
figure
subplot(2, 1, 1)
plot(f, 2 * abs(Y1(1:NFFT / 2 + 1))), grid on
title('Spectrum of Original Signal')
xlabel('Frequency (Hz)')
subplot(2, 1, 2)
plot(f, 2 * abs(Y2(1:NFFT / 2 + 1)))
grid on
title('Spectrum of M=2 Downsampled Signal')
xlabel('Frequency (Hz)')

figure
subplot(2, 1, 1)
plot(f, 2 * abs(Y1(1:NFFT / 2 + 1))), grid on
title('Spectrum of Original Signal')
xlabel('Frequency (Hz)')
subplot(2, 1, 2)
plot(f, 2 * abs(Y3(1:NFFT / 2 + 1)))
grid on
title('Spectrum of M=3 Downsampled Signal')
xlabel('Frequency (Hz)')

figure
subplot(2, 1, 1)
plot(f, 2 * abs(Y1(1:NFFT / 2 + 1))), grid on
title('Spectrum of Original Signal')
xlabel('Frequency (Hz)')
subplot(2, 1, 2)
plot(f, 2 * abs(Y4(1:NFFT / 2 + 1)))
grid on
title('Spectrum of M=5 Downsampled Signal')
xlabel('Frequency (Hz)')

figure
subplot(2, 1, 1)
plot(f, 2 * abs(Y1(1:NFFT / 2 + 1))), grid on
title('Spectrum of Original Signal')
xlabel('Frequency (Hz)')
subplot(2, 1, 2)
plot(f, 2 * abs(Y5(1:NFFT / 2 + 1)))
grid on
title('Spectrum of M=10 Downsampled Signal')
xlabel('Frequency (Hz)')

figure
subplot(2, 1, 1)
plot(f, 2 * abs(Y1(1:NFFT / 2 + 1))), grid on
title('Spectrum of Original Signal')
xlabel('Frequency (Hz)')
subplot(2, 1, 2)
plot(f, 2 * abs(Y6(1:NFFT / 2 + 1)))
grid on
title('Spectrum of Unfiltered M=10 Downsample')
xlabel('Frequency (Hz)')
