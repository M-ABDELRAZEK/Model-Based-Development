K = 5;
T = 2;

num = [K];
den = [T 1];
G = tf(num, den);
t = 0:0.1:10;
U_Ramp = 0.1*t.^2;
[y_Ramp, t_Ramp] = lsim(G, U_Ramp, t);
plot(t_Ramp, y_Ramp);