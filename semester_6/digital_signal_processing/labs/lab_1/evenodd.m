function [x_e, x_o, n_o] = evenodd(x, n)

    x_flip = fliplr(x);
    n_flip = -1 * fliplr(n);

    x_pad = [zeros(1, length(x) - 1) x];
    x_flip_pad = [x_flip zeros(1, length(x) - 1)];
    n_o = [n_flip(1:end - 1) n];

    x_e = zeros(1, length(n_o));
    x_o = zeros(1, length(n_o));

    for idx = 1:length(n_o)
        x_e(idx) = 1/2 * (x_pad(idx) + x_flip_pad(idx));
        x_o(idx) = 1/2 * (x_pad(idx) - x_flip_pad(idx));
    end

end
