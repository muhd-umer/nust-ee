%% Pitch response to elevator deflection
display(roots([1, 0.226, 0.0169]))
v_dyn = zpk(-0.435, [-1.23, -0.1130+0.0643i, -0.1130-0.0643i], -0.125);

% Coeffs for tf block in Simulink
display(tf(v_dyn))

%% Simplification
syms s;
syms s K1 K2;
G1 = -K1;
G2 = 2/(s+2);
G3 = (-0.125)*(s+0.435)/((s+1.23)*(s^2+0.226*s+0.0169));
H = -K2*s;
reduced_sys = (G1*G2*G3)/(1+(G1*G2*G3)+(G2*G3*H));

%% Comparison
figure
hold on
plot(reduced, 'LineWidth', 1.15)
plot(original, '--', 'LineWidth', 1)
xlabel('Time (s)')
ylabel('Magnitude')
title('Comparison of Step Response')
legend('Reduced', 'Original')
grid