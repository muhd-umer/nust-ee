function [db, mag, pha, grd, w] = freqz_m(b, a)
    % Modified version of freqz subroutine
    % ------------------------------------
    % [db,mag,pha,grd,w] = freqz_m(b,a)
    % db = relative magnitude in dB computed over 0 to pi radians
    % mag = absolute magnitude computed over 0 to pi radians
    % pha = Phase response in radians over 0 to pi radians
    % grd = Group delay over 0 to pi radians
    %     w = 501 frequency samples between 0 to pi radians
    %     b = numerator polynomial of H(z)    (for FIR: b=h)
    %     a = denominator polynomial of H(z)    (for FIR: a=[1])
    
    [H, w] = freqz(b, a, 1000, 'whole');
    H = (H(1:1:501))';
    w = (w(1:1:501))';
    mag = abs(H);
    db = 20 * log10((mag + eps) / max(mag));
    pha = angle(H);
    grd = grpdelay(b, a, w);
end