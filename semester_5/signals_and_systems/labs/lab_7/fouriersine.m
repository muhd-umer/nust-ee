function [] = fourierSine(A, T, e)
    bias = 1 + e;
    n = -e:e;
    steps = T / 50;
    t = 0:steps:T;
    w = 2 * pi / T;
    x = A * sin(w * t);

    subplot(221)
    plot(t, x);
    grid on
    title('Original Plot')

    a = (0);

    for k = -e:e
        a(k + bias) = integral(@(t) (A * sin(w * t) .* exp(-1i * k * w * t)) / T, 0, T);
    end

    mag = abs(a);
    phase = angle(a);

    subplot(222)
    stem(n, mag, 'filled');
    grid on
    title('Magnitude Spectra')
    subplot(223)
    stem(n, phase, 'filled');
    grid on
    title('Phase Spectra')

    y = (0);

    for k = -e:e
        y = y + a(k + bias) .* exp(1i * k * w * t);
    end

    subplot(224)
    plot(t, real(y));
    grid on
    title('Reconstructed Signal')
end