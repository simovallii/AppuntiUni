#include<iostream>
#include"Cerchio.hh" 


int main(){

    Punto p;
    Cerchio c(p, 3);

    std::cout << "circonferenza: "<< c.circonferenza() << std::endl; 
    std::cout << "area: "<< c.area() << std::endl;

    Punto p2(23, 4);

    if(c.contiene(p2))
        std::cout<< "il punto e' contenuto"; 
    else
        std::cout<< "il punto non e' contenuto";
}