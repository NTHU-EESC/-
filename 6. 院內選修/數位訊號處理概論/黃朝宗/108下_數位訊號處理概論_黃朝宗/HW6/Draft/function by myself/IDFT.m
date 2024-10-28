function x = IDFT(X,N)
%     x = zeros(1,N);
%     for n = 1:1:N
%         x(n) = X(1:1:N)*exp(-1*sqrt(-1)*2*pi*(n-1)*(0:-1:-N+1)'/N);
%     end
%     x = x./N;
%     X_mk = zeros(1, N);
%     X_mk(1,1) = X(1,1);
%     M = (N/2) + 1;
%     for a = 2:1:N
%         X_mk(1, a) = X(1, N-a+2);
%     end
%     x = fft(X_mk)/N;
    x = fft(circfold(X,N))./N;
end

