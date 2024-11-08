function [y_t] = ilap(P,damp_ratio,wn)
    a_2 = 2*damp_ratio*wn; a_3 = wn^2;

    a = [1 a_2 a_3 0]; b = [-1 (2-a_2) -P];

    syms s;
    y_b = 0; y_a = 0;
    for i=1:1:length(b)
        y_b = y_b + b(i)*(s^(length(b)-i));
    end
    for i=1:1:length(a)
        y_a = y_a + a(i)*(s^(length(a)-i));
    end

    y = y_b./y_a;
    y_t = ilaplace(y); y_t = vpa(y_t);
    y_t = matlabFunction(y_t);

end

