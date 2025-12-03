using namespace std;
#include<iostream>

class Persona{

    protected:
        string nome;
        string cognome;
        string indirizzo;

    public:


        Persona(string nome, string cognome, string indirizzo){

            this->nome = nome;
            this->cognome = cognome;
            this->indirizzo = indirizzo;
        }

        void print(ostream& out){

            out << "nome: " << this->nome << ", cognome: " << this->cognome << ", indirizzo: " << indirizzo<< endl;
        }

        bool operator< (const Persona& other)const {

            if(this->cognome == other.cognome)
                return this->nome < other.nome;
            return this->cognome < other.cognome;
        }
};

class Studente: public Persona{

        private:
            string matricola;
            string mail;

        public:

            Studente(string nome, string cognome, string indirizzo, string matricola) : Persona(nome, cognome, indirizzo){

                this->matricola = matricola;
                this->mail = nome + cognome +"@gmail.com";
            }

            void print(ostream& out){
                Persona:: print(out);
                out << "matricola: " <<  matricola << ",indirizzo: " << indirizzo << ", mail:" << mail <<endl;
            }

           bool operator< (const Studente& other){

                return this->matricola < matricola;
           }
           
};

int main(){

    Studente p1("Simone", "Valli", "Via collodi 12", "377905");
    p1.print(cout);

    
    return 0;
}