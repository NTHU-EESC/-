function X = dftdirect_m(x,W)
    N = length(x);
    for a = 1:1:N
        sum = 0;
        for b = 1:1:N
            sum = sum + W(a,b)*x(b);
        end
        X(a) = sum;
    end
end
