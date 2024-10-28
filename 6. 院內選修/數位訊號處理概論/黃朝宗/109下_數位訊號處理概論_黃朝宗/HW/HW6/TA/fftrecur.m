function Xdft = fftrecur(x)
% Recursive computation of the DFT using divide & conquer
% N should be a power of 2 
N = length(x);
if N ==1
  Xdft = x;
else
     m = N/2;
     XE = fftrecur(x(1:2:N));
     XO = fftrecur(x(2:2:N));
     W = exp(-2*pi*sqrt(-1)/N).^(0:m-1).';
     temp = W.*XO;
     Xdft = [ XE+temp ; XE-temp ];
end
