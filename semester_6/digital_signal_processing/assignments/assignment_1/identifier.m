%% Approximation
F = linspace(0, 1, 100);
A_prime = zeros(1, length(F));

% Index Finder
idx_1 = find(min(abs(F - 0.27)) == abs(F - 0.27));
idx_2 = find(min(abs(F - 0.41)) == abs(F - 0.41));
idx_3 = find(min(abs(F - 0.51)) == abs(F - 0.51));
idx_4 = find(min(abs(F - 0.55)) == abs(F - 0.55));
idx_5 = find(min(abs(F - 0.6)) == abs(F - 0.6));
idx_6 = find(min(abs(F - 0.66)) == abs(F - 0.66));

% Linear Approximation
A_prime(1:idx_1) = linspace(0, 3, 28);
A_prime(idx_1 + 1:idx_2) = linspace(3, 10, 14);
A_prime(idx_2 + 1:idx_3) = linspace(10, 20, 9);
A_prime(idx_3 + 1:idx_4) = linspace(20, 35, 4);
A_prime(idx_4 + 1:idx_5) = linspace(35, 20, 5);
A_prime(idx_5 + 1:idx_6) = linspace(20, 10, 6);
A_prime(idx_6 + 1:end) = linspace(10, -7, 34);

plot(F, A_prime)
grid
xlabel('Normalized Frequency')
ylabel('Magnitude')

% P = polyfit(F, A_prime, 3);
% A = polyval(P, F);
% plot(F, A)

%% Design Fit
A = db2mag(A_prime);
Nb = 8;
Na = 8;

d = fdesign.arbmag('Nb,Na,F,A', Nb, Na, F, A);
W = [ones(1, 30) ones(1, 10) * .2 ones(1, 60)];
Hd = design(d, 'iirlpnorm', 'Weights', W, 'Norm', 2, 'DensityFactor', 30, ...
    'SystemObject', true);
fvtool(Hd, 'MagnitudeDisplay', 'Magnitude (dB)', ...
    'NormalizedFrequency', 'On');
