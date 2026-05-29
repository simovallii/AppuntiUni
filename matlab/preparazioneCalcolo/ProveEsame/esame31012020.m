clc
clear 
close all
format long


res = 1 + eps
1

matrice = zeros(10)
matrice = matrice + triu(rand(10));
x = ones(10, 1)
b = matrice*x;
xapp = matrice\b

errapp = norm(x - xapp)
xback = backward(matrice, b, 10);
errback = norm(x - xback)
function x = backward(A, b, n)
x(n) = b(n)/A(n,n);

for i = n - 1 : -1 : 1
    sommatoria = 0;
 for j = i + 1: n
     sommatoria = sommatoria + A(i, j)*x(j);
 end
    x(i) = (b(i) - sommatoria)/A(i, i);
end
end