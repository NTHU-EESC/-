function [y, type] = filterfirlp(h,x)
    N = length(h); M = N - 1; 
    h = reshape(h,1,M+1);
    x_len = length(x); x = [zeros(M,1);x(:)];
    y_len = x_len+N-1; y = zeros(1, y_len);
    if(mod(N,2)) % Type I, III
        h1 = h(1:1:((N-1)/2)); h2 = h(N:-1:((N+3)/2));
        if(h1 == h2) % Type I
            type = 'Type I';
            for n = M+1:1:y_len
                y(n) = h(1:1:M/2)*(x(n:-1:n-((M/2)-1))+x(n-M:1:n-M+((M/2)-1))) + h((M/2)+1)*x(n-(M/2));
            end
        elseif((h1==-h2) & (h((N+1)/2)==0)) % Type III
            type = 'Type III';
            for n = M+1:1:y_len
                y(n) = h(1:1:M/2)*(x(n:-1:n-((M/2)-1))-x(n-M:1:n-M+((M/2)-1)));
            end
        else
            type = 'Not correspond to one of the four types.';
            for n = M+1:1:y_len
                y(n) = h(1:1:M+1)*x(n:-1:n-M);
            end
        end
    else % Type II, IV
        h1 = h(1:1:(N/2)); h2 = h(N:-1:((N+2)/2));
        if(h1 == h2) % Type II
            type = 'Type II';
            for n = M+1:1:y_len
                y(n) = h(1:1:(M+1)/2)*(x(n:-1:n-(((M+1)/2)-1))+x(n-M:1:n-M+(((M+1)/2)-1)));
            end
        elseif(h1 == -h2) % Type IV
            type = 'Type IV';
            for n = M+1:1:y_len
                y(n) = h(1:1:(M+1)/2)*(x(n:-1:n-(((M+1)/2)-1))-x(n-M:1:n-M+(((M+1)/2)-1)));
            end
        else
            type = 'Not correspond to one of the four types.';
            for n = M+1:1:y_len
                y(n) = h(1:1:M+1)*x(n:-1:n-M);
            end
        end
    end
    y = y(M+1:y_len);
end

