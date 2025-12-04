#ifndef CERCHIO_HH
#define CERCHIO_HH

#include "Punto.hh"

class Cerchio{

    private:

        Punto centro;
        double raggio;
    
    public:

    Cerchio(const Punto& centro, double raggio);
    

        double area() const;
        double circonferenza() const;
        bool contiene(const Punto& p) const;
};
#endif