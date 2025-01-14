%% Equation
% Vin(t) = RC*dVc(t)/dt + Vc(t)
% dVc/dt = (Vin - Vc) / RC

% VC(t) is the voltage across the capacitor as a function of time.
% R is the resistance in ohms.
% C is the capacitance in farads
% Vin(t) is the input voltage as a function of time.

%% Parameters Definitions
R = 1000;
C = 1e-4;
Vin = @(t) 5 * sin(2*pi*t);
t_span = [0 10];

%% Solving The Equation
dVc_dt = @(t, Vc) ((Vin(t) - Vc) / (R*C));
Vc0 = 0; % Initial Condition
[t, Vc] = ode45(dVc_dt, t_span, Vc0);
plot(t, Vc, t, Vin(t), 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Vc(t) & Vin(t) (Volt)');
title('Voltage Across Capacitor & Source Voltage');
legend('Vc(t)', 'Vin(t)');
grid on