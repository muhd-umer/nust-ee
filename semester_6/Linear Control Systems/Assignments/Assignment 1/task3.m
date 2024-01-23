syms J1eq J2eq Kprime Dprime Deq theta1 theta2 theta3 T1;
% Dprime = D`, Kprime = K`, theta = θ

eqn1 = theta1*(J1eq*s ^ 2 + Kprime) - theta2*(Kprime) - theta3*(0) == T1;
eqn2 = - theta1*(Kprime) + theta2*(Dprime*s + Kprime) ...
    - theta3*(Dprime*s) == 0;
eqn3 = - theta1*(0) - theta2*(Dprime*s) + theta3*(J2eq*s ^ 2 ...
    + (Dprime + Deq)*s) == 0;

eqns = [eqn1; eqn2; eqn3];
vars = [theta1; theta2; theta3];

[A, Y] = equationsToMatrix(eqns, vars);
X = linsolve(A, Y);

G2 = X(1) / T1; % X(1) to solve for θ1
display(G2)
