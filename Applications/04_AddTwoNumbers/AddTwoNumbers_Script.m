close all;
clear; 
clc;

% Create Model
ModelName = 'AddTwoNumbers_Model';
new_system(ModelName, 'model')
open_system(ModelName)

% Add Block
add_block('built-in/Subsystem', [ModelName,'/Add Two Numbers'])
add_block('simulink/Sources/In1', [ModelName,'/Add Two Numbers/Number One'])
add_block('simulink/Sources/In1', [ModelName,'/Add Two Numbers/Number Two'])
add_block('simulink/Math Operations/Add', [ModelName,'/Add Two Numbers/Addition'])
add_block('simulink/Sinks/Out1', [ModelName,'/Add Two Numbers/Summation'])

% Add Lines
add_line([ModelName,'/Add Two Numbers'], 'Number One/1', 'Addition/1')
add_line([ModelName,'/Add Two Numbers'], 'Number Two/1', 'Addition/2')
add_line([ModelName,'/Add Two Numbers'], 'Addition/1', 'Summation/1')

% Create Mask
set_param([ModelName, '/Add Two Numbers'], 'Mask', 'on')
set_param([ModelName, '/Add Two Numbers'], 'MaskDescription', 'Subsystem to add two numbers')
set_param([ModelName, '/Add Two Numbers'], 'MaskType', 'Add Two Numbers Block')
set_param([ModelName, '/Add Two Numbers'], 'MaskDisplay', 'disp("Add Two Numbers Block")')

%% Test
add_block('simulink/Sources/Constant', [ModelName, '/First'], 'Value', num2str(1))
add_block('simulink/Sources/Constant', [ModelName, '/Second'], 'Value', num2str(2))
add_block('simulink/Sinks/Display', [ModelName, '/Result'])

add_line(ModelName, 'First/1', 'Add Two Numbers/1')
add_line(ModelName, 'Second/1', 'Add Two Numbers/2')
add_line(ModelName, 'Add Two Numbers/1', 'Result/1')

sim(ModelName);

