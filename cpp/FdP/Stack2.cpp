#include<iostream>
using namespace std;

template<class T>
class Stack{

    private:
        T* a;
        int l;
        int cap;

        void enLarge(){
            this->cap = cap * 2;
            T* newA = new T[cap];

            for (int i = 0; i < l; i++){
                newA[i] = a[i];
            }
            delete[]a;
            this->a = newA;
        }
    public:

        ~Stack(){
            delete[]a;
        }

        Stack(const Stack<T>& other){

            this->l = other.l;
            this->cap = other.cap;
            this->a = new T[cap];
            
            for (int i = 0;i < l; i++){
                a[i] = other.a[i];
            }
            
        }
        Stack(){
            this->cap = 5;
            this->l = 0;
            this->a = new T[cap];
        }

        void push(T value){
            if (l == cap){
                enLarge();
            }
            a[l] = value;
            l++;
        }

        bool isEmpty(){
            return l == 0;
        }

        void pop(){
            if(isEmpty()){
                throw invalid_argument("stack vuoto");
            }
            else{
                l--;
            }
        }
        int size(){
            return l;
        }

        void print(ostream& dest)const {

            for (int i = 0; i < l; i++){
                dest << a[i] << " ";
            }
        }

        Stack<T>& operator=(const Stack<T>& other){

            if(this == &other){
                return *this;
            }
            else{
                delete[]a;
                this->a = new T[other.cap];
                this->cap = other.cap;
                this->l = other.l;

                for (int i = 0; i < l; i++){
                    a[i] = other.a[i];
                }
                return *this;
            }
        } 
};
template<class T>
ostream& operator<<(ostream& dest,const Stack<T>& other ){
    other.print(dest);

    return dest;
}

int main(){

    Stack<int> s1;

    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(5);

    s1.pop();
    s1.push(8);
    cout << s1;
    return 0;
}