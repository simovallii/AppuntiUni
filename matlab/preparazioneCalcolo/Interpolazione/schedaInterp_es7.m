clear
clc
%%
x= linspace (-1,1,1000);
n=20;
xi= linspace (-1,1,n+1); %nodi di interpolazione
W= ones(size(x));
for i= 1:length(xi)
    W=W .* (x-xi(i));
end
plot (x,abs(W))
hold on
%% 
W1= ones(size(x));
xj=ones(n+1,1);
for j= 0:n
    xj(j+1)= cos((2*j+1)*pi/(2*n+2));
    W1= W1 .* (x-xj(j+1));
end
plot(x,abs(W1))
legend W W1