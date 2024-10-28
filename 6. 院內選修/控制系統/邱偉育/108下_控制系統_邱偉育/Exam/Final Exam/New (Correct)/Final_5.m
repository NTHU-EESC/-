clc;clear;close all;

a = [1]; b = conv([1 0.1], [1 4]);
G = tf(a, b);

z = 5; p = 15; K = 200; 
Gc = K*tf([1 z], [1 p]); 

zeta1 = 0.45; 
PO1 = 100*exp(-zeta1*pi/(1-zeta1^2)^0.5)

L1 = Gc*G;
figure(1); rlocus(L1); sgrid(zeta1,10^4); % --> Get K = 200
T1 = feedback(L1,1);
figure(2); step(T1);
S1 = stepinfo(T1)

% add prefilter
zeta = 0.7; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5)

zp = 20; Kp = 16;
Gp = Kp*tf([1 zp], [zp]); 

L = L1*Gp;
figure(3); rlocus(L); sgrid(zeta,10^4); % --> Get Kp = 16
T = feedback(L,1);
figure(4); step(T);
S = stepinfo(T)

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P = grade5(Gc,Gp)   %%% DO NOT change or modify this line


