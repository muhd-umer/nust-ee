function y = osave_bee(x, h, L)
    % where x, h = input arrays
    % L = block length
    % N = the number of DFT points
    % y = output of the convolution using the overlap and add method

    P = length(h);
    N = L + P - 1;
    x1 = [x, zeros(1, L)];
    y = zeros(1, length(x1) + P - 1);
    xr = zeros(1, L);

    for r = 1:ceil((length(x) + P - 1) / (L - P + 1))
        xr = [xr(L - P + 2:L), x1((r - 1) * ...
            (L - P + 1) + 1:(r - 1) * (L - P + 1) + (L - P + 1))];
        yr = cconv_bee(xr, h, N);

        y((r - 1) * (L - P + 1) + 1:(r - 1) * (L - P + 1) + (L - P + 1)) = yr(P:L);
    end

    y = y(1:length(x) + P - 1);

end
