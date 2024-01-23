%% Task 1.a
load lighthouse
imshow(ww)
whos ww
title('Task 1.a')

%% Task 1.b
ww200 = ww(200, :);
figure
plot(ww200, 'LineWidth', 1.15)
grid on
title('Task 1.b')

%% Task 2
load lighthouse
p = 2;
wp = ww(1:p:end, 1:p:end);
figure
subplot(121)
imshow(ww)
title('Original Image')
subplot(122)
imshow(wp)
title('Downsampled Image')

%% Task 3;
load lighthouse
p = 3;
ww3 = ww(1:p:end, 1:p:end);

%% Task 3.a
xr1 = (-2) .^ (0:6);
L = length(xr1);
nn = ceil((0.999:1:4 * L) / 4);
xr1hold = xr1(nn);
    
figure
plot(xr1, 'LineWidth', 1.15)
hold on
plot(xr1hold, 'LineWidth', 1.15)
hold off
grid on
title('Task 3.a')
legend('xr1', 'xr1hold')

%% Task 3.b
[r, c] = size(ww3);
rr = ceil((0.999:1:3 * r) / 3);
wholdrows = ww3(rr, :);
figure
imshow(wholdrows)
title('Task 3.b')

%% Task 3.c
cc = ceil((0.999:1:3 * c) / 3);
whold = wholdrows(:, cc);
figure
imshow(whold)
title('Task 3.c')

%% Task 3.d
n1 = 0:6;
xr1 = (-2) .^ n1;
tti = 0:1/10:6;
xr1linear = interp1(n1, xr1, tti(1:end-1));
figure
stem(xr1)
hold on
stem(xr1linear)
grid on
title('Task 3.d')
legend('xr1', 'xr1linear')

%% Task 3.e
[r, c] = size(ww3);

nr = 1:r;
nc = 1:c;
rq = 1:1/3:r;
rc = 1:1/3:c;

wrowlinear = interp1(single(ww3(nr, :)), rq);
wwlinear = interp1(single(wrowlinear(:, nc)'), rc);
wwlinear = uint8(wwlinear');

figure
imshow(wwlinear)
title('Task 3.e')