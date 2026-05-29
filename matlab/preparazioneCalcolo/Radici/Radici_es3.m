clc
clear
close all

x = linspace(0.6, 1, 1000);
nmax = 100;
tolerance = 1e-10;

p = @(x) (x./8)*((63*(x.^4)) -70*(x.^2)  +15);

res = bisezione(p, 0.6, 1, 100, tolerance)
function x = bisezione(f, a, b, nmax, tolerance)
x = (a + b)/2;
iter = 1;
while abs(f(x)) > tolerance
    iter = iter + 1;
    if nmax == iter
        break;
    end
    if f(x) * f(a) < 0
        b = x;
    else
        a = x;
    end
    x = (a + b) / 2;
end
end
