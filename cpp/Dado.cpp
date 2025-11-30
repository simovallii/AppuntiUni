using namespace std;
#include<iostream>
#include<ctime>



class Dado {

    private:
        int n_facce;
        int ultimo_lancio;

    public:

    Dado(){

        this->n_facce = 6;
        ultimo_lancio = 0;
    }

    Dado(int n_facce) {

        if (n_facce < 2) {
            throw invalid_argument("numero facce non valido");

            this->n_facce = n_facce;
        }
    }

    void reset(){

        this->ultimo_lancio = 0;
    }

    int lancia(){
        
        ultimo_lancio = (rand()%n_facce) + 1;

        return ultimo_lancio;
    }

    
};

int main(){
    srand(time(0));
    Dado d1;

    cout << d1.lancia();
 

    return 0;
}