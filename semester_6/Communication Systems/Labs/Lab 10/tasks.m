%% Task 1
% Define the parameters
Am = 1; % Amplitude of the message signal
Ac = 1; % Amplitude of the carrier signal
fm = 2; % Frequency of the message signal
fc = 10; % Frequency of the carrier signal
fs = 1000; % Sampling frequency
t = 0:1 / fs:1; % Time vector

kp = 2;
m_t = Am * cos(2 * pi * fm * t);
s_t = Ac * cos(2 * pi * fc * t + kp * m_t);
subplot(311)
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal kp = 2');

kp = pi;
m_t = Am * cos(2 * pi * fm * t);
s_t = Ac * cos(2 * pi * fc * t + kp * m_t);
subplot(312)
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal kp = pi');

kp = pi / 2;
m_t = Am * cos(2 * pi * fm * t);
s_t = Ac * cos(2 * pi * fc * t + kp * m_t);
subplot(313)
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal kp = pi/2');

%% Task 2
% Define the parameters
Am = 1; % Amplitude of the message signal
Ac = 1; % Amplitude of the carrier signal
fm = 2; % Frequency of the message signal
fc = 10; % Frequency of the carrier signal
fs = 1000; % Sampling frequency
t = 0:1 / fs:1; % Time vector

kp = 2;
m_t = Am * square(2 * pi * fm * t);
s_t = Ac * cos(2 * pi * fc * t + kp * m_t);
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal kp = 2');

%% Task 3
% Define parameters
t = 0:0.001:1;
fc = 10;
fm = 2;
Kp = pi/2;
fs = 100;

% Generate message signal 
Am = 1;
phase_dev = Kp*Am;
m_t = Am*cos(2*pi*fm*t);

% Perform PM modulation
pm_t = pmmod(m_t, fc, fs, phase_dev);

% Perform PM demodulation
demod_m_t = pmdemod(pm_t, fc, fs, phase_dev);

% Plot original and demodulated signals
figure
subplot(311)
plot(t, m_t, 'b');
xlabel('Time (s)');
ylabel('Amplitude');
title('Original Message Signal')
subplot(312)
plot(t, pm_t, 'b');
xlabel('Time (s)');
ylabel('Amplitude');
title('Modulated Signal')
subplot(313)
plot(t, demod_m_t, 'r');
xlabel('Time (s)');
ylabel('Amplitude');
title('Demodulated Signal');
