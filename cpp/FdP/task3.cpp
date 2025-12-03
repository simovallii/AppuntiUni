#include<iostream>
using namespace std;
int main () {

    int n = 0;
    int q = 0;
    int i, j;

    do {
        cout << "inserisci un numero:";
        cin >> n;
        if (n <= 0)
        {
            cout <<"input errato" << endl;
        }
    }
    while ( n <= 0);

for (i = 1; i <= n; i++) {

    for (j = 1; j <= n; j++) {
        
       q = q + i;
       cout << q;
       cout << " ";

       if (j == n) {
        q = 0;
       }
    }
    cout << endl;
}
return 0;
}