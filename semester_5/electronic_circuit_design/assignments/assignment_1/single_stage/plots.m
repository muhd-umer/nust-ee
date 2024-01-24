% Transient Plot
% Visualizes amplification of the input signal
WaveData = importdata('waveform/waveform.txt');
time = WaveData.data(:, 1);
Vin = WaveData.data(:, 2);
Vout = WaveData.data(:, 3);

figure('Name', 'Transient Plot');
% Vout vs t
subplot(2, 1, 1)
plot(time, Vout, 'r')
title('V(Out)')
grid
xlabel('Time (s)')
ylabel('Voltage (V)')
xticks(0:0.1:1.5)

% Vin vs t
subplot(2, 1, 2)
plot(time, Vin)
title('V(In)')
grid
xlabel('Time (s)')
ylabel('Voltage (V)')
xticks(0:0.1:1.5);

%%
% Bode Plot
% Visualizes the bandwidth of the amplifier
BodeData = readtable('bode_plot/bode.txt', 'VariableNamingRule', 'preserve');
Vn = BodeData.('V(out)');
f = BodeData.('Freq.');

for k = 1:numel(Vn)
    V(:, k) = sscanf(Vn{k}, '(%fdB,%f)');
end

figure('Name', 'Bode Plot');
% Decibel vs Freq.
subplot(2, 1, 1)
semilogx(f, V(1, :), 'r-o', 'MarkerIndices', 1:50:length(V(1, :)))
grid
xlabel('Frequency (Hz)')
ylabel('Magnitude (dB)')

% Phase vs Freq.
subplot(2, 1, 2)
semilogx(f, V(2, :), '-o', 'MarkerIndices', 1:50:length(V(1, :)))
grid
xlabel('Frequency (Hz)')
ylabel('Phase (°)')
sgtitle('V(out)')
