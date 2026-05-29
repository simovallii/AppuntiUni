clear
clc
close all

x = [0.49, 0.64, 0.81];
y = [0.7, 0.8, 0.9]';
xdata = 0.60;
p = polyfit(x, y, 2);
P = @(x)polyval(p, x);
err = abs(P(xdata) -sqrt(xdata));
