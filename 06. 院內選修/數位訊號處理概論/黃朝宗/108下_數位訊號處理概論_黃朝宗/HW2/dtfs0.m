function [c] = dtfs0(x)
    c = zeros(1, length(x));
    N = length(x);
    for k = 1:1:length(c)
        for n = 0:1:N-1
            c(k) = c(k) + ((1/N)*x(n+1)*exp(-1j*2*pi*(k-1)*n/N));
        end
    end
end

