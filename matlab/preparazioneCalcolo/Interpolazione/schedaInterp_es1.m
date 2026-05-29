clear
clc
close all

n = 5; %grado polinomio
x = linspace(0, 2, n + 1);
X = linspace(0, 2, 100);
f = @(x)  exp(x).*sin(2.*x);
y = f(x);

p = polyfit(x, y, n); %coefficienti 
P = @(x)polyval(p, x); %polinomio valutato in n+1 punti

plot(x, P(x), "*")  %punti interpolazione
hold on;
plot(X, P(X)) 
grid on;



