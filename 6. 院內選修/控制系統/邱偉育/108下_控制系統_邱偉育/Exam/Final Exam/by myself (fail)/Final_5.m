clc;clear;close all;

a = [1]; b = conv([1 0.1], [1 4]);
G = tf(a, b);

zeta = 0.45; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5);
figure(1); rlocus(G); sgrid(zeta,10^4);

K = 19; z = 0.8; p = 20;
Gc = K*tf([1 z], [1 p]); 

L1 = Gc*G;
T1 = feedback(L1,1);
S1 = stepinfo(T1)

zeta = 0.7; 
PO1 = 100*exp(-zeta*pi/(1-zeta^2)^0.5)
figure(2); rlocus(L1); sgrid(zeta,10^4);

K = 10; z = 0.8; p = 20;
Gp = K*tf([1 z], [1 p]); 

L = L1*Gp;
T = feedback(L,1);
S = stepinfo(T)

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P = grade5(Gc,Gp)   %%% DO NOT change or modify this line


