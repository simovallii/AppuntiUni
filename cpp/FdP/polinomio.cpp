using namespace std;
#include<iostream>


class Polinomio{

    private:

    int* arr;
    int l;


    public:

    ~Polinomio(){
        delete []arr;
    }

    Polinomio() : Polinomio(nullptr, 0){};
    Polinomio(int a[],int l){

       this->l = l;

       if (l != 0){

        this->arr = new int[l];
        for (int i = 0; i < l; i++){

            this->arr[i] = a[i];
        }
       }
       else{
        this->arr = nullptr;
       }
    }

    int getDegree(){

        return l - 1;
    }

    Polinomio operator*(const Polinomio& other) const {

       Polinomio result;
       result.l = this->l + other.l ;

       result.arr = new int[result.l]();
       

       for (int i = 0; i < this->l; i++){
        for (int j = 0; j < other.l; j++){
           
            result.arr[i + j] += arr[i]  * other.arr[j];
        }
       }
     
       return result;
    }

    void print(){
       

            cout << this->arr[0] << " + ";

        for (int i = 1; i < l; i++){

         if (arr[i] != 0 || arr[i + 1] != 0){
            if (i < l - 1 ){
           cout << this->arr[i] << "x^"<<i  << " + ";
            }
            else {

                cout<< this->arr[i] << "x^" << i;
            }
         }
    } 
}
    Polinomio(const Polinomio& other){
        this->l = other.l;
        this->arr = new int[this->l];
        
        for (int i = 0; i < l; i++){
            arr[i] = other.arr[i];
        }
    }

    const Polinomio& operator=(const Polinomio& other){

        this->~Polinomio();
        this->l = other.l;
        this->arr = new int[this->l];
        
        for (int i = 0; i < l; i++){
            arr[i] = other.arr[i];
        }
        
        return *this;
    }

   
};
int main(){

    int a[2] = {0, 1};
    int b[2] = {2, 3};

    Polinomio p1(a, 2);
    Polinomio p2(b, 2);
   
    Polinomio p3;
    
    p3 = p2;
     p3.print();
    return 0;
}