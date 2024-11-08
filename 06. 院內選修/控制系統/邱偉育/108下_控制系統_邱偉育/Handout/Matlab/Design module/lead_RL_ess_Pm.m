% open-loop tf: G(s)=40/(s^2+2s)
% spec:
% (1)steady-state error for ramp input equal to 5% of the ramp velocity
%    Kv = A/ess = A/(0.05A) = 20
% (2)phase margin PM>=45 degree

G=tf(40,[1 2 0]);
figure(1)
rlocus(G)

zeta = 0.01*45;
% zeta ~ 0.01*PM for second-order system
sgrid(zeta,10^4);
% K: gain s.t zeta <= 0.01*PM

% pull root locus left
z=5; % set
p=16; % set
Gc=tf([1 z],[1 p]);
L=G*Gc;
figure(2)
rlocus(L)
sgrid(zeta,10^4);
K=p/z;
% match ess
% K*(z/p)*20 = 20
[~,Pm]=margin(K*L);
disp(['phase margin = ' num2str(Pm)]);
