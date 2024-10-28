clc;clear;close all;

%%%% Ex 10.2
% L=40/[s(s+2)]
% specs:   Ess=5% of the velocity of ramp; P.M.= 40
%%%% Bodes + phase lead
% Gc=K*alpha*(s+z)/(s+p)




%%% Bode 
G=tf(40,[1 2 0]);
figure(1)
rlocus(G)
zeta=40*0.01;
sgrid(zeta,10^4);


K=0.168;  % determined by the requirement on P.M.
my_alpha=K;  %  determined by the requirement on error constant

z=0.1;

p= z/my_alpha;

Gc=tf([1 z],[1 p]);
L=G*Gc;
figure(2)
rlocus(L)
sgrid(zeta,10^4);

[~,Pm]=margin(K*L);
Pm
