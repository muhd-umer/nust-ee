%% Transfer function definitions
z1 = -0.435; p1 = [-1.23 -0.113-1j*0.0642 -0.113+1j*0.0642]; k1 = -0.125;
z2 = -0.435; p2 = [-0.113-1j*0.0642 -0.113+1j*0.0642]; k2 = -0.1016;
z3 = []; p3 = [-0.113-1j*0.0642 -0.113+1j*0.0642]; k3 = -0.0442;

G1 = zpk(z1, p1, k1); % Represents original tf
G2 = zpk(z2, p2, k2); % Represents G1 + 5 times rule reduction
G3 = zpk(z3, p3, k3); % Represents G1 + pole-zero cancellation reduction

%% Time domain representation
syms s;
G1_s = (-0.125*(s+0.435))/((s+1.23)*(s^2 + 0.226*s + 0.0169));
g1_t = ilaplace((1/s)*G1_s)
display(g1_t)

%% Response of the system (with pole-zero reduction)
figure
step(G2)
grid
title('With pole-zero reduction')

%% Response of the system (with 5 times rule reduction)
figure
step(G3)
grid
title('With 5 times rule reduction')

%% Response of the system (complete system, without reduction)
figure
step(G1)
grid
title('Without reduction')

%% Comparison
figure
hold on
step(G1); step(G2); step(G3);
legend('Without reduction', 'With 5 times rule reduction', ...
    'With pole-zero reduction')
grid on
title('Response Comparison')

%% Verification
G1_step = stepinfo(G1) %#ok<*NOPTS>
G2_step = stepinfo(G2)
G3_step = stepinfo(G3)

damp(G1)
damp(G2)
damp(G3)

%% Rise Time
syms wn_t zeta;
zeta_fit = linspace(0.1, 0.9, 5000);
c_t = 1 - (1/sqrt(1-zeta^2))*exp(-zeta*wn_t)*cos(wn_t*sqrt(1-zeta^2)- ...
    atan(zeta/sqrt(1-zeta^2)));
c_fit = subs(c_t, zeta, zeta_fit);

norm_time = zeros(1, 5000);
for i = 1:5000
    t1 = vpasolve(c_fit(i) == 0.9, wn_t, [0 5]);
    t2 = vpasolve(c_fit(i) == 0.1, wn_t, [0 5]);
    norm_time(i) = t1 - t2;
end

plot(zeta_fit, norm_time)
grid
title('Normalized time vs. Damping ratio')
xlabel('Damping ratio \zeta')
ylabel('Normalized time \omega_{n}t')

% polyfit returns coefficients of nth order polynomial
P = polyfit(zeta_fit, norm_time, 4);
poly2sym(P, zeta)