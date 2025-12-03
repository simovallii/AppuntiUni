
#include<iostream>
using namespace std;

class Data{
    
    protected:
        int g;
        int m;
        int a;
    
    public:

        Data(int g, int m, int a){
            this->g = g;
            this->m = m;
            this->a = a;
        }

        void print(ostream& dest){

            dest << "giorno: " << g << ", mese: " << m << ", anno: " << a << endl;
        }
};

class DataConOrario : public Data{

    private:
        int sec;

        int getOre(){

            return sec/3600;
        }

        int getMinuti(){

            return (sec%3600)/60;
        }
        int getSecondi(){

            return sec/3600;
        }
        // fare coversione ore minuti secondi, 3 metodi
    public:
        DataConOrario(int g, int m, int a, int sec) : Data(g, m, a){

            this->sec = sec;
        }


        void print(ostream& dest){

            Data:: print(dest);
            // TODO
        }
};