function y = timeshift(data, shift)
    x = data(1, :);
    n = data(2, :);
    % Different slicing for negative
    % / positive shifts
    if shift < 0
        y = x((abs(shift) + 1):length(x));
        y = [y, zeros(1, abs(shift))];
    else
        for k = 1:length(n)
            y(k + shift) = x(k);
        end
        y = y(1:(length(y) - shift));
    end
    subplot(211)
    stem(n, x)
    grid
    xlabel('n')
    ylabel('x[n]')
    title('Original Signal')
    subplot(212)
    stem(n, y, 'r')
    xlabel('n')
    ylabel(['x[n - ' num2str(shift) ']'])
    title(['Time shift of ' num2str(shift)])
    grid
end