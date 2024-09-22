%% MATLAB script that uses a while loop to print even numbers from 2 to 20
number = 2;
while number <= 20
    disp(number)
    number = number + 2;
end

%% script that calculates the factorial of a given number using a while loop
number = input('Enter a Number: ');
factorial = 1;
while number > 0
    factorial = factorial * number;
    number = number - 1;
end
disp(factorial)
