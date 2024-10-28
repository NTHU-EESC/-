clc;clear;close all;

a = [3.6]; b = conv([1 0.14], [0.1, 1]);
G = tf(a, b);

zeta = 0.6; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5)
figure(1); rlocus(G); sgrid(zeta,10^4);

K = 1.7;  % determined by the requirement on P.M.
my_alpha = K;  %  determined by the requirement on error constant
z = 0.1; p = z/my_alpha;

Gc = tf([1 z],[1 p]); Gc = K*Gc;
L = G*Gc; 

T = feedback(L,1);
figure(2); step(T);

S = stepinfo(T)


%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P = grade3(Gc)  %%% DO NOT change or modify this line