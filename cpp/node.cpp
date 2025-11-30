using namespace std;
#include<iostream>

struct node {

    int data;
    node* next;
};



void stampaRec(node* lst){
    if (lst == nullptr)
    {
        return;
    }
    else {
        cout << lst->data << " ";
        stampaRec(lst->next);
    }
}


void AddAtTheBegginning (node* &lst, int x) {

    node* new_node = new node;
    new_node->next = lst;
    new_node->data = x;
    lst = new_node;
}


void AddAtTheEnd(node* &lst, int x) {
    if (lst == nullptr)
        AddAtTheBegginning(lst, x);
    else {
        node* new_node = new node;
        new_node->data = x;
        new_node->next = nullptr;

        node* cursor = lst;
        while (cursor->next != nullptr)
            cursor = cursor->next;

        cursor->next = new_node;
    }
}

  
  node* crescente (node* lst) {

    node* cpy = new node;
    node* new_node = new node;
    bool crescente = true;

    if (lst == nullptr) {       // caso base
        return nullptr;
    }
    else {


        while (lst != nullptr) {

            
            
            cpy = lst;
            new_node = lst;
            

            while (cpy->next != nullptr) {

                cpy = cpy->next;

                if (cpy->data < new_node->data) {
                    
                    crescente = false;
                    break;

                }
                else {

                    crescente = true;
                    new_node = new_node->next;
                    
                }          
                

            }
            if (crescente == true) {
                
              
                break;
            }

            lst = lst->next;
        }

    }
    
    if (crescente == true) {

        return lst;
    }
    else {
        
        return nullptr;
    }
  }


int main (){




int x;
node* lst = nullptr;
node* risultato;

    while (true) {

        cout << "Inserisci un numero da aggiungere in coda. Inserire una lettera per terminare." << endl;
        cin >> x;

     if (cin.fail())
        {
            cout << "Addio! " << endl;
            break;
        }

        AddAtTheEnd(lst, x);

      
    }

    stampaRec(lst);

   
    
      risultato =   crescente(lst);

      if (lst == nullptr) {

        cout << endl;
        cout << " La lista inserita e' vuota" << endl;

      }

      else if (risultato == nullptr || lst->next == nullptr) {

        cout << endl;
        cout << " Non e' presente un numero da cui parte una lista crescente" << endl;

      }
      else{

        cout << endl;
        cout  << "il numero da cui parte una lista crescente e' " << risultato->data << endl;
        
        stampaRec(risultato);

      }

    return 0;
}
