#include<iostream>
using namespace std;
class Prodotto {

    private:

    int codice;
    string nome;
    double prezzo;
    int quantita;
    bool disponibilita;



    public:

    
        Prodotto(){
            this->codice = 0;
            this->nome = "";
            this->prezzo = 0;
            this->quantita = 0;
            this->disponibilita = false;
        }

        Prodotto(int codice, string nome) {

            this->codice = codice;
            
            this->prezzo = 0;
            this->quantita = 0;
            this->disponibilita = false;

        }

        Prodotto( int codice, string nome, double prezzo, int quantita){
            this->codice = codice;
            this->nome = nome;
            this->prezzo = prezzo;
            this->quantita = quantita;
           if (quantita == 0){

            this->disponibilita = false;
           }
           else{
            this->disponibilita = true;
           }

        }

        int getCodice (){

            return this->codice;
        }
        double getPrezzo(){

            return this->prezzo;
        }
        string getNome (){

            return this->nome;
        }
        int getquantita (){

            return this->quantita;
        }
        bool getDisponibilita (){

            return this->disponibilita;
        }

        void setCodice(const int& codice){

            this->codice = codice;
        }

        void setPrezzo(const double& prezzo){
            if (prezzo > 0)
            this->prezzo = prezzo;
        }
        void setQuantita(const int& quantita){
            if (quantita > 0){
            this->quantita = quantita;
            this->disponibilita = disponibilita > 0;}
            else{
                this->disponibilita = quantita < 0;}
        }

        

        void setNome(const string& nome){

            this->nome = nome;
        }
        void print (ostream& dest) const {

            dest << "Nome: " << nome << " | " << this->codice << " | " << this->prezzo << " | "<< " | " << this->quantita << " | "<< this->disponibilita;

        }

        void aggiungiQuantita (){

            this->quantita = quantita++;
            this->disponibilita = this->quantita > 0;
        }

        void aggiungiQuantita (const int& quantita) {

            if (quantita <= 0){
                    cout << "errore" << endl;

            }
            else {

                this->quantita += quantita;
                this->disponibilita = this->quantita > 0;
            }

        }

        void rimuoviQuantita(){

            if (quantita == 0){

                cout << "errore" << endl;
            }
            else {

                quantita--;
                this->disponibilita = quantita > 0;
            }
        }

        void rimuoviQuantita(int quantita){

            if ( this->quantita == 0 &&  quantita > this->quantita ){

                cout << "errore" << endl;
            }
            
            else {

               this->quantita;
               this->disponibilita = quantita > 0;
            }
        }

        Prodotto operator+(const Prodotto& other)const{

            Prodotto result = *this;

            if (this->codice == other.codice ){

                result.quantita = this->quantita +other.quantita;
                return result;
                
            }
        }

        bool operator== (const Prodotto& other) {

            return this->codice == other.codice;
        }

        bool operator!= (const Prodotto& other) {

            return !this->codice == other.codice;
        }

        Prodotto operator++(int) {

            Prodotto result = *this;
            this->quantita++;
            return result;
        }
        Prodotto operator++(){

            this->quantita += 1;

            return *this;
        }
};
template <class T>

class Magazzino{

    private:

    T* data;
    int size;
    int cap;

    void enLarge(){

        int newCap = cap * 2;
        T* newData = new T[newCap];

        for (int i = 0; i < newCap; i++){
            newData[i] == this->data[i];
        }

        delete[] data;
        this->data = newData;
        this->cap = newCap;
    }

    public:

    Magazzino<T>(const Magazzino& other){

        this-data = new T[other.cap];
        this->cap = other.cap;
        this->size = other.size;

        for (int i = 0; i < size; i++){

            this->data[i] = other.data[i];
        }

    }

   const  Magazzino& operator== (const Magazzino& other){

        if (this == &other){

            return *this;
        }
        else{
        delete[]data;
         this-data = new T[other.cap];
        this->cap = other.cap;
        this->size = other.size;

        for (int i = 0; i < size; i++){

            this->data[i] = other.data[i];
        }
        }
   }
    ~Magazzino(){
        delete[]data;
    }
    Magazzino(int max){
        this->size = 0;
        this->cap = max;
        this->data = new T[cap];
    }

    void add(const T& x){

        if (this->size == cap){
            enLarge();
        }
        else{

            this->data[this->size++] = x;
        }
    }

    bool  remove (const T& x){

        for (int i = 0; i < size; i++){

            if(this->data[i] == x){

                for (int j = 0; j < len - 1; j++){

                    this->data[j] = this->data[j + 1]
                }
                size--;
                return true;

            }
           
           
        } 
        return false;
        
    }

    
};
int main(){

    Magazzino<Prodotto> n1(5);
    

    return 0;
}