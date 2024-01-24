%% Modulation
fs = 1000;
t = -1:1 / fs:1;
L = length(t);
f_axis = fs * (-L / 2:(L / 2) + 1) / L;

A = 1;
fm = 5;
fc = 100;
beta = 15;

wm = 2 * pi * fm;
wc = 2 * pi * fc;
m = A * cos(wm * t); % signal
c = A * cos(wc * t);
mod_t = A * cos((wc * t) + beta * sin(wm * t));

figure
subplot(311)
plot(t, m);
grid
xlabel('Time (s)')
ylabel('Amplitude')
title('Message Signal')

subplot(312)
plot(t, c);
grid
xlabel('Time (s)')
ylabel('Amplitude')
title('Carrier Signal')
axis([-0.2 0.2 -1 1])

subplot(313)
plot(t, mod_t, 'Color', 'red');
grid
xlabel('Time (s)')
ylabel('Amplitude')
title('Modulated Signal')
axis([-0.2 0.2 -1 1])

%% Demodulation
diff_mod = diff(mod_t);
s = abs(diff_mod);

[b, r] = butter(10, (2 * pi * fm) / fs);
out_t = filter(b, r, s);
figure
subplot(211)
plot(t, m)
grid
title('Message Signal')
subplot(212)
plot(t(1:end - 1), out_t)
grid
title('Demodulated Signal')