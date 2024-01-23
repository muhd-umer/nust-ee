%% Task 1
% Define parameters
fc = 20;
fs = 10 * fc;
T = 1 / fs;
t = 0:T:15;
m_t = t ./ (1 + t .^ 2);
c_t = cos(2 * pi * fc * t);

% Define sensitivity list
k_a_50 = 0.5;
k_a_100 = 1.0;
k_a_125 = 1.25;

% Define AM signals
s_t_50 = (1 + k_a_50 * m_t) .* c_t;
s_t_100 = (1 + k_a_100 * m_t) .* c_t;
s_t_125 = (1 + k_a_125 * m_t) .* c_t;

% Plot message signal and AM signals
figure
subplot(2, 1, 1)
plot(t, m_t)
grid
title('Message signal')
xlabel('Time (s)')
ylabel('Amplitude')
subplot(2, 1, 2)
plot(t, s_t_50)
grid
title('AM signal: 50% modulation')
xlabel('Time (s)')
ylabel('Amplitude')

figure
subplot(2, 1, 1)
plot(t, m_t)
grid
title('Message signal')
xlabel('Time (s)')
ylabel('Amplitude')
subplot(2, 1, 2)
plot(t, s_t_100)
grid
title('AM signals: 100% modulation')
xlabel('Time (s)')
ylabel('Amplitude')

figure
subplot(2, 1, 1)
plot(t, m_t)
grid
title('Message signal')
xlabel('Time (s)')
ylabel('Amplitude')
subplot(2, 1, 2)
plot(t, s_t_125)
grid
title('AM signal: 125% modulation')
xlabel('Time (s)')
ylabel('Amplitude')

%% Task 2
Fs = 1e5;
t = -5:1/Fs:5;
m_t = 10*sin(2*pi*3000*t) + 20*cos(2*pi*2000*t);
m_t_prime = 30000*cos(2*pi*3000*t) - 40000*sin(2*pi*2000*t);
max(m_t)
max(m_t_prime)
plot(t, m_t)
axis([-0.0005 0.0005 -30 30])