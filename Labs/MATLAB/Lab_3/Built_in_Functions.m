function Built_in_Functions(varargin)
    vector = [varargin{:}];
    
    maxVal = max(vector);
    fprintf('The Maximum is: %d\n', maxVal)
    minVal = min(vector);
    fprintf('The Minimum is: %d\n', minVal)
    sumVal = sum(vector);
    fprintf('The summation is: %d\n', sumVal)
    average = mean(vector);
    fprintf('The Average is: %d\n', average)
    sortedValues = sort(vector);
    fprintf('The Sorted Vector is:\n')
    disp(sortedValues)

end