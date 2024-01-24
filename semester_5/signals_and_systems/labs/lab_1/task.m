clear;
clc;
t = -1 : 0.01 : 1; 
x = cos( 5*pi*t ); 
y = 1.4*exp(j*pi/2)*exp(j*5*pi*t); 
plot( t, x, 'b-', t, real(y), 'r--' )
grid on 
%<--- plot a sinusoid 
title('Test Plot of a Sinusoid') 
xlabel('Time (sec)')