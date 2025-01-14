%% Equation
% τ*dT(t)/dt = Ku(Tsetpoint - T(t))

% T(t)is the temperature at time t..
% Tsetpoint is the desired setpoint temperature.
% τ is the time constant of the system.
% Ku is the system's gain.

%% Parameters Definitions
Tau = 5;
Ku = 2;
Tset = 75;
T0 = 20;
mdl = gcs;

%% Variation of Tau on The Response
Tau_Values = 1:3:13;
figure
for i = 1:numel(Tau_Values)
    Tau = Tau_Values(i);
    results = sim(mdl);
    plot(results.logsout.get('Temperature').Values);
    hold on
    grid on
    LegendLabels{i} = "Tau = " + num2str(Tau);
end
legend(LegendLabels)

%% Variation of Ku on The Response
Ku_Values = 1:3:13;
figure
for i = 1:numel(Ku_Values)
    Ku = Ku_Values(i);
    results = sim(mdl);
    plot(results.logsout.get('Temperature').Values);
    hold on
    grid on
    LegendLabels{i} = "Ku = " + num2str(Ku);
end
legend(LegendLabels)