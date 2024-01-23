%% Task 1.a
zeros = roots([1 0 -1]);
display(zeros)
poles = roots([1 0.8 0.64]);
display(poles)

%% Tassk 1.b
zeros = roots([64 80 100]);
display(zeros)
poles = roots([1 0.8 0.64]);
display(poles)

%% Task 2.a
pp = 0.9 * exp(1i * pi / 3);
poles = [pp; conj(pp)];
display(poles)
zeros = [1; -1];
display(zeros)

%% Task 2.b
b = [1 0 -1];
a = [1 -0.9 0.80996];
[h, w] = freqz(b, a, 8096);

figure
plot(w, abs(h), 'LineWidth', 1.15)
xlabel('Frequency (rad/sample)')
ylabel('Magnitude')
title('Task 2.b')
grid

db3_level = max(abs(h) * 0.707);
display(db3_level)

%% Task 2.c
pp = 0.975 * exp(1i * pi / 3);
poles = [pp; conj(pp)];
display(poles)

b = [1 0 -1];
a = [1 -0.9748 0.95006];
[h, w] = freqz(b, a, 8096);

figure
plot(w, abs(h), 'LineWidth', 1.15)
xlabel('Frequency (rad/sample)')
ylabel('Magnitude')
title('Task 2.c')
grid

db3_level = max(abs(h) * 0.707);
display(db3_level)

%% Task 2.d
pp = 0.975 * exp(1i * pi / 4);
poles_a = [pp; conj(pp)];
display(poles_a)

pp = 0.975 * exp(1i * pi / 2);
poles_b = [pp; conj(pp)];
display(poles_b)

%% Task 3.a.p1
b = [1 0 -1];
a = [1 -0.9 0.80996];
[h, w] = freqz(b, a, 8096);

figure
plot(w, abs(h), 'LineWidth', 1.15)
xlabel('Frequency (rad/sample)')
ylabel('Magnitude')
title('Task 3.a.p1')
grid

db3_level = max(abs(h) * 0.1);
display(db3_level)

%% Task 3.a.p2
b = [1 0 -1];
a = [1 -0.95 0.90246];
[h, w] = freqz(b, a, 8096);

figure
plot(w, abs(h), 'LineWidth', 1.15)
xlabel('Frequency (rad/sample)')
ylabel('Magnitude')
title('Task 3.a.p2')
grid

db3_level = max(abs(h) * 0.1);
display(db3_level)

%% Task 3.a.p3
b = [1 0 -1];
a = [1 -0.9748 0.95006];
[h, w] = freqz(b, a, 8096);

figure
plot(w, abs(h), 'LineWidth', 1.15)
xlabel('Frequency (rad/sample)')
ylabel('Magnitude')
title('Task 3.a.p3')
grid

db3_level = max(abs(h) * 0.1);
display(db3_level)
