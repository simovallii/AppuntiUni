clc
clear
close all

vettoreCond = zeros(50, 1);
vettoreDet = zeros(50, 1);
for n = 2: 50
vettoreCond(n) = cond(generaMatrice(n));
vettoreDet(n) = det(generaMatrice(n));
end

plot(1:50, vettoreCond, "-*")
grid on;
hold on;
plot(1:50, vettoreDet, "-*");
legend("condizionamenti", "determinanti")
function A = generaMatrice(n)
A = []; 
i = n;

  for j = 1: n

      A(j, i) = 2;
      A(j, i - 1) = -1;
      A(j + 1, i) = -1;
      i = i - 1;

      if i == 1
          A(j + 1, i) = 2; 
       break;
      end
end
end

% clear
% clc
% 
% n_max=50;
% i=1;
% 
% 
% 
% while i<=n_max
% determinanti(i)=det(genera_matrice(i));
% condizioanmenti(i)=cond(genera_matrice(i), 1);
% i=i+1;
% end
% 
% plot([1:n_max], determinanti, '-*');
% grid on; title("determinanti");
% xlabel('dimensione matrice')
% hold on;
% plot([1:n_max], condizioanmenti, '-*');
% title("condizionamenti");
% xlabel('dimensione matrice')
% grid on;
% 
% %funzione per generare la matrice
% function [A] = genera_matrice(n)
%     A= diag(2*ones(n, 1))+...
%     diag(-1*ones(n-1, 1), 1)+...
%     diag(-1*ones(n-1, 1), -1);
% 
%     A=fliplr(A);
% 
% end