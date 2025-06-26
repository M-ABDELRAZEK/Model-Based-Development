%% Advanced Simulink Scripting Lab
% Author: Mohamed
% Date: 26/6/2025
%
% Purpose:
% - Dynamically create Simulink blocks and connections
% - Perform parameter sweeps and automate simulations
% - Analyze logged data from simulations
%
% Key Parameters:
%   Solver: ode45 
%   StopTime: 10s 
%   Gain Sweep: 1-10 
%
% Structure:
%   1. Model Creation
%   2. Dynamic Block Creation
%   3. Simulation & Results

%% 1. Model Creation
close all; clear; clc;

ModelName = 'AdvancedLab';
new_system(ModelName, "Model");
open_system(ModelName);

% Model Configurations
set_param(ModelName, ...
          'Solver', 'ode45', ...
          'StopTime', '10', ...
          'SignalLogging', 'on', ...
          'SaveOutput', 'on', ...
          'SaveFormat', 'Dataset');

%% 2. Dynamic Block Creation
add_block('simulink/Ports & Subsystems/Subsystem', [ModelName, '/DynamicSubsystem']);
add_block('simulink/Math Operations/Gain', [ModelName, '/DynamicSubsystem/Gain']);
add_block('simulink/Sinks/Scope', [ModelName, '/DynamicSubsystem/Scope']);
add_block('simulink/Sources/Sine Wave', [ModelName, '/DynamicSubsystem/SineWave']);
add_block('simulink/Math Operations/Sum', [ModelName, '/DynamicSubsystem/Sum'])

% Block Parameters
set_param([ModelName, '/DynamicSubsystem/Gain'], 'Gain', '5');
set_param([ModelName, '/DynamicSubsystem/Sum'], 'Inputs', '|+-');
Simulink.sdi.markSignalForStreaming([ModelName, '/DynamicSubsystem/Gain'], 1, 'on');
inports  = find_system(ModelName, 'SearchDepth', 2, 'BlockType', 'Inport');
outports = find_system(ModelName, 'SearchDepth', 2, 'BlockType', 'Outport');
delete_block(inports);
delete_block(outports);

% Add Lines
add_line([ModelName, '/DynamicSubsystem'], 'SineWave/1', 'Sum/1', 'autorouting', 'smart');
add_line([ModelName, '/DynamicSubsystem'], 'Sum/1', 'Gain/1', 'autorouting', 'smart');
add_line([ModelName, '/DynamicSubsystem'], 'Gain/1', 'Scope/1', 'autorouting', 'smart');
add_line([ModelName, '/DynamicSubsystem'], 'Gain/1', 'Sum/2', 'autorouting', 'smart'); % For Feedback

% Auto Arrange
Simulink.BlockDiagram.arrangeSystem([ModelName, '/DynamicSubsystem']);

%% 3. Simulation Setup & Results
OutData = cell(1, 10);
NumSim = length(OutData);

for GainValue = 1:NumSim
    set_param([ModelName, '/DynamicSubsystem/Gain'], 'Gain', num2str(GainValue));
    SimOut = sim(ModelName);
    plot(SimOut.logsout{1}.Values);
    hold on
    disp("Simulation " + num2str(GainValue) + " Complete");
    LegendLables{GainValue} = "Gain = " + num2str(GainValue);
end
legend(LegendLables);
xlabel('Time');
ylabel('Signal After Feedback');
title('System Response to Gain Variation');