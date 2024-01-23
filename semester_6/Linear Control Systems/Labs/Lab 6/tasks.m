num = 0.0334;
den = [1.566e-5, 1.11556e-3];

speed_tf = tf(num, den);
display(speed_tf)

t = 0:0.01:10;
step_in = 2.15*ones(1, length(t));
step_in(t < 1) = 0;

lsim(speed_tf, step_in, t)
grid
title('Step Response')
xlabel('Time (s)')
ylabel('Magnitude')