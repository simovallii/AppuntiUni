#include<iostream>
using namespace std;

template<class T>
class Set{

    private:
        T* a;
        int l;
        int cap;

        void enLarge(){

            this->cap = cap* 2;
            T* newA = new T[cap];
            for(int i = 0; i < l; i++){
                newA[i] = a[i];
            }
            delete[]a;
            this->a = newA;
        }
    public:

        ~Set(){
            delete[]a;
        }
        Set(){
            this->l = 0;
            this->cap = 5;
            this->a = new T[cap];
        }

        Set(const Set<T>& other){
            this->l = other.l;
            this->cap = other.cap;
            this->a = new T[cap];

            for(int i = 0; i < l; i++){
                a[i] = other.a[i];
            }
        }

        Set& operator=(const Set& other){

            if (this == &other){
                return *this;
            }
            else{
                delete[]a;
                this->l = other.l;
                this->cap = other.cap;
                this->a = new T[cap];
    
                for(int i = 0; i < l; i++){
                    a[i] = other.a[i];
                }
                return *this;
            }
        }
        void add(T value){

            if (l == cap){
                this->enLarge();
            }

            if(contains(value)){
                throw invalid_argument("elemento non valido");
            }
            else{

            a[l] = value;
            l++;

            }

        }

        int size() const {

            return l;
        }

        bool contains(const T &value){

            for(int i = 0; i < l; i++){
                if (a[i] == value)
                    return true;
            }
            return false;
        }

        Set<T> findInRange(const T& min, const T& max){

                int c = -1;
                int q = -1;

                for (int i = 0; i < l; i++){
                    if (a[i] == min){
                        c = i;
                    }
                    else if (a[i] == max){
                        q = i;
                    }
                }

                Set<T> result;
                for (int j = c; j <= q; j++ ){

                    result.add(a[j]);
                }
                return result;
        }

        void print(ostream& dest) const {

            for (int i = 0; i < l; i++){
                dest << a[i] << " ";
            }
        }
    };
    template <class T>
    ostream& operator<<(ostream& dest, const Set<T>& other){
        
        other.print(dest);
        return dest;
    }
    int main(){

        Set<int> s1;
        s1.add(2);
        s1.add(3);
        s1.add(4);
        s1.add(5);
        s1.add(6);
        s1.add(7);
        s1.add(8);

        cout << s1;
        return 0; 
    }