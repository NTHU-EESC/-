clc;
close all;
clear all;
t=0.001:0.001:1
d=2*sin(2*pi*50*t);
figure;
plot(d);N=numel(d);
x=d(1:N)+0.5*randn(1,N);
l=d-x;
rr=[];k=1;
r=xcorr(x);M=25;
for i=1:1:M
    rr(i)=r(N-i+1);
end
R=toeplitz(rr);
I=inv(R);
p=xcorr(d,x);
for i=1:1:M
    P(i)=p(N-i+1);
end

W=(inv(R))*P';k=1;
y=zeros(N,1);
for i=M:N
  j=x(i:-1:i-M+1);
  y(i)=(W)'*(j)';
end
e=y'-d;
subplot(4,1,1),plot(d);ylim([-2.5 2.5]);title('desired signal');
subplot(4,1,2),plot(x);title('signal corrupted with noise');
subplot(4,1,3),plot(y);ylim([-2.5 2.5]);title('estimated signal');
subplot(4,1,4),plot(e);ylim([-5 5]);title('error signal');
