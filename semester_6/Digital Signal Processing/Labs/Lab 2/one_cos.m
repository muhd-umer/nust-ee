function one_cos(A, w, phi, dur)
    t = linspace(0, dur, 20);
    x_t = A * cos(w * t + phi);
    plot(t, x_t)
    xlabel('t')
    ylabel('cos(wt+phi)')
    title('Task 1')
    grid on
end
