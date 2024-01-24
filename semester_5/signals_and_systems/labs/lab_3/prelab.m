[y, Fs] = audioread('test_song.wav');
sound(y, Fs)    % Plays the audio
pause(12);  % Adds a delay of n seconds
yflip = flipud(y);  % Reverses the column vector
sound(yflip, Fs)
pause(12);
sound(yflip, Fs*2)  % Compressed signal
pause(6);
sound(yflip, Fs/2)  % Expanded signal