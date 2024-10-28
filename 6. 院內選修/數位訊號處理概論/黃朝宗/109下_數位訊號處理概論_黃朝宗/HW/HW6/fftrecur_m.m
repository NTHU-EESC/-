function X = fftrecur_m(x,W)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    N = length(x);
if N ==1
  X = x;
else
    next_W = zeros(N/2, N/2);
     for i = 1:N/2
         for j = 1:N/2
             next_W(i, j) = W(i, 2*j-1);
         end
     end
     XE = fftrecur_m(x(1:2:N), next_W);  
     XO = fftrecur_m(x(2:2:N), next_W);
     temp = W(2, 1:N/2).'.*XO;
     X = [ XE+temp ; XE-temp ];
end

