#include <iostream>
using namespace std;
int main (){

    char a;
    cin >> a;

    if (a >= 97)
    {
        a = a - 32; 
    }
    else
    {
        a = a + 32;
    }
   
        cout << a << endl;
    return 0;
}