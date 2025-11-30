#include <iostream>
using namespace std;

class Razionale {
	private:
		int n;
		int d;
		
		
	public:

	Razionale() : Razionale(1,1){};
	Razionale(int n, int d){

		this->n = n;
		this->d = d;
	}
	

		Razionale somma(const Razionale &other) {
			Razionale risultato;
			risultato.d = d * other.d;
			risultato.n = n * other.d + d * other.n;
			return risultato;
		}
		void leggi() {
			int num, den;
			char sep;
			cin >> num >> sep >> den;
			n = num;

			if (den == 0) {
				cout << "Errore: denominatore uguale a zero" << endl;
				d = 1;
			} else
				d = den;
			return;
		}

		void stampa() {
			cout << n << "/" << d << endl;
		}

		

		Razionale operator+(const Razionale & other) {

			return somma(other);
		}

		Razionale operator+ (int other) {

			return somma(Razionale(other, 1));
		}
	}
;

Razionale operator+ (int i, Razionale other) {

	return other + 1;
} 


int main() {
	Razionale r1(3, 4);
	


	Razionale r2(1, 4);

	Razionale r3 = r1 + r2;
	
	r3.stampa();

	
	
	return 0;
}