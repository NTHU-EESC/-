function y = filterfirlp(h, x)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
filter_type = 0;
L = length(h);
M = L - 1;
type_I = 1:M/2;
type_III = 1:M/2;
type_II = 1:L/2;
type_IV = 1:L/2;
if mod(M, 2) == 0
    if h(type_I) == h(L+1 - type_I)
        fprintf('type I');
        filter_type = 1;
    elseif h(type_III) == -h(L+1 - type_III)
        if h(M/2 + 1) == 0
            fprintf('type III');
            filter_type = 3;
        end
    else
        y = conv(h, x);
        fprintf('h is not FIR linear phase filter!');
        return;
    end
else
    if h(type_II) == h(L+1 - type_II)
        fprintf('type II');
        filter_type = 2;
    elseif h(type_IV) == -h(L+1 - type_IV)
            fprintf('type IV');
            filter_type = 4;
    else
        y = conv(h, x);
        fprintf('h is not FIR linear phase filter!');
        return;
    end
end
length_x = length(x);
length_y = L+length_x-1;
y = zeros(1, length_y);  %initialize y
if filter_type == 1
    for k = 1:M/2
        y = y + h(k)*(shift(x, k-1, L) + shift(x, M-k+1, L));  % shift is another function (written in shift.m)
    end
    y = y + h(M/2+1)*shift(x, M/2, L);
elseif filter_type == 3
        for k = 1:M/2
            y = y + h(k)*(shift(x, k-1, L) - shift(x, M-k+1, L));
        end
elseif filter_type == 2
        for k = 1:L/2
            y = y + h(k)*(shift(x, k-1, L) + shift(x, M-k+1, L));
        end
else
    for k = 1:L/2
            y = y + h(k)*(shift(x, k-1, L) - shift(x, M-k+1, L));
    end
end


end

