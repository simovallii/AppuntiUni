using namespace std;
#include<iostream>
#include<string>

class StringSet {

    private:

        int l;
        string s[100];


    public:
    StringSet(){

        this->l = 0;
        
    }
    StringSet(string s[], int l){

        this->l = 0;
        
      for (int i = 0; i < l; i++) {

        this->add(s[i]);
      }
    }

    void add(string x){
        if (!contains(x)) {

            if (l == 99) {
                cout << "array Pieno" << endl;
            }
            else {
                this->s[l] = x;
                l++;
            }
        }
    }
    bool contains (const string& elem)const {

        for (int i = 0; i < l; i++){

            if (this->s[i] == elem) {

                return true;
            }
            return false;
        }
    }
    int size(){

        return this->l;
    }

    StringSet operator+(StringSet& other ){
        
        StringSet result;
        if (this->l + other.l > 100 ){
            

            return result;
        }
        else {

            for (int i = 0; i < this->l; i++) {
                result.add(this->s[i]);
            }
            for (int i = 0; i < other.l; i++) {
                result.add(other.s[i]);
            }

        }
    }

    void print (ostream& dest) const{
    dest << "{";
        for (int i = 0; i < l; i++) {
            if(i != l - 1 ){
            cout<< s[i] << ", ";
            }
            else{
                cout << s[i];
            }
        }
    
    dest << "}" << endl;
    }

    void remove (const string& s){

            for (int i = 0; i < l;i++){

                if (s == this->s[i]){

                    for (int j = i; j < l - 1; j++){

                        this->s[j] = this->s[j + 1];
                    }
                    l--;
                    break;
                }
            }
            throw invalid_argument("stringa non trovata");
    }

    void operator-(const string &s){

        this->remove(s);
    }
};


    ostream& operator<< (ostream& dest, StringSet& other){

         other.print(dest);
        return dest;
}

int main(){

    string s[] = {"il", "gatto", "con", "gli", "stivali"};
   char* s3 = "dio";
   cout << s3;
    StringSet s1(s, 5); 
try{
    s1 - "stivali";
}catch(const exception& s){
     cout << s.what() << endl;
}
    cout << s1;
    
    return 0;
}