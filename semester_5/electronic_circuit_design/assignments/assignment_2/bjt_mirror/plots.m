hold on
plot(v2, IR2, 'cyan')
plot(v2, IR1, 'red')
plot(v2, IR3, 'magenta')
plot(v2, IR4, 'blue')
title('Load Current I_{L}')
grid
xlabel('V2 (V)')
ylabel('I ({A})')
legend('250 {\Omega}', '500 {\Omega}', '750 {\Omega}', '1000 {\Omega}')
xticks(0:10)