#include<iostream>
using namespace std;

struct node {

    int data;
    node* next;
};



bool equals  (node* l1, node* l2) {

    if ( l1 == nullptr || l2 == nullptr) {

        return true;
    }
    else {

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->data != l2->data) {

                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return true;
    }
}

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

node* unione (node* &lst, node* lst2) {

    node* new_lst = new node;
    
    new_lst = lst;

    while (new_lst->next != nullptr) {

        new_lst = new_lst->next;
    }
    new_lst->next = lst2;

    node* new_lst2 = nullptr;
    node* copiaLst = lst;
    node* copiaNuovaLst = nullptr;
    bool v;

    while (copiaLst != nullptr) {

        copiaNuovaLst = new_lst2;

        while (copiaNuovaLst != nullptr) {
            
            v = false;
            if (copiaLst->data == copiaNuovaLst->data) {
                v = true;
                break;
            }
            copiaNuovaLst = copiaNuovaLst->next;
        }

        if (!v) {
            AddAtTheEnd(new_lst2, copiaLst->data);
        }
        copiaLst = copiaLst->next;
    }

    return new_lst2;
    
}


node* rotate (node* &lst) {

    node* new_node = new node;
    new_node = lst;
    int x = new_node->data;
    int y = 0;

    while(new_node->next != nullptr) {

       y = new_node->next->data;

        new_node->next->data = x;
        x = y;
        new_node = new_node->next;

    }
    node* new_lst = new node;
    new_lst = lst;
    new_lst->data = y;

    return lst;

}


void rotate_back (node* &lst) {

    node* inizio = new node;
    inizio = lst;
    

    node* fine = new node;
    fine = lst;

    while (fine->next != nullptr) {

        fine = fine->next;
    }

    lst = lst->next;
    inizio->next = nullptr;
    fine->next = inizio;

}


node* sum_lists (node* lst1, node* lst2) {

    int c1 = 0;
    int c2 = 0;
    node* new_lst1 = lst1;
    node* new_lst2 = lst2;

    while (new_lst1 != nullptr) {
        c1++;
        new_lst1 = new_lst1->next;
    }

      while (new_lst2 != nullptr) {
        c2++;
        new_lst2 = new_lst2->next;
    }

    if (c1 == c2) {

        node* new_node = new node;
        new_node = nullptr;

        while (lst1 != nullptr) {

           AddAtTheEnd(new_node, lst1->data + lst2->data);
           lst1 = lst1->next;
           lst2 = lst2->next;
            
        }

        return new_node;
    }
    else if (c1 > c2) {

        node* new_node = new node;
        new_node = nullptr;
        while (lst2 != nullptr) {

            AddAtTheEnd(new_node, lst1->data + lst2->data);
            lst1 = lst1->next;
            lst2 = lst2->next;

        }

        while (lst1 != nullptr) {
            AddAtTheEnd(new_node, lst1->data);
            lst1 = lst1->next;
        }

        return new_node;
    }
     else if (c1 < c2) {

        node* new_node = new node;
        new_node = nullptr;
        while (lst1 != nullptr) {

            AddAtTheEnd(new_node, lst1->data + lst2->data);
            lst1 = lst1->next;
            lst2 = lst2->next;

        }

        while (lst2 != nullptr) {
            AddAtTheEnd(new_node, lst2->data);
            lst2 = lst2->next;
        }
        return new_node;
    }
}



node* merge (node* l1, node* l2) {

    node* l3 = new node;
    l3 = nullptr;

    while (l1 != nullptr || l2 != nullptr) {
        if (l1 != nullptr && l2 == nullptr) {

            AddAtTheEnd(l3, l1->data);
            l1 = l1->next;

        }
        else if (l1 == nullptr && l2 != nullptr) {

            AddAtTheEnd(l3, l2->data);
            l2 = l2->next;
        }
        else if (l1->data <= l2->data) {

            AddAtTheEnd(l3,l1->data);
            l1 = l1->next;
        }
        else if (l2->data <= l1->data) {

            AddAtTheEnd(l3, l2->data) ;
            l2 = l2->next;
        }
    }

    return l3;
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


node* unions (node* l1, node* l2) {

concat(l1,l2);     // da rivedere 

node* new_lst = new node;
new_lst = nullptr;

AddAtTheEnd(new_lst, l1->data);

node* cursor1 = l1;


while (cursor1 != nullptr) {
 bool v;
   node* cursor2 = new_lst;

          v = false;
    while (cursor2 != nullptr) {
      
        if (cursor1->data == cursor2->data) {

            v = true;
            break;
            
        }
       
cursor2 = cursor2->next;
    }
    if (v == false) {

        AddAtTheEnd(new_lst, cursor1->data);
    }
    cursor1 = cursor1->next;
}

return new_lst;
}

node* firstEven (node* lst) {

    if (lst == nullptr) {

        return NULL;
    }
    else {

        while (lst != nullptr) {

            if (lst->data%2 == 0) {

                return lst;
            }
            lst = lst->next;
        }

        return NULL;
    }
}

int main (){

    node* lst = nullptr;
    node* lst2 = nullptr;

    AddAtTheEnd(lst, 1);
    AddAtTheEnd(lst, 3);
    AddAtTheEnd(lst, 3);
    AddAtTheEnd(lst, 9);
    AddAtTheEnd(lst, 5);

    AddAtTheEnd(lst2, 6);
    AddAtTheEnd(lst2, 4);
    AddAtTheEnd(lst2, 3);
    AddAtTheEnd(lst2, 2);
    AddAtTheEnd(lst2, 1);
    
node* l3 = nullptr;
l3 = firstEven(lst);

stampa(l3);
   

   

    return 0;
}