function [y, n] = sigadd(x1, n1, x2, n2)
    % This function adds the indices of two inputs x1 and x2

    % Pad with zeros at the beginning if input index exceeds
    % the range of x1 / x2
    if n1(length(n1)) > length(x1)
        x1 = [zeros(1, n1(1) - 1), x1];
    end

    if n2(length(n2)) > length(x2)
        x2 = [zeros(1, n2(1) - 1), x2];
    end

    % If-Else conditions to pad and add proper indices
    if length(n2) > length(n1)
        x2_pad = x2(1:n2(length(n2)));
        x1_pad = [x1(1:n1(length(n1))), zeros(1, ...
            length(x2_pad) - length(x1(1:n1(length(n1)))))];
    elseif length(n2) < length(n1)
        x1_pad = x1(1:n1(length(n1)));
        x2_pad = [x2(1:n2(length(n2))), zeros(1, ...
            length(x1_pad) - length(x2(1:n2(length(n2)))))];
    else
        x1_pad = x1;
        x2_pad = x2;
    end

    % Post-proc, add the padded inputs
    y = x1_pad + x2_pad;
    n = length(y);
end