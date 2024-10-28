 function Gc = Bode_lag(K,omega_c,attenuation_db)
    z = omega_c/10;
    alpha = 10^(attenuation_db/20);
    p = z/alpha;
    num = K*p*[1 z];
    den = z*[1 p];
    Gc = tf(num,den);
 end