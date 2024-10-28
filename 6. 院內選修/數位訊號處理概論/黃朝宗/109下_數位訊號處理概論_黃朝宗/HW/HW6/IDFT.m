function x = IDFT(X, N)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
X_circular =[X(1), X(N:-1:2)];
x = 1/N*fft(X_circular);
end

