#include<iostream>
using namespace std;

template<class T>
class Set{

    private:
        T* a;
        int cap;
        int top;

        void enLarge(){
            this->cap = cap*2;
            T* newA = new T[cap];

            for (int i = 0; i < top;i++){
                newA[i] = a[i];
            }

            delete[]a;
            this->a = newA;
        }
    public:

    Set(){
        this->cap = 5;
        this->top = 0;
        this->a = new T[cap];
    }

    bool contains(const T& value){
        for(int i = 0; i < top; i++){
            if(this->a[i] == value)
                return true;
        }
        return false;
    }
    void add(const T& elem){
        if(this->cap == top){
            enLarge();
        }
        
        if(!contains){
            a[top] = elem;
            top++;
        }else{
            throw invalid_argument("elemento non valido");
        }
       
        
    }

    int size(){
        return top;
    }
};
template<class T>
Set<T> operator-(const Set<T>& other){
    Set<T> result = new Set<T>();

    
}
int main(){

}