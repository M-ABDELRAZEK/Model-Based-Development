function outerFunction(a, b)
    result = innerFunction();
    fprintf('The Summation of %d + %d = %d\n', a, b, result)
    function sum = innerFunction()
        sum = a + b;
    end
end