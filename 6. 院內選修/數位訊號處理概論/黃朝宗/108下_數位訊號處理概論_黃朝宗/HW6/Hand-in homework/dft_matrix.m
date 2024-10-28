function W = dft_matrix(N)
    W = zeros(N, N);
    for a = 1:1:N
        for b = 1:1:N
            W(a,b) = exp(-1*sqrt(-1)*2*pi*(a-1)*(b-1)/N);
        end
    end
end

