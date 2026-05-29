x = [-1.5, -0.5, 0.5, 1.5];
y = [0.1054, 0.7788 0.7788 0.1054];

coeff = polyfit(x, y, length(x) - 1);
x_g = linspace(-1.5, 1.5, 1000);
p = @(x)polyval(coeff, x);
pInt = @(x_g)interp1(x, y, x_g);
semilogy(x_g, p(x_g))
hold on;
grid on;
semilogy(x_g, pInt(x_g))
legend("polinomio interpolante", "composita linare")



%2c e 2d
a = -1.5;
b = 1.5;
p1_integrato = trapz(x_g, p(x_g))   %calcola gli integrali col trapezio
p2_integrato = trapz(x_g, pInt(x_g))

g = @(x) exp(-x.^2);
g_integrato = trapz(x_g, g(x_g))
err1 = abs(p1_integrato - g_integrato)
err2 = abs(p2_integrato - g_integrato)


%es1 TODO

