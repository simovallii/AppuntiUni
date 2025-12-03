#include "Punto.hh"
#include<iostream>
#include<cmath>

Punto::Punto(double x,double y) : x(x), y(y){};
Punto::Punto() : x(0), y(0){};

double Punto::distanzaDa(const Punto& p) const {
    double dx = x - p.x;
    double dy = y - p.y;

    return sqrt(dx*dx + dy*dy);
};

void Punto::stampa() const {
    std::cout<<x << ", " << y << std:: endl;
};

double Punto::getX() const {
    return x;
}

double Punto::getY() const {
    
}