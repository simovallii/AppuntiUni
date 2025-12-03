#include<iostream>
#include<fstream>
using namespace std;

class Intervallo    {

    private:
        int inizio;
        int fine;

    

    bool valid(int i, int f){

        return i >= 0 && f >= 0 && i < f;
    }

    public:



    Intervallo() : Intervallo(0,1){};

    Intervallo(int i, int f){

        if(valid(i, f)){
        this->inizio = i;
        this->fine = f;
        }
        else {

            cout << "errore" << endl;

            this->inizio = 0;
            this->fine = 1;
        }
    }

    
    int getInizio() const
    {
        return this->inizio;
    }


    void setInizio(int inizio)
    {   
        if (inizio < this->fine && inizio > 1)
        this->inizio = inizio;
    }

    int getFine() const
    {
        return this->fine;
    }

    void setFine(int fine)
    {   
        if (fine > this->inizio && fine > 1)
            this->fine = fine;
        else
            cout << "input non valido" << endl;
    }

        bool contains (const int& x){

            int i = inizio;
            int f = fine;

            while (i < f){

                if (i == x){

                    return true;
                }
                i++;
            }

            return false;
        }

        Intervallo join (const Intervallo &i){

            Intervallo result = *this;

            if (i.inizio <=  this->inizio) {

                result.inizio = i.inizio; 

            }

            if (i.fine > this->fine){

                result.fine = i.fine;
            }

            return result;  
        }

        void stampa(ostream& dest) const {

            dest << getInizio()<< "," << getFine();
        }


        Intervallo operator+(const Intervallo &other) {

            Intervallo result = *this;

            result.inizio = this->inizio + other.inizio;   // i1 + i2     i1.operator+(i2)
            result.fine = this->fine + other.fine;

            if (valid(result.inizio, result.fine)) {

                return result;
            }
            else{

                cout << "errore nella somma" << endl;
                return *this;
            }
        }

        Intervallo operator* (const Intervallo &other) {

            Intervallo result = *this;

            result.inizio = this->inizio * other.inizio;
            result.fine = this->fine * other.fine;

            if (valid(result.inizio, result.fine)) {

                return result;
            }
            else{

                cout << "errore nel prodotto" << endl;
                return *this;
            }
        }
        
        
    };

ostream& operator<< (ostream& dest,const Intervallo& i ) {

        i.stampa(dest);

        return dest;
}

istream& operator>> (istream &source, Intervallo& i) {

        int inizio, fine;

        source >> inizio >> fine;

        i.setInizio(inizio);
        i.setFine(fine);
       
        return source;
        
};
int main(){ 

    Intervallo i1;
    Intervallo i2;

  cin >> i1;
  cin>> i2; 

 Intervallo i3  =  i1 + i2 ;



    cout << i3;

    return 0;
}