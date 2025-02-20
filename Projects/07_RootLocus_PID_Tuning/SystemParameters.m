%% RC Circuit Second Order System
R1 = 1e6;
R2 = 1e6;
C1 = 0.1e-6;
C2 = 0.1e-6;

num = [1/(R1*R2*C1*C2)]; 
den = [1 (R1*C1+R2*C2+R1*C2)/(R1*R2*C1*C2) 1/(R1*R2*C1*C2)];

G = tf(num, den)