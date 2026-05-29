clear
clc
close all
m = 100;
a = 0;
b = 2*pi;


f = @(x) x.*exp(-x) .* cos(2*x);
res = PuntoMedioComposita(f, a, b, m)
res2 = trapeziComposita(f, a, b, m)
err = [];

i = 1;
for m = 10:10:100
err(i) = PuntoMedioComposita(f, a,b, m);
i = i + 1;
end
m = 10:10:100;
semilogy(m, err)
grid on;
function risultato = PuntoMedioComposita(f, a, b, m)
H = (b - a)/m;
x = a + H/2 : H : b;  %ricordarsi!!
y = f(x);
risultato = H * sum(y);

end
function risultato = trapeziComposita(f, a, b, m)
H = (b - a)/m;
x = a : H : b;
y = f(x);
sommatoria = y(2:m);
risultato = (H/2) * (y(1)+ 2*sum(sommatoria) + y(m + 1));
end
