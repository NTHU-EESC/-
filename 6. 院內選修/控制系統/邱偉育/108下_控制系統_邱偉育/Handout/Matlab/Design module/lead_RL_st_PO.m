% open-loop tf: G(s)=K/(s^2)
% spec:
% (1)settling time: T<=4
% (2)percent overshoot P.O.<=35%
G=tf(1,[1 0 0]);
% figure(1)
% rlocus(G)

zeta=0.317;
PO=100*exp(-zeta*pi/(1-zeta^2)^0.5);
disp(['percent overshoot = ' num2str(PO)]);

% pull root locus left
z=2; % set
p=15; % set
Gc=tf([1 z],[1 p]);
L=G*Gc;
figure(2)
rlocus(L)
sgrid(zeta,10^4);

K = 37; % choose by root locus
T = feedback(K*L,1);
S=stepinfo(T);
disp(S)
