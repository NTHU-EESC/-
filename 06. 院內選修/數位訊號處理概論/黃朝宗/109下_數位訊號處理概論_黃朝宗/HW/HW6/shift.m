function shift_x = shift(x, k, L)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
length_x = length(x);
length_total = length_x+L-1;  % L is the length of h
shift_x = zeros(1, length_total);
for m = 1: length_x
    shift_x(m+k) = x(m);
end

