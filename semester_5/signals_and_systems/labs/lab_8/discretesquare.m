function [] = discreteSquare()
    N = 10; % Period N

    n_definition = 1:1:N;
    x = [0 0 0 0 0 0 0 0 1 1]; % 1 - 10

    subplot(2, 2, 1)
    stem(n_definition, x, 'filled');
    title('Original Function x[n]')
    xlabel('n');
    grid

    ak = zeros(1, 35);
    length(ak);

    for k = -17:1:17
        for n = 1:1:N
            ak(k + 18) = ak(k + 18) + (x(n) ...
                * (exp(-1i * k * (2 * pi * (1 / N)) * n))) / N;
        end
    end

    k_axis = -17:1:17;
    length(k_axis);

    mag_ak = abs(ak);

    tol = 1e-6;

    for k = -17:1:17
        if abs(ak(k + 18)) < tol
            ak(k + 18) = 0;
        end
    end

    phase_ak = angle(ak);

    subplot(2, 2, 2)
    stem(k_axis, mag_ak);
    title('Magnitude Spectrum');
    xlabel('k')
    grid

    subplot(2, 2, 3)
    stem(k_axis, phase_ak);
    title('Phase Spectrum');
    xlabel('k')
    grid

    x_recon = zeros(1, N + 1);

    for n = 1:N
        for k = 1:1:N
            x_recon(n + 1) = x_recon(n + 1) + (ak(k + 18) ...
                .* (exp(1i * k * (2 * pi * (1 / N)) * n)));
        end
    end

    n_axis = 0:1:N;
    subplot(2, 2, 4)
    stem(n_axis, real(x_recon), 'filled')
    title('Reconstructed Signal x[n]')
    xlabel('n')
    grid