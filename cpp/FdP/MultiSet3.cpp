#include<iostream>
using namespace std;

template <class T>
class MultiSet{

    private:
         T* elements;
         int size;
         int cap;

         void enLarge(){
            this->cap = cap * 2;
            T* elem = new T[cap];

            for (int i = 0; i < size; i++){
                elem[i] = elements[i];
            }
            delete[]elements;
            elements = elem;
         }
    public:

        ~MultiSet(){
        delete[] elements;
    }
        MultiSet(){

            this->elemets = new T[5];
            this->cap = 5;
            this->size = 0;
        }

        int size(){
            return size;
        }
        bool isEmpty(){
            return this->size == 0;
        }

        void add(T value){
            if (size == cap)
                Enlarge();
            elements[size] = value;
            size++;
        }

        int cardinality(const T &value){
            
            int c = 0;

            for(int i = 0; i < size; i++){
                if(this->elements[i] == value){
                    c++;
                }
            }
            return c;
        }
        bool contains(T value){
            for(int i = 0; i < size; i++){
                if(this->elements[i] == value){
                    return true;
                }
            }
            return false;
        }

        MultiSet<T> intersection(const Multiset<T>& other) const {
            MultiSet<T> result;

            for (int i = 0; i < size; i++){
                for (int j = 0; j < oher.size;j++){
                    if(this->elements[i] == other.elements[j] && !result.contains(this->elements[i]))
                        result.add(this->elements[i]);
                }
            }

            return result;
        }
};

template <class T>
ostream& operator<< (ostream& os, const MultiSet<T> &ms){
   >// print(os);

}
int main(){

    return 0;
}