function [y] = filterdf1(b,a,x)
% Implementation of Direct Form I structure (Normal Form)
%  with zero initial conditions
% [y] = filterdf1(b,a,x)
M = length(b)-1; N = length(a)-1; K = max(M,N);
a0 = a(1); a = reshape(a,1,N+1)/a0; 
b = reshape(b,1,M+1)/a0; a = a(2:end);
Lx = length(x); x = [zeros(K,1);x(:)];
Ly = Lx+K; y = zeros(1,Ly);
for n = K+1:Ly
    sn = b*x(n:-1:n-M);
    y(n) = sn - a*y(n-1:-1:n-N)';
end
y = y(K+1:Ly);