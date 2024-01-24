function exercise_1()
    t = 0:0.01:4;
    x = 2 * sin(2 * pi * t - (pi / 2));
    plot(t, x, '-b');
    grid
    title('Exercise 1')
    xlabel('t')
    ylabel('x = 2 * sin(2 * pi * t - (pi / 2))')
end