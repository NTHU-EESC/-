clc;clear;close;

%%%  specs
%%% Ts<=4, P.O<=35%


G=tf(1,[1 0 0]);

figure(1)
rlocus(G);

zeta=0.35;
PO=100*exp(  -zeta*pi/   (1-zeta^2)^0.5)


z=2;
p=15;
Gc=tf([1 z],[1 p]);
L=Gc*G;

figure(2)
rlocus(L);
sgrid(zeta,10^4);


K=63;

L=K*Gc*G;
T=feedback(L,1);
% figure(3)
% step(T)
% S=stepinfo(T)
 
