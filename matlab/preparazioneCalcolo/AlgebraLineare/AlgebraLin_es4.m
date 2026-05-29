clc
clear
close all

x = ones(1000, 1);
y = ones(1000, 1);
A = hilb(1000);
B = rand(1000);

b = A*x;
c = B*y;

xCalcolata = A\b;
yCalcolata = B\c;

%calcolo gli errori
errx = norm((x - xCalcolata))/norm(x)
erry = norm((y - yCalcolata))/norm(y)

condizionamentoA = cond(A)
condizionamentoB = cond(B)

%osserviamo che la matrice A di Hilbert è mal condizionata e infatti
%l'errore è molto più grande rispetto all'errore di B che è di ordine basso
condHilb = [];
for i = 2:50
condHilb(i) = cond(hilb(i));
end
semilogy(1:50, condHilb)
grid on;
% clear
% clc
% 
% % Punto A
% A = hilb(1000);
% B = rand(1000);
% 
% x_esatta = ones(1000, 1);
% y_esatta = ones(1000, 1);
% 
% b = A * x_esatta;
% c = B * y_esatta;
% 
% % Punto B
% x_calcolata = A \ b;
% err_ass = norm(x_esatta - x_calcolata);
% y_calcolata = B \ c;
% err_ass_y = norm(y_esatta - y_calcolata);
% 
% % Punto 3
% err_err_x = norm(x_esatta - x_calcolata) / norm(x_esatta)
% err_rel_y = norm(y_esatta - y_calcolata) / norm(y_esatta)
% 
% % Punto D
% n_range = 1:50;
% cond_hilb = zeros(length(n_range), 1);
% 
% for i = 1:length(n_range)
%     A = hilb(n_range(i));
%     cond_hilbert(i) = cond(A);
%     i
%     n_range(i)
%     x_esatta = ones(i, 1);
%     b = A * x_esatta;
%     x_calcolata = A \ b;
%     err_rel_y(i) = norm(x_esatta - x_calcolata) / norm(x_esatta)
% end
% 
% figure;
% semilogy(n_range, cond_hilbert, '-s', 'LineWidth', 2);
% title('Condizionamento matrice di Hilbert');
% xlabel('dimensione della matrice');
% grid on;
% 
% figure;
% semilogy(n_range, err_rel_y,'-s');
% xlabel('dimensione della matrice');
% ylabel('errore relativo');
% grid on;
