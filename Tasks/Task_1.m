%% Numeric Types
intVar = 23;
doubleVar = 3.8;
disp(['The data type of intVar is: ', class(intVar)])
disp(['The data type of doubleVar is: ', class(doubleVar)])

%% Creating Numeric Arrays
evenNumbers = [2:2:10];
primeNumbers = [2;3;5;7;11];

disp(evenNumbers)
disp(primeNumbers)

%% Specialized Matrix Functions
identityMatrix = eye(3);
magicSquare = magic(2)

disp(identityMatrix)
disp(magicSquare)

%% Matrix Concatenation
combinedVector = horzcat(evenNumbers, primeNumbers');
combinedMatrix = vertcat(identityMatrix, horzcat(magicSquare, zeros(2,1)));

disp(combinedVector)
disp(combinedMatrix)