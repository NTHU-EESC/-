clc;clear;close all;


G=tf(40,[1 2 0]);
damp=0.4;
rlocus(G)
sgrid(damp,10^4)

% % % compensation
Kc=0.15;
alpha=1/Kc;

z=0.1;
p=z/alpha;
Gc=Kc*tf([1 z],[1 p]);
 L=Gc*G;
 figure(2)
 rlocus(L/Kc)
 sgrid(damp,10^4)
% T=feedback(Kc*L,1);
% S=stepinfo(T)