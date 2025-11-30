#include<iostream>
using namespace std;

class Tv{

    private:

        bool acceso;
        int volume;
        int canale;

        bool validaCanale(int c) {

            return c >= 0 && c <= 99;
        }

    public:

        

        Tv (int c) {
            if (!Tv::validaCanale(c)){
                cout << "Errore" << endl;
            }
            else {
            this->canale = c;
            }

            acceso = true;
            volume = 5;

        }

        void stampaTelevisore() {

            if (acceso) {
            cout << "volume = " << volume << endl;
            cout << "canale = " << canale << endl:
            cout << "accesa" << endl;
            
            else {

                cout << "spenta" << endl;
            }
        }
        else {

            cout << "La TV \202 spenta!" << endl;
        }
        }
        
        void pulsanteAccedi () {

            acceso = !acceso;
        }

        void impostaCanale (int c ) {

            canale = c;
        }

        void canaleSuccessivo(){
            
            if (canale == 99){

                cout << "errore" << endl;

            }
            else{
            canale += 1;
            }
        }

        void canalePrecedente(){

            if (canale == 0){

                cout << "errore" << endl;
            }
            else {

                canale -= 1;
            }
        }

        void aumentaVolume (){

            if (volume == 10){
                
                cout << "errore" << endl;
            }
            else{

                volume += 1;
            }
        }

        void abbassaVolume(){

            if (volume == 0) {

                cout << "errore" << endl;
            }
            else{

                volume -= 1;
            }
        }

        void silenzia(){

            if (acceso){

                volume = 0;
            }
            else {

                cout << "La TV \202 spenta!" << endl;
            }
        }
};
int main(){

    Tv t1(5);
    t1.aumentaVolume();
    t1.pulsanteAccedi();
    t1.canaleSuccessivo();
    t1.stampaTelevisore();
    return 0;
}