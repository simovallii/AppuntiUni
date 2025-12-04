
#include "Cerchio.hh"
#include<cmath>
#include <string>
#include<iostream>
#include<stdexcept>

Cerchio::Cerchio(const Punto& p, double raggio) : centro(p), raggio(raggio){
    if(raggio <= 0)
        throw std::invalid_argument("argomento non valido");
}


    double Cerchio::area() const {
        return M_PI * pow(raggio, 2);
    }

    double Cerchio::circonferenza() const {
        return M_PI * (raggio * 2);
    }

    bool Cerchio::contiene(const Punto& p) const {
        return centro.distanzaDa(p) <= raggio;
    }
    
    