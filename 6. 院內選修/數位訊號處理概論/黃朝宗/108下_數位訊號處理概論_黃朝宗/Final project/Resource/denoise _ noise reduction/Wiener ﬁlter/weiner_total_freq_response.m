clc 
clear all

fs=2000;
ts=1/fs;
f1=60; 
f21=50; f22=70; 
f31=180; f32=300; f33=420; f34=540; f35=660;
t1=ts:ts:5;
x1=130*sin(2*pi*f1*t1);  %fundamental component
x2=5*sin(2*pi*f21*t1)+5*sin(2*pi*f22*t1); %Flicker disturbance
x3=30*sin(2*pi*f31*t1)+19*sin(2*pi*f32*t1)+11*sin(2*pi*f33*t1)+5*sin(2*pi*f34*t1)+3*sin(2*pi*f35*t1); %Harmonics
x=x1+x2+x3;

%design of Weiner FIR filter ;extracting fundamental signal
%calculate cross correlation vector
u=x';
d=x1;
m=100; %filter order
u1=[u' zeros(1,m)];

p=zeros(m,1);
R=zeros(m,m);
for i=1:m
       p(i,1)=mean(d.*u1(1,(i:(9999+i)))); 
end
%calculate autocorrelation matrix
for i=1:m
    for j=1:m
        R(i,j)=mean(u1(1,(i:(9999+i))).*u1(1,(j:(9999+j)))); 
    end
end

w=R\p; %This corresponding to inv(R)*p
fvtool(w,'impulse')
fvtool(w,1,'fs',fs)
y=filter(w,1,x); %filter output 
e=y-d;

t=0:ts:1; 

Y = fft(y); % compute Fourier transform
n = length(y)/2; % 2nd half are complex conjugates
amp_spec = abs(Y)/n; % absolute value and normalize
freq = (0:4999)/(2*n*ts); 

figure
subplot(3,1,1)
plot(t,x(1:length(t)))
grid on
xlabel('Time(sec)')
ylabel('Amplitude')
title('Fundamental signal plus Flicker and Harmonics')
subplot(3,1,2)
plot(t,y(1:length(t)))
grid on
xlabel('Time(sec)')
ylabel('Amplitude')
title('Filtered signal all disturbances')
subplot(3,1,3)
plot(freq,amp_spec(1:5000)); grid on % plot amplitude spectrum
xlabel('Frequency (Hz)');
ylabel('Amplitude'); % amplitude as function of frequency
title('Frequency spectrum of filtered signal')
