function [] = discreteSine(A, f, Fs)
    N = Fs / f;

    n_definition = 0:1:N;
    x = A * sin(2 * pi * (f / Fs) * n_definition);

    subplot(2, 2, 1)
    stem(n_definition, x, 'filled')
    title('Original Signal x[n]')
    xlabel('n')
    grid

    n_obv = 0:1:15;
    x_n = A * sin(2 * pi * (f / Fs) * n_obv);
    length(n_obv);

    ak = zeros(1, 41);
    length(ak);

    for k = -20:1:20
        for n = 0:1:15
            ak(k + 21) = ak(k + 21) + (x_n(n + 1) ...
                * (exp(-1i * k * (2 * pi * (1 / N)) * n))) / N;
        end
    end

    k_axis = -20:20;
    length(k_axis);

    mag_ak = abs(ak);

    tol = 1e-6;

    for k = -20:1:20
        if abs(ak(k + 21)) < tol
            ak(k + 21) = 0;
        end
    end

    phase_ak = angle(ak);

%     subplot(2, 2, 2)
%     stem(k_axis, mag_ak);
%     title('Magnitude Spectrum');
%     xlabel('k')
%     grid
% 
%     subplot(2, 2, 3)
%     stem(k_axis, phase_ak);
%     title('Phase Spectrum');
%     xlabel('k')
%     grid

    frequency_radians = zeros(1, 41);

    for k = -20:20
        frequency_radians(k + 21) = 2 * pi * (k / N);
    end

    frequency_Hertz = zeros(1, 41);

    for k = -20:20
        frequency_Hertz(k + 21) = (k / N);
    end

    subplot(2,2,2)
    stem(frequency_radians, mag_ak)
    title('Magnitude of a_{k}')
    xlabel('Frequency (in Radians)')
    grid

    subplot(2,2,3)
    stem(frequency_Hertz, mag_ak)
    title('Magnitude of a_{k}')
    xlabel('Frequency (in Hertz)')
    grid

    x_recon = zeros(1, N + 1);

    for n = 0:N
        for k = -7:1:8
            x_recon(n + 1) = x_recon(n + 1) + (ak(k + 21) ...
                .* (exp(1i * k * (2 * pi * (1 / N)) * n)));
        end
    end

    n_axis = 0:1:N;
    subplot(2, 2, 4)
    stem(n_axis, x_recon, 'filled')
    title('Reconstructed Signal x[n]')
    xlabel('n')
    grid