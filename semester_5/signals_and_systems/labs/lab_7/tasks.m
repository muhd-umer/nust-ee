T = 10; A = 3;
steps = T / 50;
t = 0:steps:T;
x = A * cos(2 * pi * (1 / T) * t);

subplot(221);
plot(t, x);
grid on
title('CT Cosine Signal');

n = 0:T;
subplot(222);
y = A * cos(2 * pi * (1 / T) * n);
stem(n, y, 'filled');
grid on
title('DT Cosine Signal');

L = length(y);
fourierSeries = (1 / L) .* (fft(y, L));
reconstructedSignal = ifft(fourierSeries, L);

k_x = (-T / 2):(T / 2);
t_x = 0:T;

subplot(223);
stem(k_x, real(fftshift(fourierSeries)), 'filled');
grid on
title('FS Coefficients Using fft');

subplot(224);
stem(t_x, real(L .* reconstructedSignal), 'filled');
grid on
title('Reconstructed Signal using ifft');