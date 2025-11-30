using namespace std;
#include<iostream>

template <typename T>

class Stack{

    // push pop empty 

    private:

        T* a;
        int top;
        int cap;

        void enLarge(){

            T* tmp = new T [cap * 2];

            for (int i = 0; i < cap; i++){
                tmp[i] = this->a[i];
            }
            this->cap = cap*2;
            delete[] a;
            this->a = tmp;
        }

    public:

    ~Stack(){
            delete[]a;  // distruttore 
        }
        Stack(){

            this->a = new T[5];
            this->top = 0;
            this->cap = 5;
        }

        bool isEmpty() const {

            return top == 0;
        }

        void push (T x){

            if (top == cap){

                enLarge();
            }
            this->a[top] = x;
            top++;

        }

        T pop(){

            if (isEmpty()){
                throw out_of_range("array vuoto");
            }
            top--;
            return this->a[top];
        }

        T getTop() const{
            if (isEmpty()){
                throw out_of_range ("array vuoto");
                
            }
            return this->a[this->top - 1];
        }

        Stack(const Stack& other){

            
            this->top = other.top;
            this->cap = other.cap;
            this->a = new T[other.cap];
            for (int i = 0; i < other.top; i++){
 
               a[i] = other.a[i];
            }
             
        }
        void print (ostream& dest) const{

            for (int i = 0; i < top; i++){

                dest << this->a[i];
            }
            
        }

    

       const Stack& operator= (const Stack& other){

        delete []a;

        this->top = other.top;
        this->cap = other.cap;

        a = new T[other.cap];
        for (int i = 0; i < other.top; i++){

            a[i] = other.a[i];
        }
        return *this;
       }
       
};

template <typename T>
ostream& operator<<(ostream& dest, const Stack<T>& other) {

    other.print(dest);
    return dest;
}

int main (){

    Stack<int> S1;
    S1.push(4);
    S1.push(4);
    S1.push(4);
    
    cout << S1;
    return 0;
}