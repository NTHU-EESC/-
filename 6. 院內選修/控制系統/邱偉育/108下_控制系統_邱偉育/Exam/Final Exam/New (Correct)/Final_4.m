clc;clear;close all;

a = [1]; b = conv([1 -3], [1, -2]);
G = tf(a, b);
figure(1); bode(G);
figure(2); rlocus(G);

z = 6; p = 20; K = 1000;
Gc = K*tf([1 z], [1 p]);

% 4a
L1 = G*Gc; 
figure(3); rlocus(L1);
T1 = feedback(L1,1);
figure(4); step(T1);
S1 = stepinfo(T1)

% 4b
zeta = 0.7; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5);
zp = 60; Kp = 100;
Gp = Kp*tf([1 zp], [zp]);
L = L1*Gp;
figure(5); rlocus(L); sgrid(zeta,10^4);

T = feedback(L,1);
figure(6); step(T);
S = stepinfo(T)

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P = grade4(Gc,Gp)   %%% DO NOT change or modify this line
