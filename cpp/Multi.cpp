#include <iostream>
using namespace std;

template<class T>
class  MultiSet {
private:
    T* a;
    int l;
    int cap;

    void enLarge() {
        cap = cap * 2;
        T* newA = new T[cap];
        for (int i = 0; i < l; i++){
        newA[i] = a[i];
        }

        delete [] a;
        this->a = newA;
    }
public:
    
    ~MultiSet(){
        delete[]a;
    }

    MultiSet(const MultiSet &other){
        
        this->cap = other.cap;
        this->l = other.l;
        this->a = new T[cap];

        for (int i = 0; i < l; i++){
            a[i] = other.a[i];
        }
    }

    MultiSet& operator=(const MultiSet &other){

        if (this == &other){
            return *this;
        }
        delete[]a;
        this->cap = other.cap;
        this->l = other.l;
        this->a = new T[cap];
    
            for (int i = 0; i < l; i++){
                a[i] = other.a[i];
            }
            return *this;
    }
    MultiSet() {
        this->l = 0;
        this->cap = 5;
        this->a = new T[cap];
    }

    void add(const T& x) {
        if (l == cap)
            enLarge();
        a[l] = x;
        this->l++;
    }

    void remove(const T& x){
        bool v = false;
        for(int i = 0; i < l; i++){
            if (a[i] == x){
                v = true;
                for (int j = i; j < l - 1; j++){
                    a[j] = a[j + 1];
                   
                }
                i--;
                l--;
            }
        }

        if (v == false)
            throw invalid_argument("numero non presente");
        
    }

    bool isEmpty(){
        return l == 0;
    }

    int cardinality(const T &elem){

        int c = 0;

        for (int i = 0; i < l; i++){
            if(a[i] == elem)
                c++;
        }
        return c;
    }

    void print(ostream &dest)const  {
        for (int i = 0; i < l; i++){
            dest << a[i] << " ";
        }
    }
};
template <class T>
ostream& operator<<( ostream &dest, const MultiSet<T> &other){

    other.print(dest);
    return dest;
}

int main() {
    MultiSet<int> m1;
    m1.add(5);
    m1.add(6);
    m1.add(5);
    m1.add(6);
    m1.add(5);
    m1.add(6);
    m1.add(5);
    m1.add(6);

  

    MultiSet<int> m2(m1);
    
    cout << m2;
    return 0;
}