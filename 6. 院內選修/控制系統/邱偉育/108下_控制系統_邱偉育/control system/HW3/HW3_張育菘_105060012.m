%CP3.1
%a
g1_num = [1]; g1_den = [1 10]; 
g1_tf = tf(g1_num, g1_den);
g1_ss = ss(g1_tf);
%b
g2_num = [1 5 3]; g2_den = [1 8 5]; 
g2_tf = tf(g2_num, g2_den);
g2_ss = ss(g2_tf);
%c
g3_num = [1 1]; g3_den = [1 3 3 1]; 
g3_tf = tf(g3_num, g3_den);
g3_ss = ss(g3_tf);

%CP3.2
%a
a1 = [0 1; 2 8]; b1 = [0; 1]; 
c1 = [1 0]; d1 = [0];
sys1_ss = ss(a1, b1, c1, d1);
sys1_tf = tf(sys1_ss);
%b
a2 = [1 1 0; -2 0 4; 5 4 -7]; b2 = [-1; 0; 1]; 
c2 = [0 1 0]; d2 = [0];
sys2_ss = ss(a2, b2, c2, d2);
sys2_tf = tf(sys2_ss);
%c
a3 = [0 1; -1 -2]; b3 = [0; 1]; 
c3 = [-2 1]; d3 = [0];
sys3_ss = ss(a3, b3, c3, d3);
sys3_tf = tf(sys3_ss);

%CP3.4
%a
a = [0 1 0; 0 0 1; -3 -2 -5]; b = [0; 0; 1]; 
c = [1 0 0]; d = [0];
sys_ss = ss(a, b, c, d);
sys_tf = tf(sys_ss);
%b
x0 = [0; -1; 1]; % initial condition
t = [0:0.01:10]; 
u = 0*t; % zero input
[y,T,x]=lsim(sys_ss,u,t,x0);
figure;
subplot(3,1,1); plot(T,x(:,1)); 
xlabel('Time (s)'); ylabel('x_1'); 
subplot(3,1,2); plot(T,x(:,2));
xlabel('Time (s)'); ylabel('x_2'); 
subplot(3,1,3); plot(T,x(:,3));
xlabel('Time (s)'); ylabel('x_3'); 
figure; plot(T,y);
xlabel('Time (s)'); ylabel('y'); 
%c
dt = 10;
phi = expm(a*dt);
fprintf("the result from part(c):");
x3 = phi*x0
fprintf("the result from part(b):");
ans_b = x(1001,:);

%CP3.7
a = [0 1; -2 -3]; b = [0; 1]; 
c = [1 0]; d = [0];
sys_ss = ss(a, b, c, d);
x0 = [1; 0]; % initial condition
t = [0:0.01:10]; 
u = 0*t; % zero input
[y,T,x]=lsim(sys_ss,u,t,x0);
figure;
subplot(2,1,1); plot(T,x(:,1)); 
xlabel('Time (s)'); ylabel('x_1'); 
subplot(2,1,2); plot(T,x(:,2));

%CP3.8
dk = 0.1; K_fv = 100;
K = [0: dk: K_fv];
eigenA_real = zeros(3, (dk^-1)*K_fv+1);
i = 1;
for j = 0: dk: K_fv
    a = [0 1 0; 0 0 1; -2 -j -2]; 
    eigenA = eig(a);
    eigenA_real(:,i) = real(eigenA);
    i = i + 1;
end
figure; 
plot(K, eigenA_real(1,:)); hold on;
plot(K, eigenA_real(2,:));
plot(K, eigenA_real(3,:)); hold off;
xlabel('K'); ylabel('real part of eigenvalues');
legend(["e1"], ["e2"], ["e3"]);