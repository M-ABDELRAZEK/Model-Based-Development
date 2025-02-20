%% Definitions
% C(s) = Kp + KI/s + KDs = Kd(s^2 + Kp/Kd * s + Ki/Dd) / s = Kd(s + ZPd)(s + Zpi) ==> PID Controller Equation
% 1 + L(s) = 0 % Root Locus Equation
% L(s) = C(s)*G(s) % Loop Transfer Function

H = 1; % Feedback Transfer Function
SystemParameters % External Script for System Forward Transfer Funstion

%% Requirements
Mp = 0.15; % Overshoot
steady_state_error = 0.05;
Ts = 3; % Settling Time

%% Get Poles, Zeros and characteristic Equation Paramerters
% rlocus(G);
P = pole(G);
Z = zero(G);

Wn_OpenLoop = sqrt(P(1) * P(2));
Zeta_OpenLoop = -(P(1)+P(2)) / (2*Wn_OpenLoop);
figure
pzmap(G)
hold on 
grid on

%% Design Point
Zeta = - log(Mp) / sqrt(pi^2 + log(Mp)^2);
Segma = 4 / Ts;
Wn = Segma / Zeta; % Or Wn = Segma * tan(acos(Zeta))
Wd = Wn * sqrt(1 - Zeta^2);
Tp = pi / Wd;
Theta = acos(Zeta);

%% Draw Lines From Centre To Design Point
L = 100; % Arbitrary length for the asymptote lines
X_Wn = L * cos(Theta);
Y_Wn = L * sin(Theta);

plot([0 -Segma*L], [0 Wd*L], 'r', 'LineWidth', 1.5);
plot([0 -Segma*L], [0 -Wd*L], 'r', 'LineWidth', 1.5);

%% Calculate Asymptotes Location & Angles
Num_Asymptotes = length(P) - length(Z);
for i = 0:Num_Asymptotes - 1
    Angles(i+1) = (2*i + 1) * 180 / Num_Asymptotes;
end

%% Draw Centroid & Asymptotes
Cd = (real(P(1)) + real(P(2))) / 2; % Centroid Between Poles
plot([Cd Cd], ylim, '--r', 'LineWidth', .5);

L = 100;
for TH = Angles
    x_end = Cd + L * cosd(TH);
    y_end = L * sind(TH);
    plot([Cd, x_end], [0, y_end], 'b', 'LineWidth', 1.4);
end

xlim([-30 0])
ylim([-30 30])

xlabel('Real Axis');
ylabel('Imaginary Axis');
title('Pole-Zero Map with Centroid and Asymptotes');

%% Get Intersection Point 
X_int = Cd;
Y_int = -Cd*tan(Theta);
plot(X_int, Y_int, 'RO', 'MarkerSize', 4, 'Color', 'k')
plot(X_int, -Y_int, 'RO', 'MarkerSize', 4, 'Color', 'k')
legend('Poles & Zeros', 'Line', 'Line', 'Centroid', 'Asymptotes', 'Intersection Point', 'Intersection Point');

%% Get Gain Value
% 1 + L(s) = 1 + K*G(s) = 0
s = X_int + Y_int*i;
L_value = evalfr(G, s);
K = 1/L_value;

sys = feedback(K*G, H);
step(sys)