clc
clear
close all
v = ones(7, 1) * 15
matrice = diag(diag(v)) + diag(ones(6, 1), 1) + diag(ones(6, 1), - 1)
xData = [1 0 1 0 1 0 1]';
b = matrice*xData;
x = linspace(1, 7, 7) * 0;
x = x';
%i metodi convergono perchè la matrice  è diagonal dominante;
res = jacobi(matrice,x , b, 40);
[solGauss]= GaussS(matrice, b, x, 40);

for i  = 1:40
errJacobi(i)= norm(xData - res(: , i));
errGauss(i) = norm(xData - solGauss(:, i));
end
semilogy(1:40, errJacobi)
grid on;
hold on;
semilogy(1:40, errGauss)
legend("jacobi", "gauss-seidel")





function x = jacobi(matrice, x0, b, nmax)
D = diag(diag(matrice))
C = matrice - D;


[ n , n]= size ( matrice ) ;
iter=0;
x = [ ] ;
x_old=x0 ;
while iter <nmax
iter=iter +1;
B=-inv(D)*C ;
ragg = max(abs(eig(B)))
x ( : , iter )=B* x_old+inv (D)* b ;
x_old=x ( : , iter ) ;
end 
end
% Prepare for the Gauss-Seidel method

function [ x , B_Gauss]= GaussS ( a , b , x0 , nmax)
% 
[ n , n]= size ( a ) ;
iter=0;
x = [ ] ;
x_old=x0 ;
while iter <nmax
iter=iter +1;
D=diag ( diag(a)) ;
E= tril(a,- 1) ;
F=triu( a , 1 ) ;
B_Gauss=-inv(D+E)*F ;
ragg = max(abs(eig(B_Gauss)))
x ( : , iter )=-inv (D+E)*F* x_old+inv (D+E)* b ;
x_old=x ( : , iter ) ;
end
end