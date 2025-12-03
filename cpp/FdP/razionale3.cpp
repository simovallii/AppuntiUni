#include <iostream>
using namespace std;

class Razionale {
private:
    int n;
    int d;

public:
    Razionale() : Razionale(1) {}

    Razionale(int num) : Razionale(num, 1) {}

    Razionale(int num, int den) {
        n = num;

        if (den == 0){

            throw string ("denominatore = 0");
        }
        
    }

    void semplifica(){

        int i = 2;

        while (n >= i && d >= i){

            if (n%i == 0 && d%i == 0) {

                n /= i;
                d /= i;
            }
            else {

                i++;
            }
        }
    }
    void read(istream& in) {
        int num, den;
        char sep;
        in >> num >> sep >> den;
        n = num;

        if (den == 0) {
           throw invalid_argument("denominatore non valido");
        }
       

        else if (sep != '/'){

            throw invalid_argument("separatore non valido");
        } 
        d = den;
    }

    void print(ostream& out) const { // metodi costanti, r non deve alterarsi
        out << n << "/" << d << endl;
    }

    Razionale somma(Razionale other) const {
        Razionale risultato;
        risultato.d = d * other.d;
        risultato.n = n * other.d + d * other.n;
        return risultato;
    }
    Razionale operator+(const Razionale & other) {

        return somma(other);
    }

    Razionale operator+ (int other) {

        return somma(Razionale(other, 1));
    }

    // operatore prefisso 
    Razionale operator++(){
        *this = *this + 1; // this->operator+ (1);
        return *this;
    }
    
    // op prefisso 
     Razionale operator++(int){
        Razionale result = *this;
        *this = *this + 1;

        return result;
    }



    int& operator[](int i){  // ritorno UN RIFERIMENTO alla zona di memoria

        if (i == 0)
            return n;
        else if (i == 1)
            return d;
        else {

            cout << "errore" << endl;
            return d;
        }
    }

   
};


ostream& operator<<(ostream &dest, const Razionale &r){

    r.print(dest);

    return dest;
}

istream& operator>>(istream &source, Razionale &r){

    r.read(source);

    return source;
}

   
int main() {

	Razionale r1(3, 3);
	Razionale r2(1, 4);

    Razionale r3 = r1 + r2;
   try{
    cin >> r1;
   }catch(invalid_argument a){

    cout << a.what();
   }
   
	
	return 0;
}