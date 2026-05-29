clc
clear
close all

f = @(x) exp(-x) -10^-9;
der = @(x) -exp(-x);
res = newtonResiduo(f, der, 20, 1e-10)
resI = newtonIncremento(f, der, 20, 1e-10)


function xk1 = newtonResiduo(f, der, x0, tolerance)
xk1 = x0 - (f(x0)/der(x0));

while abs(f(xk1)) > tolerance
    xk = xk1;
    xk1 = xk - (f(xk))/der(xk);
end
end

function xk1 = newtonIncremento(f, der, x0, tolerance)
xk1 = x0 - (f(x0)/der(x0));
xk = x0
while abs(xk1 - xk) > tolerance
    xk = xk1;
    xk1 = xk - (f(xk))/der(xk);
end
end