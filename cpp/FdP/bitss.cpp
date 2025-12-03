#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int n = 0;
    int b[n];
    int scelta;
    int decimale = 0;
    int overflow = 0;

    do {
        cout << "inserisci n bit" << endl;
        cin >> n;
        if ( n < 2) {
            cout << "input errato" << endl;
        }
}
    while (n < 2);

    for (int i = n - 1; i >= 0; i--) {

        cout << "inserisci bit n " << i << endl;
        cin >> b[i];
    }



    do {
       cout << " Operazione: 0) Stampa in binario. 1)Converti in decimale. 2) Somma." << endl;
    cin >> scelta; 

    if (scelta < 0 || scelta > 2  ) {

        cout << "input errato" << endl;
    }
    }
    while (scelta < 0 || scelta > 2);

    
    
    if (scelta == 0){
      for (int i = n - 1; i >= 0; i--) {

        cout << b[i];
    }
    }

    if ( scelta == 1 )
    {

       if (b[n-1] == 1) {

            decimale = pow(2, n - 1) * (- 1) ;
        }  
        
           for ( int i = n - 2 ; i >= 0 ; i--) {

            

                decimale += pow(2, i) * b[i];
            

        }
       
        cout << decimale;
    }

    if (scelta == 2)
    {
        for (int i = 0; i < n; i++) {
            
            
            b[i] += 1;

       
        
        
         if ( b[i] == 1) {

              
                break;
            }
        else if (b[i] > 1) {

                b[i] = 0;
                
            }
        

       if (b[i] == 0) {

                overflow++;
            }
        }
        
        if (overflow == n - 1)
        {
            cout << "overflow!" << endl;
        }
        else if (b[n - 1] <= 1) {
        for (int i = n - 1; i >= 0; i--) {

        cout << b[i];
    } 
        }
        
    }


    
  return 0;
}