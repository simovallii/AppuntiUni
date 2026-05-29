clc
clear 
close all
coeff1 = [1 -6 11 -6];
x = linspace(1, 1.5, 1000);
f = @(x) polyval(coeff1, x);
xres = bisezione(f, 0.9, 1.5, 1e-10)
der = [3 -12 11];
fder = @(x)polyval(der, x)
xres2 = newton(f, 0.9, 1.5, fder, 1e-10, 1.2)
function x = bisezione(f, a, b, tolerance)
x = (a + b)/2;

while abs(f(x)) > tolerance
    if f(a)*f(x) < 0
        b = x;
    else
        a = x;
    end
    x = (a + b)/2;
end
end


function xk1 = newton(f, a, b, der, tolerance, x0)
xk1 = x0 - (f(x0)/der(x0));

while abs(f(xk1)) > tolerance
    xk = xk1;
    xk1 = xk - (f(xk)/der(xk));

end
end