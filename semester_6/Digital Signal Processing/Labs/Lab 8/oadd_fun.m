function y = oadd_fun(x, h, L)
    % where x, h = input arrays
    % L = block length
    % y = output of the convolution using the overlap and add method

    P = length(h);
    N = L + P - 1;
    x1 = [x, zeros(1, L)];
    h1 = [h, zeros(1, L - P)];

    H = fft(h1, N);
    y = zeros(1, length(x1) + P - 1);

    for r = 1:ceil(length(x) / L)
        xr = x1((r - 1) * L + 1:r * L);
        X = fft(xr, N);
        Y = X .* H;
        yr = ifft(Y, N);

        if (r == ceil(length(x) / L) && rem(length(x), L))
            yr = yr(1:N - (L - rem(length(x), L)));
        end

        y = y + [zeros(1, (r - 1) * L), yr, zeros(1, length(y) - L * (r - 1) - length(yr))];
    end

end