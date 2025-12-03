class Punto {
    private:
        double x;
        double y;
    public: 

    Punto(double x, double y) ;  
    Punto();

    double distanzaDa(const Punto& p) const;

    void stampa() const;

    double getX() const;
    double getY() const;


};