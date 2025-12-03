#include<iostream>
using namespace std;

class Data {

    private:
        int g;
        int m;
        int a;

    
   
    public:
    int getG() const
    {
        return this->g;
    }


    void setG(int g)
    {
        this->g = g;
    }


    int getM() const
    {
        return this->m;
    }


    void setM(int m)
    {
        this->m = m;
    }


    int getA() const
    {
        return this->a;
    }


    void setA(int a)
    {
        this->a = a;
    }

        Data() : Data(1, 1, 1970) {};

        bool isValid(int g, int m, int a)
        {

            return g > 0 && g < 31 && m > 1 && m < 13;
    }
    Data (int g, int m, int a) {

        if (isValid(g,m,a)){
        this->g = g;
        this->m = m;
        this->a = a;
        }
        else {
            this->g = 1;
            this->m = 1;
            this->a = 2001;
        }
    }
    // > < == ++ >> <<

    bool operator<(const Data &other)const{

        if (this->a != other.a){

            return this->a < other.a;
        }
        else if (this->m != other.m){

            return this->m < other.m;
        }
        else if (this->g != other.g){

            return this->g < other.g;
        }

    }

    bool operator>(const Data &other)const{

       return other < *this;

    }

    bool operator== (const Data &other )const {

        return this->a == other.a && this->m == other.m && this->g == other.g;
    }

    bool operator!=(const Data& other){

        return *this == other;
    }

    Data operator++(){

            this->g = this->g + 1; //metterlo aposto

            return *this;
    }
};

ostream& operator<< (ostream & dest, const Data & d) {

    dest << d.getG() << "/";
    dest << d.getM() << "/";
    dest << d.getA();

    return dest;
}

istream& operator>> (istream & source, Data & d) {

    int giorno, mese, anno;
        source >> giorno;
        source >> mese;
        source >> anno;

        d.setG(giorno);
        d.setM(mese);
        d.setA(anno);

        return source;
}

int main(){

    Data d(2, 6, 2000);
    cin >> d;
    cout << d;


    return 0;
}