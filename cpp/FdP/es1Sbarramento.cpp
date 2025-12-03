#include<iostream>
#include<cstring>
using namespace std;

struct node {

    int data;
    node* next;
};

 


char* replace (char* str, char target, char replacement) {

char* str2 = new char;

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] != target) {

            str2[i] = str[i];
            
        }
        else {

            str2[i] = replacement;
        }


        

    }
    return str2;
}

node* concat (node* &l1, node* l2) {


    if (l1 == nullptr && l2 == nullptr) {

        return nullptr;
    }
    else if (l1 != nullptr && l2 == nullptr) {

        return l1;
    }
    else if (l1 == nullptr && l2 != nullptr) {

        return l2;
    }
    else {

        node* new_node = new node;

        new_node = l1;
        for (int i = 0; new_node->next != nullptr; i++) {

            new_node = new_node->next;

        }

        new_node->next = l2;

        return l1;
    }
}

void swap (int a[], int b[], int dim) {



    
    for (int i = 0; i < dim; i++ ) {

        int temp = 0;

        if (a[i] > b[i]) {

            temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }
}


char* trim(char* str, char c) {
    
    int dim = 0;
    int dim2 = 0;
    char* str2;
    while (str[dim] != '\0') {

            dim++;

    }

    for (int i = 0; i < dim; i++) {

        if (str[i] != c) {

            str2[dim2] = str[i];
            dim2++;
        }
    }

    return str2;
}


bool isDescending (node* lst) {
    
       bool decrescente;

    if (lst == nullptr) {

        return false;
    }
    else {

     
       node* new_lst;

        while (lst->next != nullptr) {

             
                new_lst = lst;
                lst = lst-> next;

                if(new_lst->data > lst->data) {

                  decrescente = true;  
                }
                else {

                  decrescente = false;
                  break;
                }

        }
    }

    return decrescente;
}

void ruota (int x[], int dim ) {

    int y[dim];

    for (int i = 0; i < dim; i++) {

        y[i + 1] = x[i];

        if (i == (dim - 1)) {

            y[0] = x[i]; 
        }
    }

    for (int j = 0; j < dim; j++) {

        x[j] = y[j];
    }
}

void reverse(int a[], int length) {

    int inizio = 0;
    int fine = length - 1;
    int tmp = 0;

    while (inizio < fine) {

        tmp = a[inizio];
        a[inizio] = a[fine];
        a[fine] = tmp;

        inizio++;
        fine--;
    }

   
}





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



int main() {

char str[] = {"ciao"};

cout << trim(str, 'a');

 return 0;
}