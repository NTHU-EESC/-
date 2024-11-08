function X = fftrecur_m(x,W)
    N = length(x);
    if N ==1
         X = x;
    else
         m = N/2;
         XE = fftrecur_m(x(1:2:N-1), W(1:m,1:2:N-1));
         XO = fftrecur_m(x(2:2:N), W(1:m,1:2:N-1));
         temp = W(1:m,2).*XO;
         X = [ XE+temp; XE-temp ];
    end
end
