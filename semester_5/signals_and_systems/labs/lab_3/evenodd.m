% Signal Definition
n = -3:6;
x = zeros(1, length(n));
x(4) = 2; x(6) = 3; x(7) = -1; x(9) = 2; x(10) = -3;

x_e = 1/2 * (x + fliplr(x)); % Even
x_o = 1/2 * (x - fliplr(x)); % Odd

figure
stem(n, x)
title('Original Function')
grid
figure
stem(n, x_e)
title('Even Component')
grid
figure
stem(n, x_o)
title('Odd Component')
grid