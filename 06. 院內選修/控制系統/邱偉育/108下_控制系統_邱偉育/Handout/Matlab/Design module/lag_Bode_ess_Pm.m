% open-loop tf: G(s)=40/(s^2+2s)
% spec:
% (1)steady-state error for ramp input equal to 5% of the ramp velocity
%    Kv = A/ess = A/(0.05A) = 20
% (2)phase margin PM>=45 degree
G=tf(40,[1 2 0]);
figure(1)
margin(G);

K = 1; % Kv = 20*K = 20
omega_c = 1.61; % match PM
% omega_c: frequency when phase = PM-180+(small number)
attenuation_db = 19.2;
% attenuation_db: magnitude when frequency = omega_c
% fix omega_c then tune attenuation_db
Gc = Bode_lag(K,omega_c,attenuation_db);
L=Gc*G;
figure(2)
margin(L)

 function Gc = Bode_lag(K,omega_c,attenuation_db)
    z = omega_c/10;
    alpha = 10^(attenuation_db/20);
    p = z/alpha;
    num = K*p*[1 z];
    den = z*[1 p];
    Gc = tf(num,den);
 end