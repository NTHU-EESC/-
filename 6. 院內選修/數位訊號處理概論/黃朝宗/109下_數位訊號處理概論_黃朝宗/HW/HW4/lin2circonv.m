function y = lin2circonv(x,h)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
lenX = length(x);
lenH = length(h);
if lenX > lenH
    N = lenX;
    h = [h zeros(1, N-lenH)];
elseif lenX < lenH
    N = lenH;
    x = [x zeros(1, N-lenX)];
else
    N = lenX; %The lenght of them is the same
end
    y_conv = conv(x, h);
    right = [zeros(1, N), y_conv(1:length(y_conv)-N)];%y_conv right shift N
    left = [y_conv(N+1:end), zeros(1,N)]; %y_conv left shift N
    y_tmp = y_conv+right+left;
    y = y_tmp(1:N);
end

