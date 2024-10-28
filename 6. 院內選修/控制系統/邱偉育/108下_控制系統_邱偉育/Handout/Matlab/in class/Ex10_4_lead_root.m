clc;clear;close all;


G=tf(1,[1 2 0]);
figure(1); rlocus(G);
damp=0.4;

% % % compensation
z=9;
p=30;
Gc=tf([1 z],[1 p]);
L=Gc*G;
figure(2); rlocus(L);
sgrid(damp,10^4)
K_min=z/p;
Kc=22.5;

T=feedback(Kc*L,1);
figure(3); rlocus(T);
sgrid(damp,10^4);
S=stepinfo(T)