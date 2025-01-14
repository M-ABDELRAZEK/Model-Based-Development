x = linspace(0, 8*pi, 10000);
y = sin(x);
plot(x, y)
grid on
title('Basic Plotting')
legend('Sine Wave')
xlabel('x')
ylabel('y(x)')