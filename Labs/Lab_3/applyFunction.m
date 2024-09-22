function result = applyFunction(funcHandle, vector)
    result = arrayfun(funcHandle, vector);
end

%% Handle Functions
%square = @(x) x.^2;
%cube = @(x) x.^3;