clc; clear;

%% System Equations
% m * a + b * v + k * x = F
% F = 0 ==> Steady State

%% Paramiters Difinitions
b = 10; % Damping Coefficient
k = 400; % Spring Coefficient
x0 = 1; % Initial Position
m = 3; % mass

%% Simulate Multiple Times
mdl = gcs; % get current system 
massValues = 1:2:11;

for i = 1:numel(massValues)
    m = massValues(i);
    result = sim(mdl);
    plot(result.logsout.get("Position").Values);
    hold on
    disp("Simulation " + num2str(i) + " Complete");
    LegendLables{i} = "mass = " + num2str(m);
end
legend(LegendLables);