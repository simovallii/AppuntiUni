clc
clear
close all;

n = 20; %10, 15, 20
x = linspace(-1, 1, n + 1);
X = linspace(-1, 1, 101);
f = @(x) exp(x) + 1;
matrice = vander(x);
y = f(x);
coeff = matrice\y'
P = @(x) polyval(coeff, x);

i = 1:n + 1;
epsilon = ((-1).^i) * 10^-5;
ypert = y + epsilon;
pPert = polyfit(x, ypert, n);
PPert = @(x) polyval(pPert, x);

plot(X, P(X));
hold on;
grid on;
plot(X, PPert(X));
legend("polinomio non perturpato", "pert")

maxP = max(abs(P(X) -PPert(X)));
maxA = max(abs(coeff - pPert));





