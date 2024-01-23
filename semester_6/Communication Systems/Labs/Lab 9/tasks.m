Am = 1;
Ac = 1;
fm = 2;
fc = 20;
t = linspace(0, 1, 500);

%% Task 1
kf = 14;
beta = kf*Am / fm;
s_t = Ac*cos(2*pi*fc*t + beta*sin(2*pi*fm*t));
m_t = Am*cos(2*pi*fm*t);

subplot(211)
plot(t, m_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Message signal');

subplot(212)
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal');

%% Continuation
figure
kf = 16;
beta = kf*Am / fm;
s_t = Ac*cos(2*pi*fc*t + beta*sin(2*pi*fm*t));

subplot(211)
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal kf = 16');

kf = 25;
beta = kf*Am / fm;
s_t = Ac*cos(2*pi*fc*t + beta*sin(2*pi*fm*t));

subplot(212)
plot(t, s_t)
xlabel('Time (s)');
ylabel('Amplitude (V)');
title ('Modulated signal kf = 25');
