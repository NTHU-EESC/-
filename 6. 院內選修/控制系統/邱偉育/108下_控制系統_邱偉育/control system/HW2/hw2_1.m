m = 1;  % 1 kg
c = 2; % 12 N-s/m
k = 1; % 20 N/m
% Open-Loop Response
s = tf('s');
P = 1/(m*s^2 + c*s + k) % Transfer function
step(P)
