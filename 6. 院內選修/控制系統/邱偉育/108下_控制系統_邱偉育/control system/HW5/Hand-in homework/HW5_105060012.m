close all; clear;

% Q1
% Parameters
m = 10; M = 100; L = 1; g = 9.81;
% PID tuning
KD = -50; KI = -50; KP = -((M+m)*g)-((KI/KD)*M*L)-50;
% Reference signal
r = 0; c_in = [0;1/M;0;0;-1/(M*L)];
ref_sig=@(t, x)[x(2);-m*g*x(4)/M;x(4);x(5);(M+m)*g*x(4)/(M*L)]+(-KP*x(4)-KI*x(3)-KD*x(5))*c_in;
T = linspace(0, 45, 3*1e3);
x0 = [0; 0; 0; 1; 0];
[t, Y] = ode45(@(t, x) ref_sig(t, x), T, x0);
u = (-KP.*Y(:,4)) + (-KI.*Y(:,3)) + (-KD.*Y(:,5));
% Plot
figure; plot(t, Y(:,4), t, u);
xlabel('Time[s]');
ylabel('Angular rotation [rad]');
legend(["Output"], ["Input"]);
figure; 
subplot(2,2,1); plot(t, u);
xlabel('Time[s]'); ylabel('Angular rotation [rad]');
legend(["Input"]);
subplot(2,2,2); plot(t, Y(:,4));
xlabel('Time[s]'); ylabel('Angular rotation [rad]');
legend(["Output"]);
subplot(2,2,3); plot(t, Y(:,1));
xlabel('Time[s]'); ylabel('Position');
legend(["Output"]);
subplot(2,2,4); plot(t, Y(:,4), t, u);
xlabel('Time[s]'); ylabel('Angular rotation [rad]');
legend(["Output"], ["Input"]);
% Solve equation
syms x;
eqn = M*L*x^3 - KD*x^2 - ((M+m)*g+KP)*x - KI == 0;
s = solve(eqn, x);
digits(6) % sets the precision used by vpa to 6 significant decimal digits.
vpa(s) % Variable-precision arithmetic

% Q2
% G(s)
b = [-1/(M*L)]; % -0.01
a = [1 0 -(M+m)*g/(M*L)]; % [1 0 -10.7910]
% PID(s)
b_pid = [KP KI KD]; a_pid = [1];
b_all = conv(b_pid, b); a_all = conv(a_pid, a);
figure; zplane(b_all,a_all);
% open-loop system
fprintf("open-loop system \n");
sys = tf(b_all, a_all);
figure; bode(sys); grid on;
figure; nyquist(sys); grid on;
% closed-loop system
fprintf("closed-loop system \n");
T_sys = feedback(sys,1,+1);
figure; bode(T_sys); grid on;
figure; nyquist(T_sys); grid on;