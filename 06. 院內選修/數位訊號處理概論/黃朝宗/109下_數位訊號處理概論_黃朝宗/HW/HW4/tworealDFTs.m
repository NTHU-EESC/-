function [X1, X2] = tworealDFTs(x1,x2)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
XK = fft(x1+1j*x2);
X_cong = circfold(XK, length(XK));
X1 = 0.5*(XK + conj(X_cong));
X2 = 0.5*(XK - conj(X_cong))/1j;
end

