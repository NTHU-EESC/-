function [Xhat, X_mean, A, m] = klt_audio_train(X, N_type)  
    [N,p] = size(X);
    G = zeros(p,p);
    N_data = N/N_type;
    for i = 1:1:N_type
        G = cov(X((N_data*(i-1)+1):(N_data*i)),1)/N_type + G;
    end
    G = cov(X,1);
    [U, D] = eig(G);
    Xhat = U*(X');
    Xhat = Xhat';
    [U,L,A] = svd(G);
%     lambda=diag(L);
    X_mean = mean(X);
%     Mx = repmat(mean(X),N,1);
%     C = (X-Mx)*A;
%     min = 10000;
    m = 1;
%     Xhat = C(:,1:m)*A(:,1:m)'+Mx;
%     E = X(:) - Xhat(:);
%     MSE1 = sum(E.^2)/N; % mean square error
end


