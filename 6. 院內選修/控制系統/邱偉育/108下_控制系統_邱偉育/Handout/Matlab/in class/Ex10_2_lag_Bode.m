clc;clear;close all;

%%%% Ex 10.2
% L=40/[s(s+2)]
% specs:   Ess=5% of the velocity of ramp; P.M.= 40
%%%% Bodes + phase lead


%%% Bode 
G=tf(40,[1 2 0]);
figure(1)
margin(G);


%%% lag
K=1;
omega_c=1.91;
attenuation_db=17;
Gc = Bode_lag(K,omega_c,attenuation_db);
L=Gc*G;
figure(2)
margin(L)

figure(3)
nyquist(L)