tt = -1:0.01:1;
xx = cos(5 * pi * tt);
zz = 1.4 * exp(1i * pi / 2) * exp(1i * 5 * pi * tt);
plot(tt, xx, 'b - ', tt, real(zz), 'r -- '), grid on
%<--- plot a sinusoid
title('TEST PLOT of a SINUSOID')
xlabel('TIME (sec)')