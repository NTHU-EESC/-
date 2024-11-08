function x = fftdifr2(x)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
N=length(x); nu=log2(N);
for m=nu:-1:1
    L=2^m;
    L2=L/2;
    for ir=1:L2
        W=exp(-1i*2*pi*(ir-1)/L);
        for it=ir:L:N
            ib=it+L2;
            temp=x(ib);
            x(ib)=(x(it)-x(ib))*W;
            x(it)=x(it)+temp;
        end
    end
end
x = bitrevorder(x);
end

