function W = dft_matrix(N)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
W_N = exp(-1j*2*pi/N);
W = zeros(8, 8);
for m = 1:N
    for n = 1:N
        W(m, n) = W_N^(m-1)^(n-1); 
    end
end
end

