using namespace std;
#include<iostream>
#include<cstring>

#define MAX 100
int main (){


    int* v[MAX];

    int* p = new int;

    cout << "inserisci numero da allocare" << endl;
    cin >> *p;

    v[0] = p;

    cout << *v[0];

    delete p;

    
    
    




   return 0;

    }
    