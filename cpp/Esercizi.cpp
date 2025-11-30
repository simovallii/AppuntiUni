#include<iostream>
using namespace std;

struct node {

    int data;
    node* next;
};

void addAtTheBeginning (node* &lst, int dato) {

    node* new_node = new node;
    new_node->data = dato;
    new_node->next = lst;
    lst = new_node;
}

void AddAtTheEnd (node* &lst, int dato) {

    if (lst == nullptr) {
        addAtTheBeginning(lst, dato);
    }
    else {
        node* new_node = new node;
        new_node->data = dato;
        new_node->next = nullptr;

        node* cursor = lst;

        while (cursor->next != nullptr) {

            cursor = cursor->next;
        }
        cursor->next = new_node;
    }
}

void stampa (node* lst) {

    if (lst == nullptr){

        return;
    }
    else {

        cout << lst->data << " ";
        stampa(lst->next);
    }
}

node* remove_duplicates (node* &lst) {

    
    if (lst == nullptr) {
        return nullptr;
    }
    else { 

       node* cursor = lst;
        node* controllo = nullptr;
         node* new_lst = nullptr;
        bool v;

        while (cursor != nullptr) {

             controllo = new_lst;
             v = false;

             while (controllo != nullptr) {
                
                if (controllo->data == cursor->data) {
                    v = true;
                    break;
                }
                controllo = controllo->next;
             }

            if (!v) {
                AddAtTheEnd(new_lst, cursor->data);
            }
            cursor = cursor->next;
        }
        return new_lst;

    }
    
}

node* remove_negatives(node* lst) {

    if (lst == nullptr) {
        return nullptr;
    }
    else {

        node* cursor = lst;
        node* new_lst = nullptr;
        

        while (cursor != nullptr) {

            if (cursor->data > 0) {
                AddAtTheEnd(new_lst, cursor->data);
            }
            cursor = cursor->next;
        }
        return new_lst;
    }
}


int main (){

    node* lst = nullptr;

    AddAtTheEnd(lst, 1);
    AddAtTheEnd(lst, -2);
    AddAtTheEnd(lst, 2);
    AddAtTheEnd(lst, -4);
    AddAtTheEnd(lst, 5);

    node* lst2 = remove_negatives(lst);

    stampa(lst);
    cout << endl;
    stampa(lst2);

    return 0;
}