% open-loop tf: G(s)=40/(s^2+2s)
% spec:
% (1)steady-state error for ramp input equal to 5% of the ramp velocity
%    Kv = A/ess = A/(0.05A) = 20
% (2)phase margin PM>=45 degree
G=tf(40,[1 2 0]);
figure(1)
margin(G);

K = 1;   % Kv = 20*K = 20
w_m = 6.17;
% w_m: frequcncy of initial PM
phi_m = 38;
% phi_m: difference between (origin Pm) and (final Pm)
% need more than difference
% larger phi_m for larger Pm
Gc = Bode_lead(K,phi_m,w_m);
L=G*Gc;
figure(2)
margin(L);
 
 function Gc = Bode_lead(K,phi_m,w_m)
    phi = phi_m*pi/180;
    alpha = (1+sin(phi))/(1-sin(phi));
    p = w_m*(alpha^0.5);
    z = p/alpha;
    num = K*p*[1 z];
    den = z*[1 p];
    Gc = tf(num,den);
 end
