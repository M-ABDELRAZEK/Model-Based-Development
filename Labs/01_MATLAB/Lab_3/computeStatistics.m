function [meanVal, standardDeviation] = computeStatistics(varargin) 
    vector = [varargin{:}];
    meanVal = mean(vector);
    standardDeviation = std(vector);
end
