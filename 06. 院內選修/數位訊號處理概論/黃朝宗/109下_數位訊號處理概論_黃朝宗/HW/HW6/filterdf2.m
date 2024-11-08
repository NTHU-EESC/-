function y = filterdf2(b, a, x)
% Implementation of Direct Form II structure (Normal Form)
%  with zero initial conditions
% [y] = filterdf2(b,a,x)
M = length(b)-1; N = length(a)-1; K = max(M,N);
a0 = a(1); a = reshape(a,1,N+1)/a0; 
b = reshape(b,1,M+1)/a0; a = a(2:end);
Lx = length(x); x = [zeros(K, 1);x(:)];
Ly = Lx+K; y = zeros(1, Ly); w = zeros(Ly, 1);
for n = K+1:Ly
    w(n) = x(n) - a*w(n-1:-1:n-N);
    y(n) = (b*w(n:-1:n-M))';   
end
y = y(K+1:Ly);
end
