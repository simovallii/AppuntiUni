using namespace std;
#include<iostream>
 struct elem{

            int data;
            elem* next;
        };
class list {

    private: 

       elem* l;
       int n;

    public:

    list(const list& other){

        this->l = nullptr;
        
        elem* t = other.l;
        this->n = other.n;
     while (t != nullptr){

        this->add_last(t->data);
        t = t->next;
        }

   
    }
    ~list(){ 
        
       
        while (n!= 0){ 
         elem* t = this->l;
         this->l = this->l->next;
         delete t;
         n--;
        }
       
    }
    list(){
            this->l = nullptr;
            this->n = 0;
    }

    bool isEmpty (){
        return this->n == 0;
    }
    void add_first(int x){

        elem* t = new elem;
        t->data = x;
        t->next = this->l;
        this->l = t;
        n++;
    }

    void add_last (int x){

        if (l == nullptr){
         add_first(x);
        }
        else {

            elem* t = new elem;
            elem* t2 = this->l;
            t->data = x;
            t->next = nullptr;

            while (t2->next != nullptr){

                t2 = t2->next;
            }
            t2->next = t;
            
            n++;

        }
    }
    int remove_first(){

        int x = this->l->data;
        elem* t = this->l;
       
        this->l = this->l->next;
        delete t;
        n--;
        return x;
        
    }


    int   remove_last(){

       int x;
        elem* t = this->l;
        
        while (t->next->next != nullptr){

            t = t->next;
        }
        x = t->next->data;
        delete t->next;
        t->next = nullptr;
        n--;
       return x;
    }
    int dim(){
        return n;
    }
void print(ostream& dest)const{

    elem* t = this->l;
    while(t != nullptr){

        dest << t->data;
        t = t->next;
    }
}

const list& operator= (const list& other){

    this->~list();
    this->n = other.n;

    elem* t = other.l;
    if (this == &other){

        return *this;
    }
    else{

    while (t != nullptr){

        this->add_last(t->data);
        t = t->next;
    }

    return *this;
}
}


};

ostream& operator<<(ostream& dest, const list& other){

    other.print(dest);

    return dest;
}

int main(){

    list l1;
    l1.add_last(1);
    l1.add_last(2);
    l1.add_last(3);
    
   cout << "l1: " ;
   cout << l1;
   cout << endl;
    list l2(l1);
    
   
    cout << "l2 : ";
    cout << l2;
    
    return 0;
}