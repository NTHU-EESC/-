clc;clear;close all;

a = [1 5]; b = [1 2 20 3];
G = tf(a, b);

% Lag + rlocus
zeta = 0.55; 
PO = 100*exp(-zeta*pi/(1-zeta^2)^0.5)
figure(1); rlocus(G); sgrid(zeta,10^4);

K = 5;
my_alpha = 30*(3/5)*(1/K);  %  determined by the requirement on error constant
% K*(z/p)*(5/3) = 30, my_alpha = z/p
z = 1.1;
p = z/my_alpha;
Gc = tf([1 z],[1 p]);
L = G*Gc;
figure(2); rlocus(L); sgrid(zeta,10^4);

[~,Pm]=margin(K*L);
disp(['phase margin = ' num2str(Pm)]);

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P=grade2(Gc)  %%% DO NOT change or modify this line