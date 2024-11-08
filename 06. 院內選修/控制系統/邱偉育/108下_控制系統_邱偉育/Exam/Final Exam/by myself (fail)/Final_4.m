clc;clear;close all;

a = [1]; b = conv([1 -3], [1, -2]);
G = tf(a, b);
% figure(1); bode(G);
% figure(2); rlocus(G);

z = 0.8; p = 20;
Gc = tf([1 z], [1 p]); Gc = 200*Gc;

L1 = G*Gc; 
% figure(3); rlocus(L1);
% figure(4); bode(L1);
T1 = feedback(L1,1);
% figure(5); step(T1);
S1 = stepinfo(T1);

zeta = 0.7; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5);
figure(6); rlocus(L1); sgrid(zeta,10^4);

zp = 2; pp = 3;
Gp = tf([1 zp], [1 pp]);

L = L1*Gp;
T = feedback(L,1);
% figure(5); step(T);
S = stepinfo(T)

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P = grade4(Gc,Gp)   %%% DO NOT change or modify this line
