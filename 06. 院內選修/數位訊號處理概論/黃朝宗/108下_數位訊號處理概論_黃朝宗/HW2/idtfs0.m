function [x] = idtfs0(c)
    x = zeros(1, length(c));
    N = length(c);
    for n = 1:1:length(x)
        for k = 0:1:N-1
            x(n) = x(n) + (c(k+1)*exp(1j*2*pi*k*(n-1)/N));
        end
    end
end

