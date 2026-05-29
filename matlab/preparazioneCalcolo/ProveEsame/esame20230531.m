clc
clear
close all

f = @(x) sin(pi.*x) + 2.*cos(pi.*x);
X = linspace(0.5, 1.5, 100);
xDati = [0.5 0.75 1.5];
yDati = f(xDati)';
matrice = vander(xDati);
% coeffVander = matrice\yDati;
% coeff = polyfit(xDati, f(xDati), 2);
% p = @(x) polyval(coeff, x);
% pvander = @(x) polyval(coeffVander, x);
% 
% err = abs(p(X) - pvander(X));
% plot(X, err)
% grid on;
% hold on;

D = diag(diag(matrice));
E = tril(matrice, -1);
F = triu(matrice, 1);
B = -inv(D + E) * F;
max(abs(eig(B)));

resultVero = trapz(xDati, yDati);

function xk1 = gaussSeidel(D, E, F, x, tolerance)
B = -inv(D + E) * F;
xk = x;
xk1 =  B * xk + inv(D + E) * b;

while norm(xk1 -xk) > tolerance
xk1 = B * x + inv(D + E) * b;
end
end
