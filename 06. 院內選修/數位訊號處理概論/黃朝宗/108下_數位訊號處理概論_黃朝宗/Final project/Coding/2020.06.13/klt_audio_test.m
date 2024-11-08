function [Xhat] = klt_audio_test(X, X_mean, A, m)  
    [N,p] = size(X);
    Mx = repmat(X_mean,N,1);
    C = (X-Mx)*A;
    Xhat = C(:,1:m)*A(:,1:m)'+Mx;
end