%% Parameters Definition
% C(s) = Kp+KI/s+KDs = Kp(1+1/(Tis)+Tds). ==> PID Controller Equation

%% Step Response in Open Loop Test
[Res, time] = step(G);
figure
plot(time, Res, 'LineWidth', 1.5);
grid on;
xlabel('Time (s)');
ylabel('Response');
title('Step Response');

%% Defferention To get Inflection Point
dt = time(2) - time(1);
dy_dt = diff(Res)/dt;
d2y_dt2 = diff(dy_dt)/dt;

dy_dt = [dy_dt; NaN];
d2y_dt2 = [d2y_dt2; NaN; NaN];

figure;
plot(time, d2y_dt2, 'r', 'LineWidth', 1.5);
hold on
plot(time, dy_dt, 'b', 'LineWidth', 1.5);
grid on
xlabel("Time")
legend("d2y/dt2", "dy/dt")
title("First and Second Derivative Values")
hold off

%% Find Inflection Point
Inf_index = find(d2y_dt2(1:end-1) .* d2y_dt2(2:end) < 0, 1);
Inf_Time = time(Inf_index);
Inf_Res = Res(Inf_index);

%% Draw Tangent Line At Inflection Point
Slope = dy_dt(Inf_index);
TangentLine = Slope * (time - Inf_Time) + Inf_Res;
figure(1)
hold on
plot(time, TangentLine, "K", 'LineWidth', 1.5);
plot(Inf_Time, Inf_Res, "RO", 'MarkerSize', 1, 'LineWidth', 5, 'Color', 'r')
xlim([0 1.2]);
legend("Response", "Tangent", "Inflection Point");

%% Get L (Delay Time) & T (Time Constant) & K (System Gain)
% t0 ==> time when the response start increasing
% t1 ==> time at inflection 
% t2 ==> intersection of tengent with the final value
% T = t2 - t1
% L = t1 - t0
% K = 
t0 = 0;
t1 = Inf_Time;
SteadyState = Res(end);
t2 = (SteadyState - Inf_Res) / Slope + t1;

plot(t2, SteadyState, 'RO', 'MarkerSize', 1, 'LineWidth', 5, 'color', 'r');
legend("Response", "Tangent", "Inflection Point", "Intersection at Final Value");

input = 1;
K = SteadyState / input;
T = t2 - t1;
L = t1 - t0;

%% Find PID Constants
% From Table
Ti = 2 * L;
Td = .5 * L;

Kp = (1.2*T)/K*L;
Ki = Kp / Ti;
Kd = Kp * Td;



