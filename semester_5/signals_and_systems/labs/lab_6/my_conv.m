function y_n = my_conv(x_n, x_limit, h_n, h_limit)

    len_conv = length(x_n) + length(h_n) - 1;
    n = ((x_limit(1)) + (h_limit(1))):len_conv - length(x_n);
    y_n = zeros(1, len_conv);

    for i = 1:length(x_n)
        for j = 1:length(h_n)
            y_n(i + j - 1) = y_n(i + j - 1) + x_n(i) * h_n(j);
        end
    end

    stem(n, y_n, 'filled', 'red');
    grid on
    ylabel('y[n]')
    xlabel('n')

end