#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

/// struct per il nodo dell'albero
typedef struct node {
    int val;
    struct node *L;
    struct node *R;
} node_t;

node_t *node_new(int val) {
    node_t *n = new node_t;
    n->val = val;
    n->L = nullptr;
    n->R = nullptr;
    return n;
}

void inOrder(node_t *n) {
    if(n == nullptr)
        return;
    inOrder(n->L);
    cout << n->val << " ";
    inOrder(n->R);
}

int max_nodes = 10;
int n_nodes = 0;

void insert_random_rec(node_t *n) {
    //// inserisce in modo random un nodo L e R e prosegue ricorsivamente
    /// limito i nodi interni totali, in modo da evitare alberi troppo grandi

    printf("inserisco %d\n", n_nodes);

    if (n_nodes++ >= max_nodes) /// limito il numero di nodi
        return;
    printf("inserisco %d\n", n_nodes);

    float probabilita = 0.8; /// tra 0 e 1

    if (rand() % 100 < probabilita * 100) { // se numero random e' minore della probabilita' -> aggiungo nodo R con valore a caso
        tree_insert_child_R(n, rand() % 100);
    }
    if (rand() % 100 < probabilita * 100) { // se numero random e' minore della probabilita' -> aggiungo nodo L con valore a caso
        tree_insert_child_L(n, rand() % 100);
    }
    if (n->L != NULL)
        insert_random_rec(n->L);
    if (n->R != NULL)
        insert_random_rec(n->R);
}

node_t *flip(node_t *n) {

    if(n == nullptr)
        return nullptr;    //arrivato in fondo, risalgo ricorsivamente

    node_t *n1 = node_new(n->val); //genero nodo n con L = null e R = null
    n1->L = flip(n->R);
    n1->R = flip(n->L);

    return n1;   // ritorno il nuovo albero flippato
}

int max(int n1, int n2){ //funzione creata per height
    if(n1 > n2)
        return n1;
    return n2;
}

//Altezza: una foglia ha altezza 0, la radice ha altezza n.
//Ricorsione: 1 + max(radice sinistra, radice destra).
int height(node_t *n){ 

    node_t *n1 = n; //puntantore al nodo per non modificare il puntatore della radice
    int h = 0;
    
    if(n == nullptr){
        return -1;
    }

    int hsx = height(n1->L);
    int hdx =  height(n1->R);
   
    h = 1 + max(hdx, hsx);
    cout << "il nodo" << n1->val << ": " << h << endl;
    
    return h;
}

//Profondità: una radice ha profondità 0.
//Ricorsione: Profondità figlio = profondità padre + 1.
void depth(node_t *n, int parentDepth){ 
    node_t *n1 = n; 
     
    if(n1 == nullptr){
        return; //caso base
    }
    
    cout << "profondita' nodo " << n1->val << ": " << parentDepth<< endl;
    depth(n1->L, parentDepth + 1); 
    depth(n1->R, parentDepth + 1);
}

//Ricorsione: per ogni nodo, la differenza tra il sottoalbero destro e sinistro è <= 1.
bool isBalanced(node_t *n){

    if (n == nullptr){
        return true; // albero vuoto è bilanciato, caso base.
    }

    if((abs(height(n->L) - height(n->R)) >= 1)){ //>= 1, return false.
        return false;       
    }

    //procedo ricorsivamente per tutti i nodi
    bool v1 = isBalanced(n->L);
    bool v2 = isBalanced(n->R);
   
    return v1 && v2;
}
bool isComplete(node_t *root){
    if(root == nullptr) return true;

    node_t* q[2000];
    int front = 0, next = 0;

    q[next++] = root;

    bool mustBeLeaf = false;

    while(front < next){
        node_t* curr = q[front++];

        // se trovi un nodo dopo che hai visto un buco → non completo
        if(mustBeLeaf && (curr->L || curr->R)){
            return false;
        }

        // figlio sinistro
        if(curr->L){
            q[next++] = curr->L;
        } else {
            mustBeLeaf = true;
        }

        // figlio destro
        if(curr->R){
            if(mustBeLeaf) return false;
            q[next++] = curr->R;
        } else {
            mustBeLeaf = true;
        }
    }

    return true;
}

node_t *lowestCommonAncestor(node_t* n, int val1, int val2){ //dati due valori, restituisce il valore del nodo più basso che li contiene
    
    if(n == nullptr){
        return nullptr;    //se l'albero è vuoto ritorna il puntatore nullo
    }

    node_t* l = lowestCommonAncestor(n->L, val1, val2); //cerco valore a destra ricorsivamente
    node_t* r = lowestCommonAncestor(n->R, val1, val2); //cerco valore a sinistra ricorsivamente   

    if(n->val == val1 || n->val == val2){
        return n;
    }
    
    if(l != nullptr && r != nullptr){
        return n;
    }
    if(l != nullptr){
        return l;
    }
    if(r != nullptr){
        return r;
    }
    return nullptr;
}


int main(){
    node_t *root = node_new(4);  //creazione di nodi fatta fare da AI
    root->L = node_new(2);
    root->R = node_new(6);
    root->L->L = node_new(1);
    root->L->R = node_new(3);
    root->R->L = node_new(5);
    root->R->R = node_new(7);


    node_t *root1 = flip(root);
    cout << "In-order: ";
    inOrder(root);
    cout << endl;

    cout << "Flip: ";
    inOrder(root1);
    cout << endl;

    int res = height(root);
    depth(root, 0);
    return 0;
}