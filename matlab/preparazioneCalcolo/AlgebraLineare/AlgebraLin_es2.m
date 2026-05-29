clc
clear
close all

function x = forward(A, b)
n = length(b);
x = zeros(n, 1);

x(1) = b(1)/A(1, 1);

for i = 2:length(b)
    s= 0;
    for j = 1:i-1
       s = s + A(i, j)*x(j);
    end
    x(i) = (b(i) - s)/A(i, i);
end
end

function x = backward(A, b)
n = length(b);
x = zeros(n, 1);
x(n) = b(n)/A(n,n);

for i = n-1: -1: 1
    s = 0;
    for j = i+1 : n
        s = s + A(i, j)*x(j);
    end
    x(i) = (b(i) - s)/A(i, i);
end
end