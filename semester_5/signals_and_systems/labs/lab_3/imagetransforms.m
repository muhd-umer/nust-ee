img = imread('image.jpg');
[height, width, channels] = size(img);
figure
imagesc(img)
title('Original')
figure
imagesc(fliplr(img))
title('Flipped')
