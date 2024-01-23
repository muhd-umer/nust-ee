%% Task 1
% Define the parameters
wp1 = 0.35*pi;
ws1 = 0.2*pi;
wp2 = 0.65*pi;
ws2 = 0.8*pi;
tranband = wp1 - ws1;

% Calculate the filter length
M = ceil((11*pi) / tranband);

% Calculate the cutoff frequencies
wc1 = (ws1+wp1)/2;
wc2 = (ws2+wp2)/2;

% Create the ideal low-pass filters
hd1 = ideal_lp(wc1, M);
hd2 = ideal_lp(wc2, M);

% Create the bandpass filter
hd = hd2 - hd1;

% Apply the Blackman window
wn = blackman(M)';
h = wn .* hd;

% Plot the ideal impulse response
figure
stem(abs(hd))
title("Ideal Impulse Response")

% Plot the actual impulse response
figure
stem(abs(h))
title("Actual Impulse Response")

% Plot the frequency response
figure
[H, w] = freqz(h, 1, 1024);
plot(w/pi, abs(H))
title("Frequency Response")
xlabel("Frequency (rad/s)")
ylabel("Magnitude")

%% Task 2
% Define the parameters
fp = 1000;
fst = 4300;
Fs = 10000;
trans = fst - fp;

% Calculate the transition width
del_w = (2*pi*trans)/Fs;

% Calculate the filter length
M = ceil(6.6*pi/del_w);

% Create the filter
b = fir1(M, 1000/5000);

% Calculate the frequency response
[H, w] = freqz(b, 1, 1024);

% Plot the frequency response
figure
plot(w, abs(H))
xlabel("Frequency (rad/s)")
ylabel("Magnitude")
title("Task 2")

%% Task 3
% Define the parameters
fp1 = 8000;
fs1 = 7000;
fp2 = 16000;
fs2 = 17000;
Fs = 48000;
trans = fp1 - fs1;

fc1 = (fp1 + fs1)/2;
fc2 = (fp2 + fs2)/2;

% Calculate the transition width
del_w = (2*pi*trans)/Fs;

% Calculate the filter length
M = ceil(6.6*pi/del_w);

% Create the filter
b = fir1(M, [fc1/Fs/2, fc2/Fs/2]);

% Calculate the frequency response
[H, w] = freqz(b, 1, 1024);

% Plot the frequency response
figure
plot(w, abs(H))
xlabel("Frequency (rad/s)")
ylabel("Magnitude")
title("Task 3")
axis([0 1 0 (1+0.1)])