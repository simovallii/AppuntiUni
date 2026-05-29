clc
clear 
close all

f = @(x) cos(2.*x)^2 -x.^2;
der = @(x) -4*cos(2.*x).*sin(2.*x) -2.*x; 

tolerance = 10e-10;
resCorde = corde(f, 0.3, 0.6, tolerance)
resNewton = newton(f, der, tolerance, 0.3)
resBisezione = bisezione(f, 0.3, 0.6, tolerance)

function xk1 = corde(f, a, b, tolerance)
x0 = a;
xk1 = x0 - f(x0)*(b-a)/(f(b)-f(a));
while abs(f(xk1)) > tolerance
    xk = xk1;
    xk1 = xk - f(xk)*(b-a)/(f(b)-f(a));
end
end

function xk1 = newton(f, der, tolerance, x0)
xk1 = x0 - (f(x0)/der(x0));

while abs(f(xk1)) > tolerance
    xk = xk1;
    xk1 = xk - (f(xk)/der(xk));
end
end

function x = bisezione(f, a, b, tolerance)
x = (a + b)/2;

while abs(f(x)) > tolerance
    if f(a)*f(x) < 0
        b = x;
    else
        a = x;
    end
    x = (a+b)/2;
end
end