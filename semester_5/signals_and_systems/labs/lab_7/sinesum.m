function [output m p]= sinesum(signal, freq, Fs)
%SINESUM Estimates a signal as a sum of pure sine waves of known frequency
%'signal' - Input signal you wish to estimate
%'freq'   - Vector of known frequencies with significant contributions
%           If no vector is specified, vector is assumed to be a
%           fundamental (primary freq of signal) plus harmonics (number of
%           harmonics specified by the constant 'harmonics'
%'Fs'     - Sampling rate of input signal
%'output' - Estimate of signal using pure sine functions
%'m'      - Vector of frequency component amplitudes
%'p'      - Vector of frequency component phases (reconstructed
%           signal must be reversed in time as of 4/24/2012) 
%
% Created on: April 24, 2012
% Author: Srikanth Iyer 
% Email: sri243@gmail.com
 
%freq=[50 100 150];
% Fs=10000;

% Constants
dft_constant=10; % using a longer FFT will reduce leakage effects
harmonics=2; %Number of harmonics excluding f0 (only used if 'freq' is not specified)

% Create appropriate time vector (for plotting)
time=0:1/Fs:length(signal)/Fs-1/Fs;

%Initialize outputs m and p
m=[];
p=[];
output=zeros(size(signal))';

%Compute FFT
L=length(signal);
NFFT = 2^(nextpow2(L)+dft_constant);
Y = fft(signal,NFFT)/L;
f_fft = Fs/2*linspace(0,1,NFFT/2+1);

%Create 'freq' if not already specified
if(~exist('freq'))
    [f0 maxcomp]=max(2*abs(Y(1:NFFT/2+1)));
    freq=f0:f0:(harmonics+1)*f0;
end

for(index=1:length(freq))
    fc=freq(index);

%Extract magnitude and phase of fft at specified frequencies
freq_index=ceil((NFFT/2+1)*fc/(Fs/2));
dev=1*ones(1,length(freq_index)); %allows for some error in frequency resolution caused by taking the FFT
high=freq_index+dev;
low=freq_index-dev;
if(fc==0) 
Yc=Y(1);
else
Yc=max(Y(low:high));
end
mc=2*abs(Yc);
pc=atan2(real(Yc), imag(Yc));
p=[p pc];
m=[m pc];
output=output+mc*sin(2*pi*fc*-time+pc);
end
%figure; plot(time, signal,time,output)
end

