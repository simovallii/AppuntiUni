#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

// Partendo dal file della visita DFS, estendere il codice per verificare 
// se esiste un cammino nel grafo tale che, data in input una sequenza di 
// interi, i nodi del cammino contengono nell'ordine la stessa sequenza di 
// interi dell'input. NB: ciascun nodo del grafo contiene un valore intero 
// rappresentato dall'array V nel codice.



// compilazione: g++ lezione13-grafi-DFS.cpp -o dfs_cammino
// esecuzione: ./dfs_cammino -v -g

int ct_swap = 0;
int ct_cmp = 0;
int ct_op = 0; /// operazioni per la ricerca

int max_dim = 0;
int ntests = 1;
int ndiv = 1;
int details = 0;
int graph = 0;

int n = 0; /// dimensione dell'array

/// file di output per grafo
ofstream output_graph;
int n_operazione = 0; /// contatore di operazioni per visualizzare i vari step

int ct_visit = 0; // contatore durante visita

//////////////////////////////////////////////////
/// Definizione della struttura dati lista
//////////////////////////////////////////////////

/// struct per il nodo della lista
typedef struct node {
    int val;
    struct node *next;
} node_t;

/// struct per la lista
typedef struct list {
    node *head;
} list_t;

//////////////////////////////////////////////////
/// Definizione della struttura dati grafo
//////////////////////////////////////////////////

int *V;          // elenco dei nodi del grafo
int *V_visitato; // nodo visitato?

list_t **E; /// array di puntatori alle liste di adiacenza per ogni nodo
int n_nodi;

list_t *global_ptr_ref = NULL; /// usato per memorizzare il puntatore alla prima lista allocata

int get_address(void *node) {
    return (int)((long)node - (long)global_ptr_ref);
}

void node_print(int n) {
    output_graph << "node_" << n << "_" << n_operazione << endl;
    output_graph << "[ shape = oval; ";
    if (V_visitato[n] == 1)
        output_graph << "fillcolor = \"#ff0000\"; style=filled; ";
    if (V_visitato[n] == 2)
        output_graph << "fillcolor = \"#555555\"; style=filled; ";
    output_graph << "label = "
                 << "\"Idx: " << n << ", val: " << V[n] << "\" ];\n";

    node_t *elem = E[n]->head;
    while (elem != NULL) { /// disegno arco
        output_graph << "node_" << n << "_" << n_operazione << " -> ";
        output_graph << "node_" << elem->val << "_" << n_operazione << " [  color=gray ]\n";
        elem = elem->next;
    }
}

void graph_print() {
    for (int i = 0; i < n_nodi; i++)
        node_print(i);
    n_operazione++;
}

void list_print(list_t *l) {
    if (l->head == NULL) {
        printf("Lista vuota\n");
    } else {
        node_t *current = l->head;

        while (current != NULL) {
            if (!details)
                printf("%d, ", current->val);
            else { /// stampa completa
                if (current->next == NULL)
                    printf("allocato in %d [Val: %d, Next: NULL]\n",
                           get_address(current),
                           current->val);
                else
                    printf("allocato in %d [Val: %d, Next: %d]\n",
                           get_address(current),
                           current->val,
                           get_address(current->next));
            }
            current = current->next;
        }
        printf("\n");
    }
}

list_t *list_new(void) {
    list_t *l = new list;
    l->head = NULL; 
    return l;
}

void list_insert_front(list_t *l, int elem) {
    /// inserisce un elemento all'inizio della lista
    node_t *new_node = new node_t;
    new_node->next = NULL;
    new_node->val = elem;
    new_node->next = l->head;
    l->head = new_node;
}


/**
 * Funzione DFS adattata per verificare un cammino corrispondente alla sequenza S.
 * V_Visitato e V già descritti precedentemente nel codice
 * n: nodo corrente
 * S: sequenza di interi in input
 * seq_len: lunghezza totale della sequenza
 * seq_idx: indice dell'elemento corrente in S che stiamo verificando
 */
int DFS(int n, int* S, int seq_len, int seq_idx) {

    if (details)
        printf("DFS: lavoro sul nodo %d (visitato %d) per verificare S[%d] = %d\n", n, V_visitato[n], seq_idx, S[seq_idx]);

    // Controllo di corrispondenza del valore del nodo corrente con la sequenza
    if (V[n] != S[seq_idx]) {
        return 0; // Il valore non coincide, abortiamo questo ramo
    }

    // Il valore è quello ed è l'ultimo, cammino trovato
    if (seq_idx == seq_len - 1) {
        return 1; 
    }

    // Controllo ciclo
    if (V_visitato[n] == 1) 
        return 0;

    //il valore coincide ma non è l'ultimo della sequenza, continuo
    V_visitato[n] = 1; // Marciamo temporaneamente come visitato nell'esplorazione del cammino

    if (details)
        printf("Visito il nodo %d (val %d) all'indice di sequenza %d\n", n, V[n], seq_idx);

    int ret = 0;
        
    /// esploro la lista di adiacenza
    node_t *elem = E[n]->head;
    while (elem != NULL && ret == 0) { /// Continuo finche non trovo ret = 1 (cammino valido) o finche ci sono nodi visitabili

        if (graph) {
            graph_print();

            /// espando arco  n --> elem->val
            output_graph << "dfs_" << n << " -> dfs_" << elem->val;
            if (V_visitato[elem->val])
                output_graph << "[color=gray, label = \"" << ct_visit++ << "\"]";
            else
                output_graph << "[color=red, label = \"" << ct_visit++ << "\"]";
            output_graph << endl;
        }

        // Chiamata ricorsiva avanzando al prossimo elemento della sequenza (seq_idx + 1)
        ret = DFS(elem->val, S, seq_len, seq_idx + 1);

        elem = elem->next;
    }

    // Azzeriamo il contatore per permettere ad altri nodi di visitarlo
    V_visitato[n] = 0; 
    
    if (graph) {
        graph_print();
    }

    return ret;
}


//  Avvia la ricerca della sequenza individuando tutti i possibili nodi di partenza.
 
bool verifica_cammino(int* S, int seq_len) {
    if (seq_len <= 0) return true;

    // Reset di tutti i nodi 
    for (int i = 0; i < n_nodi; i++) {
        V_visitato[i] = 0;
    }

    // Cerchiamo nodo di partenza
    for (int i = 0; i < n_nodi; i++) {
        if (V[i] == S[0]) {
            if (details) {
                printf("\nTentativo di avvio DFS dal nodo di partenza con indice %d (Valore %d)\n", i, V[i]);
            }
            if (DFS(i, S, seq_len, 0) == 1) {
                return true; // Trovato cammino
            }
        }
    }
    return false; // Nessun cammino valido 
}

int parse_cmd(int argc, char **argv) {
    /// controllo argomenti
    int ok_parse = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][1] == 'v') {
            details = 1;
            ok_parse = 1;
        }
        if (argv[i][1] == 'g') {
            graph = 1;
            ok_parse = 1;
        }
    }

    if (argc > 1 && !ok_parse) {
        printf("Usage: %s [Options]\n", argv[0]);
        printf("Options:\n");
        printf("  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n");
        printf("  -graph: creazione file di dot con il grafo dell'esecuzione\n");
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    srand((unsigned)time(NULL));

    if (parse_cmd(argc, argv))
        return 1;

    if (graph) {
        output_graph.open("graph.dot");
        /// preparo header
        output_graph << "digraph g" << endl;
        output_graph << "{ " << endl;
        output_graph << "node [shape=none]" << endl;
        output_graph << "rankdir=\"LR\"" << endl;
    }

    n_nodi = 7;
    V = new int[n_nodi];          
    V_visitato = new int[n_nodi]; 
    E = new list_t *[n_nodi]; 

    // Inizializzazione: i nodi conterranno i valori pari {0, 2, 4, 6, 8, 10, 12}
    for (int i = 0; i < n_nodi; i++) {
        V[i] = 2 * i;
        V_visitato[i] = 0; 
        E[i] = list_new();
    }

    // Costruiamo un grafo circolare: ogni nodo i è connesso al nodo (i+1) % n_nodi
    for (int i = 0; i < n_nodi; i++) {
        if (i == 0)
            global_ptr_ref = E[i];

        int next_node = (i + 1) % n_nodi;
        list_insert_front(E[i], next_node);
    }

    // Stampiamo lo stato iniziale del grafo
    for (int i = 0; i < n_nodi; i++) {
        printf("Sono il nodo di indice %d nell'array. Valore: %d. Adiacente a: ", i, V[i]);
        list_print(E[i]);
    }

    printf("\n============ INIZIO TEST DI VERIFICA CAMMINI ============\n");

    // Test 1: Cammino Esistente ordinato (0 -> 2 -> 4)
    int sequenza_valida[] = {0, 2, 4};
    int len1 = 3;
    printf("\nTest 1: Ricerca cammino per sequenza {0, 2, 4}\n");
    if (verifica_cammino(sequenza_valida, len1)) {
        printf("Risultato: CAMMINO TROVATO!\n");
    } else {
        printf("Risultato: CAMMINO NON TROVATO.\n");
    }

    // Test 2: Cammino Non Esistente (0 -> 4, manca il 2 in mezzo poiché non c'è un arco diretto da 0 a 4)
    int sequenza_invalida[] = {0, 4};
    int len2 = 2;
    printf("\nTest 2: Ricerca cammino per sequenza {0, 4}\n");
    if (verifica_cammino(sequenza_invalida, len2)) {
        printf("Risultato: CAMMINO TROVATO!\n");
    } else {
        printf("Risultato: CAMMINO NON TROVATO.\n");
    }

    // Test 3: Cammino Circolare a cavallo dello zero (10 -> 12 -> 0 -> 2)
    int sequenza_circolare[] = {10, 12, 0, 2};
    int len3 = 4;
    printf("\nTest 3: Ricerca cammino per sequenza {10, 12, 0, 2}\n");
    if (verifica_cammino(sequenza_circolare, len3)) {
        printf("Risultato: CAMMINO TROVATO!\n");
    } else {
        printf("Risultato: CAMMINO NON TROVATO.\n");
    }

    if (graph) {
        /// preparo footer e chiudo file
        output_graph << "}" << endl;
        output_graph.close();
        cout << "\nFile graph.dot scritto" << endl
             << "Creare il grafo con: dot graph.dot -Tpdf -o graph.pdf" << endl;
    }

    // Liberazione memoria
    delete[] V;
    delete[] V_visitato;
    for (int i = 0; i < n_nodi; i++) {
        node_t* current = E[i]->head;
        while (current != NULL) {
            node_t* temp = current;
            current = current->next;
            delete temp;
        }
        delete E[i];
    }
    delete[] E;

    return 0;
}