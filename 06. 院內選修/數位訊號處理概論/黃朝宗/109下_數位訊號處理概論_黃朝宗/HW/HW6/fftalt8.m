function X= fftalt8(x)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
s1 = zeros(1, 8);
s2 = zeros(1, 8);
X = zeros(1,8);
for i = 1:4
    s1(i) = x(i)+x(i+4);
end
for i = 5:8
    s1(i) = x(i-4)-x(i);
end
%==================
for i = 1:2
    s2(i) = s1(i)+s1(i+2);
end
for i = 3:4
    s2(i) = s1(i+2)+exp(-1j*2*pi/8*2)*s1(i+4);
end
for i = 5:6
    s2(i) = s1(i-4)-s1(i-2);
end
for i = 7:8
    s2(i) = s1(i-2)-exp(-1j*2*pi/8*2)*s1(i);
end
%==================
for i = 1:4
   X(i) = s2(2*i-1)+exp(-1j*2*pi/8*(i-1))*s2(2*i);
end
for i = 5:8
   X(i) = s2(2*(i-4)-1)-exp(-1j*2*pi/8*(i-5))*s2(2*(i-4));
end
end

