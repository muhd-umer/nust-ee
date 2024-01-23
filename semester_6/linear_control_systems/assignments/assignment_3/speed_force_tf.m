syms M1 M2 X1 X2 k mu g s F;

eqn1 = (M1*s^2 + M1*mu*g*s + k)*X1 - (k)*X2 == F;
eqn2 = -1*(k)*X1 + (M2*s^2 + M2*mu*g*s + k)*X2 == 0;

eqns = [eqn1; eqn2];
vars = [X1; X2];

[A, Y] = equationsToMatrix(eqns, vars);
X = linsolve(A, Y);

G1 = X(1) / F;
pretty(G1)
 