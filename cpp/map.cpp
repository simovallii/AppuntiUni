#include <iostream>
using namespace std;
#include<vector>
#include<set>

template<class K, class V>
class Pair {
private:
    K first;
    V second;
public:

    K getKey() const {
        return this->first;
    }

    V& getValue() {
        return this->second;
    }

    void setValue(V v) {
        this->second = v;
    }

    void setKey(K k) {
        this->first = k;
    }
};

template<class K, class V>
class Map {
private:
    vector<Pair<K, V>> container;

   

public:


    void add(const K& k, const V& v){

        this->container->push_back(Pair<K, V>(k, v));
    }

   set<V> values(){

    set<V> result;

    for (Pair<K, V> e : container){

        result.insert(e.getValue());
    }

    return result;
}

   set<K> keys(){

    
    set<K> result;

    for (auto e : container){

        result.insert(e.getKeys());
    }

    return result;
   }

   void print(){

    for (Pair<V, K> e : container){

        cout << e.getKey << " " << e.getValue << endl;
        cout << endl;

    }
   }
};



int main() {
    Map<int, string> map;
   
    return 0;
}