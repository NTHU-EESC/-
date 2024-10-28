function x=fftditr2(x)
% DIT Radix-2 FFT Algorithm
N=length(x); nu=log2(N);
x = bitrevorder(x);
for m=1:nu
    L=2^m;
    L2=L/2;
    for ir=1:L2
        W=exp(-1i*2*pi*(ir-1)/L);
        for it=ir:L:N
            ib=it+L2;
            temp=x(ib)*W;
            temp_t=x(it);
            x(it)=temp_t+temp;
            x(ib)=temp_t-temp;
        end
    end
end