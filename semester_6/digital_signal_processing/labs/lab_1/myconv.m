function y_n = myconv(x_n, h_n, x_limit, h_limit)

    if nargin < 3
        x_limit = 0;
        h_limit = 0;
    end

    len_conv = length(x_n) + length(h_n) - 1;
    start_idx = (x_limit(1)) + (h_limit(1));
    n = start_idx:len_conv - start_idx;
    y_n = zeros(1, len_conv);

    for i = 1:length(x_n)
        for j = 1:length(h_n)
            y_n(i + j - 1) = y_n(i + j - 1) + x_n(i) * h_n(j);
            stem(n(1:length(y_n)), y_n, 'filled', 'red');
            pause(0.5)
        end
    end

    stem(n(1:length(y_n)), y_n, 'filled', 'red');
    grid on
    ylabel('y[n]')
    xlabel('n')

end
