clc;clear;close all;

%%%% Ex 10.2
% L=40/[s(s+2)]
% specs:   Ess=5% of the velocity of ramp; P.M.= 40
%%%% Bodes + phase lead
% Gc=K*alpha*(s+z)/(s+p)




%%% Bode 
G=tf(40,[1 2 0]);
figure(1)
margin(G);

 K=1;  % 1st parameter used to achieve error constant
 w_m=6.17;  % 2nd parameter 
  phi_m=10;   % 3rd parameter (in degrees)
 Gc=Bode_lead(K,phi_m,w_m);
 

 L=G*Gc;
 figure(2)
 margin(L);
 
 figure(3)
 nyquist(L)
 

