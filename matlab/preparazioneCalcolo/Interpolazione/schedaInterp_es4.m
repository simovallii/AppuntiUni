clc
clear
close all
n = 21; %grado polinomio, 22 nodi
f = @(x) sin(x);
x = linspace(-1, 1, n + 1);
y = f(x);
X = linspace(-1, 1, 100);
%interpoliamo la funzione
p = polyfit(x, y, n);
P = @(x)polyval(p, x);

%polinomio perturbato 
i = 1:n + 1;
fPert = @(x)sin(x(i)).* (1 + ((-1).^i) * 10^-4);
yPert = fPert(x);
pPert = polyfit(x, yPert, n);
PPert = @(x) polyval(pPert, x);


% plot(X, P(X));
% hold on;
% grid on;
% plot(X, PPert(X));
plot(X, abs(P(X)- PPert(X)))   %come varia l'errore di interpolazione
legend("polinomio non perturbato", "polinomio perturbato")