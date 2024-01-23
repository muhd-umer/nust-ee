% Muhammad Umer - CMS: 345834
% Muhammad Ahmed Mohsin - CMS: 333060

%% Chebyshev Filter Design
% The given Specifications are
w_p = 0.4 * pi;
w_s = 0.6 * pi;
ripple = 0.01;
Ap = -log10(0.01); % at w=wp (Ripple Magnitude)
Ar = -20 * log10(0.001); % At wr=0.6pi (Rejection magnitude)
epsilion = sqrt((10 ^ (0.1 * Ap) - 1));

% Finding ratio wp/wr;
k = w_p / w_s;

% Finding d
d = epsilion / sqrt((10 ^ (0.1 * Ar) - 1));
% Finding filter order
n = floor(acosh(1 / d) / acosh(1 / k));

% Calculating y
y = (1 / n) * (asinh(1 / epsilion));

% Plotting the filter by using the calculated values
[b, a] = cheby1(n, epsilion, (w_p / pi));
freqz(b, a, 1000);
axis([-inf inf -100 0])
xticks([0 0.2 0.4 0.6 0.8 0.999])
xticklabels({'0', '0.2\pi', '0.4\pi', '0.6\pi', '0.8\pi', '\pi'})
xlabel('Normalized Frequency  (\times\pi rad/sample)');
ylabel('Magnitude (dB)');
title('Magnitude Response of Chebyshev I Filter N = 8 (dB)');

%% Elliptic Filter Design
% The given specifications are
G_p = 0.99/1.01;
G_s = 0.001/1.01;
T = 1;
omega_p = 2 / T * tan(0.4 * pi / 2);
omega_s = 2 / T * tan(0.6 * pi / 2);
epsilon_p = sqrt(1 / G_p ^ 2 - 1);
epsilon_s = sqrt(1 / G_s ^ 2 - 1);

% calculate filter order
k = (omega_p * 1.6336/1.4531) / (omega_s * 1.9578/2.7528);
k1 = epsilon_p / epsilon_s;
[K, K_prime] = ellipk(k);
[K1, K1_prime] = ellipk(k1);

N = ceil((K1_prime / K1) / (K_prime / K));
k = ellipdeg(N, k1);

L = floor(N / 2);
r = mod(N, 2);
i = (1:L)';

% calculate poles and zeros
u = (2 * i - 1) / N;
zeta_i = cde(u, k);
z_a = (omega_p * 1.6336/1.4531) * 1i ./ (k * zeta_i);
v0 = -1i * asne(1i / epsilon_p, k1) / N;
p_a = (omega_p * 1.6336/1.4531) * 1i * cde(u - 1i * v0, k);
p_a0 = (omega_p * 1.6336/1.4531) * 1i * sne(1i * v0, k);
z = cplxpair([exp(z_a); conj(exp(z_a))]);
p = cplxpair([exp(p_a); conj(exp(p_a))]);

% calculate coefficients
b = [ones(L, 1), -2 * real(1 ./ z_a), abs(1 ./ z_a) .^ 2];
a = [ones(L, 1), -2 * real(1 ./ p_a), abs(1 ./ p_a) .^ 2];

% add extra pole/zero if N is odd
if r == 0
    b = [G_p, 0, 0; b];
    a = [1, 0, 0; a];
else
    b = [1, 0, 0; b];
    a = [1, -real(1 / p_a0), 0; a];
end

% frequency response
w = linspace(0, pi, 2048);
H = freq_resp(b, a, w);

% magnitude response dB
figure(1);
subplot(211)
plot(w, 20 * log10(abs(H)));
axis([-inf inf -100 0])
xticks([0 (0.2 * pi) (0.4 * pi) (0.6 * pi) (0.8 * pi) pi])
xticklabels({'0', '0.2\pi', '0.4\pi', '0.6\pi', '0.8\pi', '\pi'})
xlabel('Normalized Frequency  (\times\pi rad/sample)');
ylabel('Magnitude (dB)');
title('Magnitude Response of Elliptic Filter N = 6 (dB)');
