% Wave Plot
time = WaveData.data(:, 1);
Vout = WaveData.data(:, 2);
Vin = WaveData.data(:, 3);

figure('Name', 'Transient Plot');
% Vout vs t
subplot(2, 1, 1)
plot(time, Vout, 'r')
title('V(Out)')
grid on
xlabel('Time (s)')
ylabel('Voltage (V)')
% Vin vs t
subplot(2, 1, 2)
plot(time, Vin)
title('V(In)')
grid on
xlabel('Time (s)')
ylabel('Voltage (V)')

% Bode Plot
Vn = BodeData.('V(out3)');
f = BodeData.('Freq.');

for k = 1:numel(Vn)
    V(:, k) = sscanf(Vn{k}, '(%fdB,%f)');
end

figure('Name', 'Bode Plot');
% Decibel vs Freq.
subplot(2, 1, 1)
semilogx(f, V(1, :), 'r-o', 'MarkerIndices', 1:10:length(V(1, :)))
grid
xlabel('Frequency (Hz)')
ylabel('Magnitude (dB)')
% Phase vs Freq.
subplot(2, 1, 2)
semilogx(f, V(2, :), '-o', 'MarkerIndices', 1:10:length(V(1, :)))
grid
xlabel('Frequency (Hz)')
ylabel('Phase (°)')
sgtitle('V(out)')
