clc;clear;close all;
%%%% Ex 10.1
% G=10/s^2; H=1
% specs: Ts<=4 s; damping ratio >= 0.45
%%%% root locus + phase lead

G=tf(10,[1 0 0]);
figure(1)
rlocus(G);

% compensation
z=4;
p=25;
Gc=tf([1 z],[1 p]);
L=G*Gc;
figure(2)
rlocus(L)
zeta=0.45;
sgrid(zeta,10^3);

K=62;
L=K*L;
T=feedback(L,1);
stepinfo(T)