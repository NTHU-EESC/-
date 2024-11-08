function Xdft=dftdirect(x)
% Direct computation of the DFT
N=length(x); Q=2*pi/N;
for k=1:N
     S=0;
     for n=1:N
         W(k,n)=exp(-j*Q*(k-1)*(n-1));
         S=S+W(k,n)*x(n);
     end
     Xdft(k)=S;
end
     