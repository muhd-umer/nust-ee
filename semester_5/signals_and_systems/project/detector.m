%% Read audio and find speech intervals
[audioIn, fs] = audioread('enhanced_audio.mp3');
t = linspace(0, length(audioIn) / fs, length(audioIn));

windowDuration = 0.005; % seconds
numWindowSamples = round(windowDuration * fs);
win = hann(numWindowSamples, 'periodic');

percentOverlap = 10;
overlap = round(numWindowSamples * percentOverlap / 100);

mergeDuration = 0.1;
mergeDist = round(mergeDuration * fs);

idxSpeech = detectSpeech(audioIn(:, 1), fs, 'Window', win, 'OverlapLength', ...
    overlap, 'MergeDistance', mergeDist) ./ fs; % Divide by ./ fs for conversion to time

%% Extract features
aFE = audioFeatureExtractor( ...
SampleRate = fs, ...
    Window = hamming(round(0.03 * fs), 'periodic'), ...
    OverlapLength = round(0.02 * fs), ...
    mfcc = true, ...
    mfccDelta = true, ...
    mfccDeltaDelta = true, ...
    pitch = true, ...
    spectralCentroid = true, ...
    zerocrossrate = true, ...
    shortTimeEnergy = true); % Feature extractor

features = extract(aFE, audioIn);

idx = info(aFE);
tFE = linspace(0, length(audioIn) / fs, length(features));

%% Plots
featureSplices = zeros(length(idxSpeech), 4);
detectThresh = 0.05;

for i = 1:length(idxSpeech)
    boundLower = interp1(tFE, 1:length(tFE), idxSpeech(i, 1), 'nearest');
    boundUpper = interp1(tFE, 1:length(tFE), idxSpeech(i, 2), 'nearest');
    feats = features(:, idx.mfccDelta);

    if (tFE(boundUpper) - tFE(boundLower)) <= 0.15 % Skip splices less than 0.2 seconds
        continue
    end

    featureSplices(i, :) = [tFE(boundLower) tFE(boundUpper) ...
                            mean(feats(boundLower:boundUpper)) std(feats(boundLower:boundUpper))];

%     % To plot all individual mfccDelta of splices against time
%     figure
%     plot(tFE(boundLower:boundUpper), feats(boundLower:boundUpper))
%     grid
%     xlabel('Time (s)')
%     ylabel('Frequency (Hz)')
%     title(['Splice ID ', num2str(i)])

end

%% Detect splices
featureSplices = featureSplices(any(featureSplices, 2), :);
figure
plot(t, audioIn, 'Color', '#0072BD')
axis([0 t(end) -0.3 0.3])
title('Detected Splices - Audio Signal')
xlabel('Time (s)')
grid

detectedSplices = zeros(1, length(featureSplices));

for p = 1:length(featureSplices)

    if p == length(featureSplices)
        break
    elseif abs(featureSplices(p + 1, 3) / featureSplices(p + 1, 4) ...
            - featureSplices(p, 3) / featureSplices(p, 4)) > detectThresh
        detectedSplices(p) = featureSplices(p + 1, 1);
    end

end

detectedSplices = round(nonzeros(detectedSplices), 1);

for k = 1:length(detectedSplices)
    line([detectedSplices(k); detectedSplices(k)], [-0.3; 0.3], 'LineWidth', 2.5, ...
        'LineStyle', '--', 'Color', '#A2142F');
end

figure
melSpectrogram(audioIn, fs)
title('Detected Splices - Mel Spectrogram')

for k = 1:length(detectedSplices)
    line([detectedSplices(k); detectedSplices(k)], [0.0779; 19.8], 'LineWidth', 2.5, ...
        'LineStyle', '--', 'Color', '#FFFFFF');
end

colormap cool
disp(['Total number of audios being spliced: ', num2str(length(detectedSplices))]); 
disp(' ');
disp('   Start (s)');
disp(detectedSplices)