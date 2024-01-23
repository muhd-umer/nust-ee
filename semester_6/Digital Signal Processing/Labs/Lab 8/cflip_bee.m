function y = cflip_bee(x, N)
    % This function should take an input array x and circularly flip it
    % where x = input array
    % N = the number of points for circular flipping (DFT points)
    % y = output that should be Modulo N circularly flipped version of x

    % Append zeros to the end of x to make it the same length as N
    x = [x zeros(1, N - length(x))];
    y = zeros(1, N);

    % Flip x and store the modulo N circularly flipped version in y
    for i = 0:(N-1)
        idx = mod(-i, N) + 1;
        y(i+1) = x(idx);
    end

end
