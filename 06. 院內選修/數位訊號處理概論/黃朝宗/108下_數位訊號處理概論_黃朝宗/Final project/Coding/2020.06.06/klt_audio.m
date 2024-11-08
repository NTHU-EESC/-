function [Xhat_opt] = klt_audio(X)  
    [N,p] = size(X);
    G = cov(X,1);
    [U,L,A] = svd(G);
    lambda=diag(L);
    Mx = repmat(mean(X),N,1);
    C = (X-Mx)*A;
    min = 10000;
    for m=12:1:12
        Xhat = C(:,1:m)*A(:,1:m)'+Mx;
        E = X(:) - Xhat(:);
        MSE1 = sum(E.^2)/N; % mean square error
        %MSE2 = sum(lambda(m+1:p));  % mean square error
        %MSE = (MSE1+MSE2)/2;
        if (MSE1 < min)
            min = MSE1;
            Xhat_opt = Xhat;
        end
    end
end

