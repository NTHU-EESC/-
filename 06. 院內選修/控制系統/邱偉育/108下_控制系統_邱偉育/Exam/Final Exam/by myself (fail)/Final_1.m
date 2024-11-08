clc;clear;close all;
% 1(a)
a1 = [3.6];
b1 = conv(1, [1 0.9]); b1 = conv(b1, [1 0.04]);
G = tf(a1, b1);
figure(1); margin(G);
figure(2); rlocus(G);

G1 = (G*18)/3.6
figure(3); margin(G);

wc = 0.05; M = 1;
ac = 10^(M/20);
zc = wc/10; pc =zc/ac;
Kc = 18/(3.6*(pc/zc));
Gc = tf((Kc*(pc/zc)*[1 zc]), [1 pc]);

L = Gc*G;
figure(4); margin(L);


% 1(b)
z1 = 10; p1 = 40;
Gc1 = tf([1 z1],[1 p1]);
z2 = 20; p2 = 50;
Gc2 = tf([1 z2],[1 p2]);

L1 = Gc1*Gc2*G;
figure(5); margin(L1);

%%%%% All codes, including your design steps, should be provided above this line
%%%%% DO NOT just provide the transfer functions for the controllers
% P=grade1(Gc,Gc1,Gc2) %%% DO NOT change or modify this line

