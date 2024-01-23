function [x_t, t] = syn_sin(fk, Xk, fs, dur, tstart)
    % syn_sin: Function to synthesize a sum of cosine waves
    % If tstart is not specified, default tstart = 0
    if nargin < 5
        tstart = 0;
    end

    t = linspace(tstart, dur - abs(tstart), fs);

    assert(length(fk) == length(Xk), "Input fk and Xk must " + ...
    "have the same length.")

    x_t = 0;

    for k = 1:length(fk)
        x_t = x_t + real(Xk(k) * exp(2 * pi * 1i * fk(k) * t));
    end

end