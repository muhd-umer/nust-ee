function y = cconv_bee(x, h, N)
    % where x, h = input arrays
    % N = the number of DFT points
    % y = N point output of circular convolution

    % zero pad x and h to length N
    x = [x zeros(1, N - length(x))];
    h = [h zeros(1, N - length(h))];

    y = zeros(1, N);
    for m = 0:(N-1)
        h_fs = cshift_bee(cflip_bee(h, N), m, N);
        for n = 0:(N-1)
            y(m + 1) = y(m + 1) + x(n + 1) * h_fs(n + 1);
        end
    end
end
