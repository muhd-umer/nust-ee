%% 1
x = [1 2 1 2];
h = [0 1 2 3 4 1 1];
y = conv(x, h);
n = 0:1:(length(x) + length(h) - 2);
stem(n, y, 'filled', 'blue');
grid on
ylabel('y[n]')
xlabel('n')

%% 2
x = [1 2 1 2];
h = [0 1 2 3 4 1 1];
y = conv(x, h);
n = -3:1:(length(x) + length(h) - 5);
stem(n, y, 'filled', 'blue');
grid on
ylabel('y[n]')
xlabel('n')

%% 3
x = [-1 0 1];
h = [1 2 1];
y = conv(x, h);
n = -2:1:(length(x) + length(h) - 4);
stem(n, y, 'filled', 'blue');
grid on
ylabel('y[n]')
xlabel('n')