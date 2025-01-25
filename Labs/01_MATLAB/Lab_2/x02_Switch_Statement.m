%% MATLAB script to calculate the cost of a trip based on the mode of transportation
disp('Transportation Modes Available')
disp('1) Car')
disp('2) Train')
disp('3) Bus')
disp('4) Airplane')

Transportation = input('Enter Your Transportation Mode: ', 's');
switch Transportation
    case {'1', 'Car', 'car'}
        cost = 2;
    case {'2', 'Train', 'train'}
        cost = 5;
    case {'3', 'Bus', 'bus'}
        cost = 7;
    case {'4', 'Airplane', 'airplane'}
        cost = 10;
    otherwise
        cost = 0; 
end

fprintf('The Total Cost of Travel is: $%d\n', cost)

%% script that translates a color code into its corresponding name
color_code = input("Enter Color Code ('R', 'W', 'B', 'Y', 'G'): ", 's');
switch color_code
    case {'R', 'r'}
        disp('Red')
    case {'W', 'w'}
        disp('White')
    case {'B', 'b'}
        disp('Blue')
    case {'Y', 'y'}
        disp('Yellow')
    case {'G', 'g'}
        disp('Green')
    otherwise
        disp('Unknown Color')
end