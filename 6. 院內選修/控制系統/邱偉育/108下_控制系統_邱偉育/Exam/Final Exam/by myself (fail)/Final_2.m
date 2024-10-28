clc;clear;close all;

a = [1 5]; b = [1 2 3 20 3];

G = tf(a, b);

zeta = 0.55; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5)
% figure(1); rlocus(G); sgrid(zeta,10^4);
% figure(2); margin(G); grid on;

% Compensation
z = 15; p = 20;
Gc = tf([1 z], [1 p]);
L = G*Gc;
figure(3); rlocus(L); sgrid(zeta, 10^3);

K = 30*(z/p)*(3/5);
L = K*L;
figure(4); margin(L);

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P=grade2(Gc)  %%% DO NOT change or modify this line