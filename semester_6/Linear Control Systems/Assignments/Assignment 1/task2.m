syms X1 X2 X3 s T;

eqn1 = X1*(1*s^2 + 1*s) - X2*(1*s) == T;
eqn2 = -X1*(1*s) + X2*(2 + 1*s) == 0;

eqns = [eqn1; eqn2];
vars = [X1; X2];

[A, Y] = equationsToMatrix(eqns, vars);
X = linsolve(A, Y);

G1 = 2*X(2) / T; % X(3) to solve for X3
[N, D] = numden(G1);
num = sym2poly(N); den = sym2poly(D);

G1_tf = tf(num, den);
display(G1_tf)