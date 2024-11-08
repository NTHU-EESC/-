function [G,sos]=firdf2fs(h)
    H = fft(h); N = length(H);
    
    if(mod(N,2))
        K = (N+1)/2;
        N_even = 0;
    else
        K = (N/2);
        N_even = 1;
    end
            
    if(N_even)
        sos = [1 0 0 1 -1 0; zeros(K,6); 1 0 0 1 1 0];
        G = [H(1); zeros(K,1); H((N/2)+1)];
    else
        sos = [1 0 0 1 -1 0; zeros(K,6); 1 0 0 1 1 0];
        G = [H(1); zeros(K,1); 0];
    end
    
    for a = 2:1:K
        G(a) = 2*abs(H(a));
        thb1 = cos(angle(H(a)));
        thb2 = -cos(angle(H(a))-((2*pi*(a-1))/N));
        tha1 = -2*cos((2*pi*(a-1))/N);
        sos(a,:) = [thb1 thb2 0 1 tha1 1];
    end
end