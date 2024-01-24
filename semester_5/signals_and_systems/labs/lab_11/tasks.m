clear all;
close all;
clc;

%% Task 1
freq = 1; % frequency
samples_in_one_cycle = 100;
division_increment = 1 / samples_in_one_cycle;

t = 0:division_increment:(1 / freq) * 5; % 5 periods
x = cos(2 * pi * freq * t);
subplot(211)
plot(t, x);
grid
title('Original Signal')
xlabel('Time (s)')
ylabel('x(t) = cos(2*pi*freq*t);')

%% Task 2
upper_limit = length(x);
sampling_freq = 4 * freq; % sampling frequency

t_p = 0:1 / sampling_freq:1 / freq * 5;
x_p = cos(2 * pi * freq * t_p); % sampled signal
subplot(212)
plot(t, x, ':b', 'MarkerSize', 2); hold on;
stem(t_p, x_p)
grid
title('Sampled Signal')
xlabel('Time (s)')
ylabel('x_p(t) = x(t) * impulse train')

%% Task 3
t_sinc = -2.5:division_increment:2.5;
z = sinc(4 * t_sinc);

figure
subplot(211)
plot(t_sinc, z);
grid
title('Sinc Signal')
xlabel('Time (s)')
ylabel('sinc(4*pi*t)')

%% Task 4
padded_x_p = zeros(1, length(x));   % padding sampled signal to length of
i = 1;                              % original signal
k = 1;

for y = 0:division_increment:(1 / freq) * 5
    if (y == t_p(i))
        padded_x_p(k) = x_p(i);
        i = i + 1;
    end
    k = k + 1;
end

x_r = conv(padded_x_p, z, 'same');

subplot(212)
plot(t, x_r);
grid
title('Reconstructed Signal')
xlabel('Time (s)')
ylabel('x_r(t) = cos(2 * pi * freq * t)')