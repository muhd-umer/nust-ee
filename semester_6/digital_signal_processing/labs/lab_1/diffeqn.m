function y = diffeqn(a, x, y_n1)

    y = zeros(1, length(x));
    y(1) = a * y_n1 + x(1);

    for n = 2:length(x)
        y(n) = a * y(n - 1) + x(n);
    end

end
