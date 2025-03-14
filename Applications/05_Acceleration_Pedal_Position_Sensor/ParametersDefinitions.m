t = linspace(0, 10, 51)';
u = linspace(0, 1, 51)';

%% Plotting Results
sim('Position_Sensor.slx')
figure
hold on 
grid on
plot(t, u, 'b', 'LineWidth', 1.5);
plot(out.tout, out.yout{1}.Values.Data, 'r', 'LineWidth', 1.5);
xlabel("Time")
legend('Acceleration Pedal Sensor', 'Output Voltage')