%% Extend the cost calculation script by including an input for the number of miles and then use the switch statement to calculate the total cost.
disp('Transportation Modes Available')
disp('1) Car')
disp('2) Train')
disp('3) Bus')
disp('4) Airplane')

Transportation = input('Enter Your Transportation Mode: ', 's');
Miles = input('Enter The Distance: ');

switch Transportation
    case {'1', 'Car', 'car'}
        cost = Miles * 2;
    case {'2', 'Train', 'train'}
        cost = Miles * 5;
    case {'3', 'Bus', 'bus'}
        cost = Miles * 7;
    case {'4', 'Airplane', 'airplane'}
        cost = Miles * 10;
    otherwise
        cost = 0; 
end

fprintf('The Total Cost of Travel is: $%d\n', cost)
