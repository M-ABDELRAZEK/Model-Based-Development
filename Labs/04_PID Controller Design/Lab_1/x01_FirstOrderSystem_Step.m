K = 5;
R = 1e3;
C = 1e-6;
T = R * C;

Num = [K];
Den = [T 1];

G = tf(Num, Den);

step(G);

stepinfo(G)
