#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Scrivere le funzioni per ottenere i seguenti output
// (in input un albero binario):
// 1. Flip albero: per ogni nodo il sottoalbero destro diventa
//    il sottoalbero sinistro e viceversa.
// 2. Calcolo profondità e altezza di ciascun nodo dell'albero.
// 3. Funzione isBalanced: restituire un flag che indichi se l'albero
//    è bilanciato o meno. Bonus: l'algoritmo è O(n) con n nodi.
// 4. Funzione isComplete: restituire un flag che indichi se l'albero
//    è completo secondo la definizione classica.
// 5. Funzione Lowest Common Ancestor: dati due valori presenti
//    nell'albero, restituire il valore del nodo piu' basso che
//    contiene entrambi nel suo sottoalbero.

using namespace std;

/// Struct per il nodo dell'albero
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
    if (n == nullptr) return;
    inOrder(n->L);
    cout << n->val << " ";
    inOrder(n->R);
}

int max_nodes = 10;
int n_nodes = 0;

// Scambio i due sottoalberi. Bisogna invertire i puntatori e procedere in modo ricorsivo
node_t *flip(node_t *n) {
    if (n == nullptr) return nullptr;
    
    // Arrivato in fondo, risalgo ricorsivamente
    node_t *n1 = node_new(n->val); // Genero nodo n1 con L = null e R = null
    n1->L = flip(n->R);
    n1->R = flip(n->L); // Ricorsivamente scambio i due sottoalberi
    
    return n1; // Ritorno il nuovo albero flippato
}

// Funzione di supporto creata per trovare altezza (height)
int max(int n1, int n2) {
    if (n1 > n2) return n1;
    return n2;
}

// Altezza: una foglia ha altezza 0, la radice ha altezza n.
// Ricorsione: 1 + max(altezza sinistra, altezza destra).
int height(node_t *n) {
    node_t *n1 = n; // Puntatore al nodo per non modificare il puntatore della radice
    int h = 0;
    if (n == nullptr) {
        return -1; // Caso base, albero vuoto ha altezza -1
    }
    
    int hsx = height(n1->L); // Altezza del sottoalbero sinistro
    int hdx = height(n1->R); // Altezza del sottoalbero destro
    
    h = 1 + max(hdx, hsx);
    cout << "il nodo " << n1->val << ": " << h << endl; // Parte dalle foglie e risale fino alla radice, stampando l'altezza di ogni nodo
    return h;
}

// Profondità: una radice ha profondità 0.
// Ricorsione: Profondità figlio = profondità padre + 1.
void depth(node_t *n, int parentDepth) {
    // parentDepth: profondità del nodo padre, 0 per la radice
    node_t *n1 = n;
    if (n1 == nullptr) {
        return; // Caso base
    }
    
    cout << "profondita' nodo " << n1->val << ": " << parentDepth << endl;
    depth(n1->L, parentDepth + 1);
    depth(n1->R, parentDepth + 1);
}

// Ricorsione: per ogni nodo, la differenza tra il sottoalbero destro e sinistro è <= 1.
// Il costo computazionale è alto a causa delle chiamate a height (O(n^2))
// bool isBalanced(node_t *n) {
//     if (n == nullptr) {
//         return true; // Albero vuoto è bilanciato, caso base.
//     }
    
//     if (abs(height(n->L) - height(n->R)) > 1) { // Se la differenza di altezza tra i due sottoalberi è maggiore di 1, l'albero non è bilanciato
//         return false;
//     }
    
//     // Procedo ricorsivamente per tutti i nodi
//     bool v1 = isBalanced(n->L);
//     bool v2 = isBalanced(n->R);
//     return v1 && v2;
// }

// Funzione ausiliaria
// Restituisce l'altezza del sottoalbero se è bilanciato, oppure -1 se NON è bilanciato.
int checkHeight(node_t *n) {
    if (n == nullptr) {
        return 0; // Caso base: un albero vuoto ha altezza 0 ed è bilanciato
    }

    // Calcolo ricorsivo altezza sottoalbero sinistro
    int leftHeight = checkHeight(n->L);
    if (leftHeight == -1) return -1; // Se il sottoalbero sx non è bilanciato, propago l'errore

    // Calcolo ricorsivo altezza sottoalbero destro
    int rightHeight = checkHeight(n->R);
    if (rightHeight == -1) return -1; // Se il sottoalbero dx non è bilanciato, propago l'errore

    // Controllo la differenza di altezza tra i due sottoalberi
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Sbilanciato
    }

    // Ritorno l'altezza del nodo corrente
    return 1 + max(leftHeight, rightHeight);
}

// prima veniva controllata l'altezza ad ogni nodo, ora calcola l'altezza dei sottoalberi
//partendo dal basso e risalendo
//  ottimizzata ad O(n)
bool isBalanced(node_t *n) {
    return checkHeight(n) != -1;
}
bool isComplete(node_t *root) {
    if (root == nullptr) return true;
    
    // Coda di appoggio
    node_t *q[2000];
    int front = 0, next = 0;
    q[next++] = root; // Si parte dalla radice
    
    bool hole = false; // Flag identifica i buchi
    
    while (front < next) { // next aumenta ad ogni inserimento in coda, alle foglie next non aumenta
        node_t *curr = q[front++];
        
        // Gestione figlio sinistro
        if (curr->L) { // Diverso da nullptr
            // Se abbiamo già incontrato un buco in precedenza, non possono esserci altri figli
            if (hole) return false;
            q[next++] = curr->L; //si mette in coda il figlio sinistro
        } else {
            hole = true;
        }
        
        // Gestione figlio destro
        if (curr->R) {
            // Se abbiamo già incontrato un buco (incluso il caso in cui mancasse il sinistro di questo stesso nodo)
            if (hole) return false;
            q[next++] = curr->R;
        } else {
            hole = true;
        }
    }
    return true;
}

// In questa funzione si presuppone che entrambi i valori siano presenti nell'albero, altrimenti ritorna nullptr
node_t *lowestCommonAncestor(node_t *n, int val1, int val2) {
    // Dati due valori, restituisce il valore del nodo più basso che li contiene
    if (n == nullptr) {
        return nullptr; // Se l'albero è vuoto ritorna il puntatore nullo
    }
    
    if (n->val == val1 || n->val == val2) {
        return n;
    }
    
    node_t *l = lowestCommonAncestor(n->L, val1, val2); // Cerco valore a sinistra ricorsivamente
    node_t *r = lowestCommonAncestor(n->R, val1, val2); // Cerco valore a destra ricorsivamente
    
    if (l != nullptr && r != nullptr) { // Se entrambi i sottoalberi contengono i valori, allora il nodo corrente è il più basso antenato comune
        return n;
    }
    
    if (l != nullptr) { // Se il sottoalbero sinistro contiene uno dei valori, ritorno il puntatore al nodo trovato
        return l;
    }
    
    if (r != nullptr) { // Se il sottoalbero destro contiene uno dei valori, ritorno il puntatore al nodo trovato
        return r;
    }
    
    return nullptr;
}

int main() {
    // Usato per testare correttezza
    node_t *root = node_new(10);
    root->L = node_new(5);
    root->R = node_new(15);
    root->L->L = node_new(3);
    root->L->R = node_new(7);
    root->R->L = node_new(12);
    root->R->R = node_new(20);

    cout << "Calcolo altezze:" << endl;
    int h = height(root);
    cout << "Altezza totale albero: " << h << endl << endl;

    cout << "Calcolo profondita':" << endl;
    depth(root, 0);
    cout << endl;

    cout << "Albero bilanciato? ";
    if (isBalanced(root))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
    cout << endl;

    cout << "Albero completo? ";
    if (isComplete(root))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
    cout << endl;

    node_t *lca;
    lca = lowestCommonAncestor(root, 3, 7);
    if (lca) cout << "LCA(3,7) = " << lca->val << endl;
    lca = lowestCommonAncestor(root, 3, 12);
    if (lca) cout << "LCA(3,12) = " << lca->val << endl;
    lca = lowestCommonAncestor(root, 12, 20);
    if (lca) cout << "LCA(12,20) = " << lca->val << endl;
    cout << endl;

    node_t *flipped = flip(root);
    cout << "Albero originale (in-order): ";
    inOrder(root);
    cout << endl;
    cout << "Albero flippato (in-order): ";
    inOrder(flipped);
    cout << endl;

    return 0;
}