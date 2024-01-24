function [xx, tt] = syn_sin(fk, Xk, fs, dur, tstart)
    tt = tstart:1 / fs:dur;
    xx = 0;

    if not(eq(length(fk), length(Xk)))
        error('Length of fk and Xk must be equal.');
    end

    for iter = 1:length(fk)
        x_iter = Xk(iter);
        f_iter = fk(iter);
        xx = xx + real(x_iter * exp(2 * pi * 1i * f_iter * tt));
    end

    plot(tt, xx)
    grid
end
