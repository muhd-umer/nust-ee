% Muhammad Umer - CMS: 345834
% Muhammad Ahmed Mohsin - CMS: 333060

% Initializing
load('data.mat')
fs = 6e3; % sampling frequency
N = 2*fs; % number of samples
t = linspace(0, 1, 500);
df = fs / N;
index = -N / 2:(N / 2) - 1;
f = (df * index);
X = fftshift(fft(x, N)); % compute the DFT of x
Xn = fftshift(fft(xn, N)); % compute the DFT of xn

%% Frequency Spectrums
% plot the original signal (t and F)
figure(1)
subplot(211)
plot(t, x)
title('Clean Signal in Time Domain')
xlabel('Normalized Time (s)')
ylabel('Amplitude')
subplot(212)
plot(f, abs(X))
title('Clean Signal in Frequency Domain')
xlabel('Frequency (Hz)')
ylabel('Amplitude')

% plot the noisy signal (t and F)
figure(2)
subplot(211)
plot(t, xn)
title('Noisy Signal in Time Domain')
xlabel('Normalized Time (s)')
ylabel('Amplitude')
subplot(212)
plot(f, abs(Xn))
title('Noisy Signal in Frequency Domain')
xlabel('Frequency (Hz)')
ylabel('Amplitude')

%% Devised Approach
% This section cleans a noisy signal by first applying a bandstop filter
% to remove unwanted frequencies, and then applying a bandpass filter
% to keep the desired frequencies. The resulting signal is then plotted
% in the frequency domain.
% Bandstop Filter
f1 = 1e3;
f2 = 1.5e3;
[b_bs, a_bs] = butter(2, [f1 f2]/(fs/2), 'stop');
xn_bs = filter(b_bs, a_bs, xn);
Xn_bs = fftshift(fft(xn_bs, N)); % compute the DFT of xn

% Bandpass Filter
f1 = 1e3;
f2 = 1.5e3;
[b_bp, a_bp] = butter(2, [f1 f2]/(fs/2), 'bandpass');
xn_bp = filter(b_bp, a_bp, xn_bs);
Xn_bp = fftshift(fft(xn_bp, N)); % compute the DFT of xn

%% Magnitude and phase response plots
figure(3)
freqz(b_bs, a_bs)
title('Magnitude and Phase Response of Bandstop Filter')

figure(4)
freqz(b_bp, a_bp)
title('Magnitude and Phase Response of Bandpass Filter')

%% Plotting the filtered output
figure(5)
subplot(211)
plot(t, xn_bp)
title('Filtered Signal in Time Domain')
xlabel('Normalized Time (s)')
ylabel('Amplitude')
subplot(212)
plot(f, abs(Xn_bp))
title('Filtered Signal in Frequency Domain')
xlabel('Frequency (Hz)')
ylabel('Amplitude')