function exercise_2()
    x = 0:0.0001:2;
    y = cos(x);
    hold
    plot(x, y, '-r');
    y = x;
    plot(x, y,'-b');
    grid
    title('Exercise 2')
    xlabel('x')
    ylabel('y = cos(x)')
    legend('cos(x)', 'x');
end