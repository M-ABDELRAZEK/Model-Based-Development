%% Equation
% L⋅θ¨(t) + g⋅sin(θ(t)) = 0
% L⋅θ¨(t) + b⋅θ(t) + g⋅sin(θ(t)) = 0
% θ¨(t) = - b/L θ'(t) - g/L sin(θ(t))

% L is the length of the pendulum (meters).
% θ¨(t) is the angular acceleration (radians/second²).
% g is the acceleration due to gravity (9.81 m/s²).
% θ(t) is the angular displacement from the vertical position (radians).
% b is the Damping coefficient

%% Parameters Difinitions
L = 1;
g = 9.81;
t_span = [0 10];
b = .5; % Damping Coefficient

%% Solving Equation & Plotting Without Damping Effect
figure
lengthValues = 1:5;
for i = 1:numel(lengthValues)

    L = lengthValues(i);
    % y = [theta; theta_dot]; % is called state vector
    f = @(t, y)[y(2); -g/L *sin(y(1))]; % [theta_dot: theta_double_dot]

    theta0 = pi/4; % initial Position
    theta_dot0 = 0; % initial angular velocity
    y0 = [theta0; theta_dot0];

    [t, y] = ode45(f, t_span, y0); % Ordinary Differential Equation Solver
        
    theta = y(: ,1); % Extracting Angular Position Values
    theta_dot = y(: ,2); % Extracting Angular Velicity Values

    % Plotting Angular Displacement & Velocity
    plot(t, theta, t, theta_dot, 'LineWidth', 1.5)
    LegendLabels(i) = "Length = " + num2str(L);
    xlabel('time (s)')
    ylabel('\theta (rad) and \theta'' (rad/s)')
    title("Anguar Displacement & Angular Velocity")
    grid on
    hold on
end
legend(LegendLabels);

%% Solving Equation & Plotting With Damping Effect
figure
lengthValues = 1:5;
for i = 1:numel(lengthValues)
    
    L = lengthValues(i);
    % y = [theta; theta_dot]; % is called state vector
    f = @(t, y)[y(2); -b/L *y(2)-g/L *sin(y(1))]; % [theta_dot; theta_double_dot]
    
    theta0 = pi/4; % initial Position
    theta_dot0 = 0; % initial angular velocity
    y0 = [theta0; theta_dot0];
    
    [t, y] = ode45(f, t_span, y0); % Ordinary Differential Equation Solver
    
    theta = y(: ,1); % Extracting Angular Position Values
    theta_dot = y(: ,2); % Extracting Angular Velicity Values
    
    % Plotting Angular Displacement & Velocity
    plot(t, theta, t, theta_dot, 'LineWidth', 1.5)
    LegendLabels(i) = "Length = " + num2str(L);
    xlabel('time (s)')
    ylabel('\theta (rad) and \theta'' (rad/s)')
    title("Anguar Displacement & Angular Velocity")
    grid on
    hold on
end
legend(LegendLabels);
