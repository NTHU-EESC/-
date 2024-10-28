function [y, t, sys1, sys2, T1, T2_1, T2_2] = HW2_105060012
    % Hw2_1 % output: y, t
    y0 = -1; 
    wn = sqrt(2); 
    zeta = [0.3 0.6 1]; 
    t = [0:0.1:10];
    y = zeros(3,length(t));
    for i=1:1:length(zeta)-1
        c = (y0/sqrt(1-zeta(i)^2)); 
        for j=1:1:length(t)
            y(i, j) = c*exp(-zeta(i)*wn*t(j)).*sin(wn*sqrt(1-zeta(i)^2)*t(j)+acos(zeta(i)));
        end
    end
    for j=1:1:length(t)
        y(length(zeta), j) = c*exp(-zeta(i)*wn*t(j)).*sin(wn*0*t(j)+acos(zeta(i)));
    end
    
    % Hw2_2 % output: sys1, sys2
    numg = [1]; deng = [500 0 0]; sysg = tf(numg,deng);
    numgc = [1 1]; dengc = [1 2]; sysgc = tf(numgc,dengc); 
    sys1 = series(sysg,sysgc);
    sys2_num = series(sysg,sysgc); 
    sys2 = feedback(sys2_num,[1]);
    
    % Hw2_3 % output: T1, T2_1, T2_2
    numg = [1]; deng = [500 0 0]; sysg = tf(numg,deng);
    numgc = [1 1]; dengc = [1 2]; sysgc = tf(numgc,dengc);  
    T1_num = series(sysg,sysgc); 
    T1 = feedback(T1_num,[1],-1);
    T2_1 = feedback(sysg,sysgc,-1);
    T2_2 = feedback(sysg,sysgc,+1);
end

