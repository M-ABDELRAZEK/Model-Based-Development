clear; clc; close all;

% Create Model
ModelName = 'ControlSystemProjectModel';
new_system(ModelName);

% Add Blocks
add_block('simulink/Sources/Step', [ModelName, '/StepInput'], 'Position', [30, 50, 60, 80]);
add_block('simulink/Continuous/Transfer Fcn', [ModelName, '/Plant'], 'Position', [110, 40, 200, 90]);
add_block('simulink/Continuous/PID Controller', [ModelName, '/PID Controller'], 'Position', [250, 50, 310, 80]);
add_block('simulink/Sinks/Scope', [ModelName, '/Scope'], 'Position', [350, 50, 380, 80]);

% Add Lines
add_line(ModelName, 'StepInput/1', 'Plant/1');
add_line(ModelName, 'Plant/1', 'PID Controller/1');
add_line(ModelName, 'PID Controller/1', 'Scope/1');

% Configurations
set_param([ModelName, '/Plant'], 'Numerator', '[1]','Denominator', '[1, 2]')
set_param([ModelName, '/PID Controller'], 'P', num2str(1),'I', num2str(.5), 'D', num2str(0.01))

% Save & Simulate
save_system(ModelName);
sim(ModelName);
open_system(ModelName);
open_system([ModelName, '/Scope'])

% close_system(ModelName)