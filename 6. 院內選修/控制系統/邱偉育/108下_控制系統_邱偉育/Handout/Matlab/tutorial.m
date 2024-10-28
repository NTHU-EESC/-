%%
clc  % clears command window
clear all % clear workspace 
A =  [ 1 2 3 ; 4 5 6; 7 8 9];
B = A(1:2, :);
C= A(:,2:3);

%%
a =[ 1 3 ; 2 4]
b = [3 0; 1 5]
z_1 = a*b
z_2 = a.*b


%%
%A*X = B
y_1 = [2 4 ; 1 4]   %y_1 = 2*x_1 + 4*x_2 = 16;
y_2 = [16; 14]      %y_2 = 1*x_1 + 4*x_2 =14;
x_value =y_1 \ y_2  %You can also do inv(y_1)*y_2
 
 
%% 
%plot equations
subplot(1,2,1) % column:1 /row:2 /figure location: 1
fplot(@(x) sqrt(cos(2*x))-2,[-pi/2, pi/2])  %ezplot(fun2,[xymin,xymax])
title('sqrt(cos(2*x))-2');
xlabel('x');

subplot(1,2,2)  % column:1 /row:2 /figure location: 2
syms x y
ezplot((x.^2/3) - (y./5), [-2, 2, -4, 4]) %ezplot(fun,[xmin,xmax,ymin,ymax])
