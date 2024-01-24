function exercise_3()
    x = 0:0.1:10;
    z = (((10 - x).^(1/3)) - 1) ./ (4 - (x.^2)).^(1/2);
    hold
    plot(x, z, '-r');
    grid
    title('Exercise 3.4')
    xlabel('x')
    ylabel('z = ((10-x)^{1/3}-1)/(4 - x^{2})^{1/2}')
    legend('((10-x)^{1/3}-1)/(4 - x^{2})^{1/2}');
end
