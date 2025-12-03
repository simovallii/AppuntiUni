using namespace std;
#include<iostream>

class Radio {

    private:

    int volume;
    bool acceso;
    float frequenza;

    public:

    Radio (){

        this->volume = 0;
        this->acceso = false;
        this->frequenza = 90.2;
    }

    void radioOn(){

        this->acceso = !this->acceso;

    }

    void alzaVolume(){

       
         if (!acceso) {

            cout << " accendi prima la radio" << endl;
    }
    else if (this->volume < 10) {

        this-> volume += 1;
    }
        else{

            cout << "Errore! Raggiunto volume massimo." << endl;

        }
    }
    void stampa () {

        cout << "volume = " << this->volume << endl;

        if (this->acceso){
        cout << "stato = accesa" << endl;
        }else{
        cout << "stato = spenta" << endl;
        }

    cout << "frequenza =  " <<  this->frequenza;
    }
};

int main (){

  
    Radio r;

    r.radioOn();
    r.alzaVolume();
    r.stampa();

    return 0;
}