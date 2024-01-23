function y = cshift_bee(x, r, N)
    % where x = input array
    % r = amount of shift (in samples), left shift r > 0 and right shift r < 0
    % N = the number of points for circular flipping (DFT points)
    % y = output that should be Modulo N circularly shifted version of x by an amount r

    % Append zeros to the end of x to make it the same length as N
    x = [x zeros(1, N - length(x))];

    % if r < 0, shift right
    if r < 0
        y = [x(N + r + 1:N) x(1:N + r)];

    % if r > 0, shift left
    elseif r > 0
        y = [x(r + 1:N) x(1:r)];

    % if r = 0, no shift
    else
        y = x;
    end

end