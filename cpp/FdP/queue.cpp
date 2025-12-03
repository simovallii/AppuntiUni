#include<iostream>
using namespace std;


template<class T>
class Queue{

    private:

        T* data;
        int size;
        int cap;

        void enLarge(){

            int newCap = cap * 2;
            T* newData = new T[newCap];
    
            for (int i = 0; i < newCap; i++){
                newData[i] == this->data[i];
            }
        }
        public:

        Queue(int cap){

            this->size = 0;
            this->cap = cap;
            T* data = newT[cap];
        }

        void add(const T x& x){

            if (this->size == this->cap){

                enLarge();
            }
            else{
                this->data[this->size++] = x;
            }
        }
};
int main(){

    return 0;
}