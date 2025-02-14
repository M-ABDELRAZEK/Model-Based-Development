R = 1e6;
C = 1e-6;
T = R * C; % Time Constant

num = 1;
den = [T 1];
G = tf(num, den);