#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100
int main (){


char str[MAX];
char str2[MAX];
char c;
int n = 0;
int conta1 = 0, conta2 = 0;
bool anagramma;
bool comune;


do {

    cout << "inserire la prima parola:";
    cin.getline(str, MAX - 1);

    if (str[0] == '$') {
        
        cout << "Addio!" << endl;
        break;
    }
    cout << "inserire la seconda parola:";
    cin.getline(str2, MAX - 1);

     anagramma = true;
     comune = false;
     n = strlen(str);
   


           
         if (strlen(str) == strlen(str2)) {   


        for (int i = 0; i < n; i++) {

                c = str[i];

                conta1 = 0;
                conta2 = 0;



            for (int j = 0; j < n; j++) {



                if (str[j] == c) {

                     conta1++;
                    
                }



            }

          

             for (int j = 0;  j < n; j++) {



                if (str2[j] == c) {

                     conta2++;
                     
                    

                }
                
            }

            

        
            if (conta1 != conta2) {


                anagramma = false;
                break;


            }
          
          


            

        }

        for (int i = 0; i < n; i++) {

            c = str[i];

                  for (int j = 0; j < n; j++) {



                if (str2[j] == c) {

                     comune = true;
                     break;
                    
                }
                  }
        }


            if (anagramma == true) {

                    cout << "Uno e' anagramma dell'altro" << endl;

            }

            if (comune == false) {

                    cout << "Non hanno niente in comune" << endl;
            }
           
           
         }
           
        
        

           
        
        
       
    }  
while (str[0] != '$');




    return 0;

}