function [G, sos] = firdf2fs(h)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

H = fft(h);
N = length(H);
if(mod(N, 2) == 0)
    K = N/2 - 1;
    G = zeros(1, K+2);
    sos = zeros(K+2, 6);
    %=======================
    G(2) = H(N/2 + 1);
    
else
    K = (N-1)/2;
    G = zeros(1, K+2);
    sos = zeros(K+2, 6);
    %=======================
    G(2) = 0;
end
G(1) = H(1);
sos(1, 1) = 1;
sos(1, 2) = 0;
sos(1, 3) = 0;
sos(1, 4) = 1;
sos(1, 5) = -1;
sos(1, 6) = 0;
sos(2, 1) = 1;
sos(2, 2) = 0;
sos(2, 3) = 0;
sos(2, 4) = 1;
sos(2, 5) = 1;
sos(2, 6) = 0;

for m = 1:K
    sos(m+2, 1) = cos(angle(H(m+1)));
    sos(m+2, 2) = -cos(angle(H(m+1))-2*pi*m/N);
    sos(m+2, 3) = 0;
    sos(m+2, 4) = 1;
    sos(m+2, 5) = -2*cos(2*pi*m/N);
    sos(m+2, 6) = 1;
    G(m+2)=2*abs(H(m+1));
end
G = round(G.', 3);
sos = round(sos, 3);
end

