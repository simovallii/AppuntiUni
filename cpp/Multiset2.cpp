using namespace std;
#include<iostream>
template <typename T>
class Multiset{

    private:  

        T* a;
        int l;
        int cap;
        
        void enLarge (){

            T* tmp = new T[cap * 2];

            for (int i = 0; i < l; i++){

                tmp[i] = this->a[i];
            }
            this->cap =this-> cap * 2;
            delete[]a;
            this->a = tmp;
        }

    public:

    ~Multiset(){
        delete[]a;
    }

    Multiset() {
        this->l = 0;
        this->cap = 1;
        this->a = new T[cap];
    }

    Multiset(T arr[], int l){

      
        this->l = l;
        this->a = new T[l];
        
        for (int i = 0; i < l; i++){

            this->a[i] = arr[i];
        }

         this->cap = l;
    }

    void add(T x){
       if (l == cap){
        this->enLarge();
       }
       
       this->a[l] = x;
       l++;
       
       
    }

    bool contains (const T& x) const{


            if (l == 0){

                return false;
            }
            else{

                for (int i = 0; i < l; i++){

                    if(a[i] == x){

                        return true;
                    }
                }
                return false;
            }
        
    }

    void remove(const T& x){

        T* tmp = new T[l];
        
        int j = 0;

        for (int i = 0; i < l; i++){
            if (a[i] != x){

                tmp[j] = a[i];
                j++;
               
            }
        }
        if (j == 0){

            throw invalid_argument("nessun elemnto trovato");
        }
        else{

        this-> l = j;
        delete[]a;
        this->a = tmp;
    }
    }

   int multiplicity ( const T& x){
    int c = 0;
        for (int i = 0; i < l; i++){

            if (a[i] == x){

                c++;
            }
        }
        return c;
   }

   Multiset operator+(const Multiset& other){
        
        Multiset<T> Result;
         Result.l = l + other.l;
         Result.a = new T[Result.l];
         Result.cap = other.l + this->l;
       

        for (int i = 0; i < l; i++){

            Result.a[i] = a[i];
        } 
        
        int j = this->l;
        for (int i = 0; i < other.l; i++){

            Result.a[j] = other.a[i];
            j++;
        }

        return Result;
   }

   const Multiset& operator=(const Multiset& other){

    if (this == &other){

        return *this;
    }
    else {

    
    delete[]a;
    this->l  = other.l;
    this->a = new T[other.cap];
    this->cap = other.cap;

    for (int i = 0; i < l; i++){

        a[i] = other.a[i];
    }

    return *this;
}
   }


    void print(){

        for (int i = 0; i < this->l; i++){

            cout << this->a[i];
        }
    }
};
int main(){

  
    Multiset<int> m1;
    Multiset<int> m2;
    m1.add(7);
    m1.add(7);
    m1.add(7);
    m1.add(8);
    m1.add(5);

    m2.add(7);
    m2.add(7);
    m2.add(7);
    m2.add(8);
    m2.add(5);
    
    Multiset<int> m3;

    m3 = m1 + m2;
    
    m3.print();
    return 0;
}