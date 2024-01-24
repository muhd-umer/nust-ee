%% Task 1
Fs = 20000;
n = -1:1 / Fs:1;
L = length(n);
freq_axis = Fs * ((-L / 2:L / 2 - 1) / L);
m_sig = cos(2 * pi * n) + 0.5 * cos(4 * pi * n) + 0.5 * cos(8 * pi * n);
figure
subplot(211)
plot(n, m_sig);
grid
xlabel('Time (s)')
title('Message Signal - Time Domain')
subplot(212)
plot(freq_axis, abs(fftshift(fft(m_sig))));
axis([-30 30 0 25000]);
grid
xlabel('Frequency (Hz)')
title('Message Signal - Frequency Domain')

%% Task 2
c_sig = cos(2000 * pi * n);
figure
subplot(211)
plot(n, c_sig);
axis([-0.005 0.005 -1 1]);
grid
xlabel('Time (s)')
title('Carrier Signal - Time Domain')
subplot(212)
plot(freq_axis, abs(fftshift(fft(c_sig))));
axis([-2000 2000 0 25000]);
grid
xlabel('Frequency (Hz)')
title('Carrier Signal - Frequency Domain')

%% Task 3
mod_sig = m_sig .* c_sig;
figure
subplot(211)
plot(n, mod_sig);
grid
xlabel('Time (s)')
title('Modulated Signal - Time Domain')
subplot(212)
plot(freq_axis, abs(fftshift(fft(mod_sig))));
axis([-2000 2000 0 12500]);
grid
xlabel('Frequency (Hz)')
title('Modulated Signal - Frequency Domain')

%% Task 4
out_sig = mod_sig .* c_sig;
figure
subplot(211)
plot(n, out_sig);
grid
xlabel('Time (s)')
title('Output Signal - Time Domain')
subplot(212)
plot(freq_axis, abs(fftshift(fft(out_sig))));
grid
xlabel('Frequency (Hz)')
title('Output Signal - Frequency Domain')

%% Task 5
lpFilt = designfilt('lowpassiir', 'FilterOrder', 5, ...
'PassbandFrequency', 500, 'PassbandRipple', 0.09, ...
    'SampleRate', Fs);
filtered_sig = filter(lpFilt, out_sig);
figure
subplot(211)
plot(n, filtered_sig);
grid
xlabel('Time (s)')
title('Low Pass Filtered Output Signal - Time Domain')
subplot(212)
plot(freq_axis, abs(fftshift(fft(filtered_sig))));
grid
xlabel('Frequency (Hz)')
title('Low Pass Filtered Output Signal - Frequency Domain')