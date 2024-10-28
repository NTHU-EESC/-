function [y] = filterfirdf(b,x)
% Implementation of FIR Direct Form structure (Normal Form)
% [y] = filterfirdf(b,a,x)
K = length(b)-1; b = reshape(b,1,K+1);
Lx = length(x); x = [zeros(K,1);x(:)];
Ly = Lx+K; y = zeros(1,Ly);
for n = K+1:Ly
    y(n) = b*x(n:-1:n-K);
end
y = y(K+1:Ly);