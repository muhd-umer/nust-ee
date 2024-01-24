function [x, t] = one_cos(A, w, phi, dur)
    t = linspace(0, dur, 20);
    x = A * cos(w * t + phi);
    plot(t, x)
    grid
end
