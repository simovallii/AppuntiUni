clear
clc
close all

n = 7; % gradi polinomio
a = -5;
b = 5;
x = linspace(-5, 5, n + 1);
X = linspace(a, b, 100);
i = 0:n;
xChebyshev = ((a + b)/2) - ((b - a)/2) * cos(((2*i + 1)/(2*n + 2))*pi);
f = @(x) 1./(1 + x.^2);
y = f(x);

p = polyfit(x, y, n);
P = polyval(p, X);

pChebyshev = polyfit(xChebyshev, y, n)
PChebyshev = polyval(pChebyshev, X)

plot(X, P);
grid on;
hold on;
plot(X, PChebyshev)
legend("funzione runge", "chebyshev")

