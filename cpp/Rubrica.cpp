#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100

struct persona {

    char nome[MAX];
    char cognome[MAX];
    char cellulare[MAX];
};
int main() {

 
persona v[MAX];
persona contatto;
int scelta = 0;
int n = 0;




  
do 
{

    cout << "*** Rubrica ***" << endl;
    cout << "1 - Visualizza rubrica." << endl;
    cout << "2 - Inserisci contatto." << endl;
    cout << "3 - Cancella contatto." << endl;
    cout << "4 - Esci." << endl;
         
        
         
         
         cin >> scelta;
         
         
      if (scelta >= 1 && scelta <= 4){

       switch (scelta) {

            case 1 :

            for (int i = 0; i < n; i++) {
              

               cout << "Nome : " << v[i].nome << endl;
                cout << "Cognome : " << v[i].cognome << endl;
                 cout << "Cellulare : " << v[i].cellulare << endl;
                 cout << endl;
              
            }
            if (n == 0) {
              
              cout << endl;
              cout << "Non ci sono contatti " << endl;
              cout << endl;
            }

            break;

            case 2 :

                cout << "inserisci nome nuovo contatto " << endl;
                cin.ignore();
                   cin.getline(contatto.nome, MAX - 1);

                cout << "inserisci cognome nuovo contatto " << endl;
                   cin.getline(contatto.cognome, MAX - 1);

               do {

            
                cout << "inserisci cellulare nuovo contatto" << endl;
                   cin.getline(contatto.cellulare, MAX - 1);
         
         if (strlen(contatto.cellulare) != 10) {

               cout << endl;
                cout << "Numero non valido, reinserire numero." << endl;
                cout << endl;
         }

   }
            while (strlen(contatto.cellulare) != 10);


                v[n] = contatto;

               
                n++;
                
                cout << endl;
                cout << "contatto salvato correttamente " << endl;
                cout << endl;


            break;

            case 3 :  

            persona nome;
            persona cognome;
            int conta = 0;
            int conta2 = 0;
            
            
            if ( n == 0) {

               cout << endl;
               cout << "Non ci sono contatti da eliminare" << endl;
               cout << endl;

               break;
            }


            cout << "Inserisci il nome del contatto da eliminare: ";
            cin.ignore();
            cin.getline(nome.nome, MAX - 1);
            cout << "Inserisci cognome da eliminare: " ;
            cin.getline(cognome.cognome, MAX - 1);

            
            


            for ( int i = 0; i < n; i++)
            {

                  conta = strcmp(nome.nome,v[i].nome);
                  conta2 = strcmp(cognome.cognome, v[i].cognome);
                 

                  if (conta == 0 && conta2 == 0) {
                   
                     for (int j = i; j < n; j++) {

                        v[j] = v[j + 1];

                     }
                     n = n - 1;

                     cout << endl;
                     cout << "Contatto cancellato!"<< endl;
                     cout << endl;

                     break;
                  }
                  
            }
            if (conta != 0 || conta2 != 0) {
               
               cout << endl;
               cout << "NON e' stato trovato nessun contatto con questo nome o cognome." << endl;
               cout << endl;
            }

            

            break;

            
         }
      }
      else {
         cout << "Numero non valido" << endl;
      }

        

}
while (scelta != 4);

cout << "Addio!";




    return 0;
}