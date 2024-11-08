%%% CP8.1
close all; clear;
fprintf("CP8.1 \n");

num = [25]; den = [1 1 25];
sys = tf(num, den);
w = logspace(0,1,500);

[mag, phase] = bode(sys, w);
[mp, wr_index] = max(mag);
mp_log = 20*log10(mp); wr = w(wr_index);

fprintf("Mpw = %f dB, wr = %f rad/s", mp_log, wr);
figure; bode(sys, w); grid on;

%%% CP8.4
close all; clear;
fprintf("CP8.4 \n");

num = [54]; den = [1 6 0];
sys = tf(num, den);
sys_closed = feedback(sys,1);
wb = bandwidth(sys_closed);

title_name = strcat('Bandwidth = ', num2str(wb), ' rad/sec');
figure; bode(sys_closed); grid on;
title(title_name);

%%% CP8.9
close all; clear;
fprintf("CP8.9 \n");

K = 0.6;
a1 = [1 1]; a2 = [1 1000]; a = conv(a1, a2); a = K*a;
b1 = [1 20]; b2 = [1 80]; b = conv(b1, b2);

sys = tf(a, b);
w = logspace(0,3,10000);

[mag, phase] = bode(sys, w);
[mp, wp_index] = max(mag);
wp = w(wp_index);

fprintf("peak magnitude at wp = %f rad/s", wp);
figure; bode(sys); grid on;

%%% CP9.3
close all; clear;
fprintf("CP9.3 \n");

% a
a1 = [1]; b1 = [1 0.2];
sys1 = tf(a1, b1);
figure; nichols(sys1); ngrid;
% b
a2 = [1]; b2 = [1 2 1];
sys2 = tf(a2, b2);
figure; nichols(sys2); ngrid;
% c
a3 = [6]; b3 = [1 6 11 6];
sys3 = tf(a3, b3);
figure; nichols(sys3); ngrid;