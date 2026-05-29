clc
clear 
n = 50;
a = -4;
b = 4;
f = @(x) (4.*x)./(1 + (x.^2));
x = linspace(a, b, n);
i = 1:n;
xChebyshev = ((a + b)/2) - ((b-a)/2) .* cos(((2*i + 1)/(2*n + 2))*pi);
yChebyshev = f(xChebyshev);
y = f(x);
coeff1 = polyfit(x, y, n-1);
coeff2 = polyfit(xChebyshev, yChebyshev, n -1);
p1 = @(x) polyval(coeff1, x);
p2 = @(x) polyval(coeff2, x);

xgraf = linspace(-4, 4, 1000);
plot(xgraf, p1(xgraf));
hold on; 
grid on;
plot(xgraf, p2(xgraf));
legend("1", "2")