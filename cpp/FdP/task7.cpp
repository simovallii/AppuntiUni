using namespace std;
#include<iostream>
#include<cstring>
#define MAX 1000

int main() {

    int* arr[MAX];
   int x = 0;
   int dim = 0;
   int q = 0;


      
   while (x >= 0) {
       
      
    
        cout << "inserisci un numero" << endl;
        cin >> x;

    if (x >= 0) {
      
    
      bool trovato = false;
      
    
    for (int i = 0; i < q; i++) {

        if (*arr[i] == x) {

          trovato = true;
          break;
        }

    }

   

    if (!trovato) {

      int* p = new int();
     *p = x; 
     arr[q] = p;
      dim++;
    }

    else if (trovato) {

      for (int i = 0; i < q; i++) {
        if (*arr[i] == x) {
          arr[q] = arr[i]; 
        }
      }
      
    }

      q++; 
    }
    else{
      break;
    }
    
    }
    
    for (int i = 0; i < q; i++) {

      cout << *arr[i] << " ";
    }

      cout << endl;
      cout << "il numero di variabili allocate e' " << dim << endl;
 

  for ( int i = 0; i < dim; i++) {

    if (arr[i] != nullptr){

       delete arr[i];
       arr[i] = nullptr;

    }
  }


    return 0;
}