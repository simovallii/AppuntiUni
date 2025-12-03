#include "Punto.hh"
#include<iostream>

int main(){
    
    Punto p(3, 5);
    Punto p2(43, 7);
    double x = p.distanzaDa(p2);
    p.stampa();
    p2.stampa();
}