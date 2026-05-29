clc
clear
close all

coeff1 = [1 -6 11 -6];
coeff2 = [1 -7 15 -13 4];
x = linspace(-1, 4, 1000)
roots1 = roots(coeff1);
roots2 = roots(coeff2);
p1 = @(x) polyval(coeff1, x)
p2 = @(x) polyval(coeff2, x);

plot(x, p1(x))
grid on;
hold on;
plot(x, p2(x));
plot(roots1, p1(roots1),"*");
plot(roots2, p2(roots2), "*")
legend('Polynomial 1', 'Polynomial 2', "radici 1", "radici 2");