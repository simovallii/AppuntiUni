#include <iostream>
#include <fstream>
using namespace std;

struct node {
    int data;
    node* next;
};


void printIt(node* lst) {
    while (lst != nullptr) {
        cout << lst->data << " ";
        lst = lst->next;
    }
    cout << endl;
}

void printRec(node* lst) {
    if (lst == nullptr)
        return;
    else {
        cout << lst->data << " ";
        printRec(lst->next);
    }
}

void addAtTheBeginning(node* &lst, int x) {
    node* new_node = new node;
    new_node->next = lst;
    new_node->data = x;
    lst = new_node;
}

void addAtTheEnd(node* &lst, int x) {
    if (lst == nullptr)
        addAtTheBeginning(lst, x);
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

void removeAtTheBeginning(node* &lst) {
    if (lst == nullptr) {
        cout << "Non posso rimuovere elementi da una lista vuota" << endl;
        return;
    }

    node* new_lst = lst->next;
    delete lst;
    lst = new_lst;
}

void removeAtTheEnd(node* &lst) {
    if (lst == nullptr) {
        cout << "Non posso rimuovere elementi da una lista vuota" << endl;
    } else if (lst->next == nullptr) {
        removeAtTheBeginning(lst);
    } else {
        node* cursor = lst;
        while (cursor->next->next != nullptr) {
            cursor = cursor->next;
        }

        delete cursor->next;
        cursor->next = nullptr;
    }
}

void add(node* &lst, int x) {        // aggiungo valori alla lista (fatta in tutorato)

    if (lst == nullptr) {
        node* new_node = new node;
        new_node->data = x;
        new_node->next = nullptr;
    }

    else {

        node* new_node = new node;
        new_node->data = x;
        new_node->next = nullptr;

        node* cursor = lst;

        while(cursor->next != nullptr) {

            cursor = cursor->next;
        }

        cursor->next = new_node;
    }
}

int lunghezzaLista (node* lst) {

    if (lst == nullptr) {
        return 0;
    }
    else {
        return 1 + lunghezzaLista(lst->next);
    }
}

void simmetrica(node* lst) {

    int len = lunghezzaLista(lst);

    }

int  GetValue (node* lst, int i ) {  // controllo il valore della lista

    if (lst == nullptr) {    
        return - 1;
    }

    node* cursor = lst;
    int indice = 0;

    while (cursor != nullptr && indice < i) {

        cursor = cursor->next;
        indice++;
    }

    return cursor->data;
}

node* SommaVicini (node* lst) { // da fare

    int lunghezza = lunghezzaLista(lst);
    node* new_lst = nullptr;

}


