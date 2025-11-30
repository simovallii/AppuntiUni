#include<iostream>
using namespace std;

template<class K, class V>
 class Pair{
    private:
        K first;
        V second;

    public:

        K getFirst() const{
            return this->first;
        }

        V getSecond() const{
            return this->second;
        }

        void setFirst(K key){
            this->first = key;
        }

        void setSecond(V value){
            this->second = value;
        }

};

    template<class K, class V>
    class Map{

        private:
        Pair<K,V>* container;
        int cap;
        int l;

        void enLarge(){

            this->cap =  cap * 2;
            Pair<K,V>* newContainer = new Pair<K,V>[cap];

            for(int i = 0; i < this->l; i++){
                newContainer[i] = this->container[i];
            }
            delete[] container;
            this->container = newContainer;
        }
        public:

             ~Map(){
                delete[]container;
             }

             Map(const Map& other){
                this->l = other.l;
                this->cap = other.cap;
                this->container = new Pair<K,V>[cap];

                for(int i = 0; i < l; i++){
                    this->container[i] = other.container[i];
                }
             }
            Map(){
                this->cap = 5;
                this->l = 0;
                this->container = new Pair<K,V>[cap];
            }

            void insert(const K& key, const V& value){

                if(this->l == cap)
                    enLarge();
            
             for(int i = 0; i < this->l; i++){
             if(container[i].getFirst() == key){
                       container[i].setSecond(value);
                        return;
                    }
                }
                

                container[l].setFirst(key);
                container[l].setSecond(value);
                l++;
            }

            bool contains(const K& key) const{

                for(int i = 0; i < this->l; i++){
                    if(this->container[i].getFirst() == key)
                        return true;
                } 
                return false;
            }
            bool isEmpty() const{
                return l == 0;
            }

            void remove(const K& key){
                if(!contains(key))
                    throw invalid_argument("chiave non presente");
                
                for( int i = 0; i < this->l; i++){
                    if(container[i].getFirst() == key){
                        for(int j = i; j < this->l - 1; j++){
                            container[j] = container[j + 1];
                        }
                        l--;
                        return;
                    }
                }
            }

            int size()const{
                return this->l;
            }

            Map& operator=(const Map& other){
                if(this == &other)
                    return *this; 
                delete[] this->container;
                this->l = other.l;
                this->cap = other.cap;
                this->container = new Pair<K,V>[cap];

                for(int i = 0; i < l; i++){
                    this->container[i] = other.container[i];
                }

                return *this;
            }

    };
int main(){}