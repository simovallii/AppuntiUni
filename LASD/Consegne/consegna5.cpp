#include <iostream>  
#include <fstream>   
#include <sstream>   
#include <string>    
#include <stdio.h>   
#include <math.h>    

using namespace std;

// Partire dal codice fornito (in materiale didattico) che carica 
// le distanze tra i capoluoghi di provincia italiani e integrare 
// l'esecuzione del clustering gerarchico di kruskal. Identificare 
// gli ultimi archi aggiunti per descrivere quali sono i cluster di 
// città più distanti tra loro.
// Bonus: rappresentare graficamente i cluster o lo spanning tree 
// evidenziando gli ultimi archi



typedef struct node {
    int val;           
    float w;           
    struct node *next; 
} node_t;

 
typedef struct list {
    node *head;         
} list_t;

int details = 0; 


list_t *list_new(void) {
    list_t *l = new list;
    l->head = NULL;     
    return l;
}


void list_insert_front(list_t *l, int elem, float w) {
    node_t *new_node = new node_t; 
    new_node->val = elem;         
    new_node->w = w;               
    new_node->next = l->head;      
    l->head = new_node;            
}


void list_print(list_t *l, string *nomi) {
    if (l->head == NULL) {
        printf("Lista vuota\n");
    } else {
        node_t *current = l->head;
        while (current != NULL) {
           
            printf("%s(%d) w:%.1f, ", nomi[current->val].c_str(), current->val, current->w);

        }
        printf("\n");
    }
}

const int N = 107; // Numero totale dei capoluoghi di provincia italiani

// Struttura che mappa un arco in modo isolato 
struct Edge {
    int u, v;      // I due nodi, estremi dell'arco
    float peso;    // Il peso dell'arco 
};


//UNION-FIND

int parent[N + 1]; // Array dei "padri": indica a quale set appartiene ogni nodo
int rango[N + 1];  // Array dei "ranghi": stima l'altezza degli alberi per ottimizzare l'unione

// Inizializza le strutture Union-Find creando n set indipendenti
void ds_init(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i; // All'inizio ogni nodo è padre di se stesso (set isolato)
        rango[i] = 0;  // Altezza iniziale dell'albero pari a 0
    }
}

// Trova la radice del set x
int ds_find(int x) {
    if (parent[x] != x)
        //  collega il nodo direttamente alla radice finale
        parent[x] = ds_find(parent[x]); 
    return parent[x];
}

// Unisce i set di x e y. Ritorna 'true' se l'unione avviene, 'false' se erano già nello stesso set
bool ds_unisci(int x, int y) {
    int rx = ds_find(x); // Radice del set di x
    int ry = ds_find(y); // Radice del set di y
    if (rx == ry)
        return false;    // Hanno la stessa radice: creerebbero un ciclo.

    // l'albero più basso viene agganciato sotto l'albero più alto
    if (rango[rx] < rango[ry]) {
        int tmp = rx; rx = ry; ry = tmp; // Scambia per garantire che rx sia il più alto
    }
    parent[ry] = rx; // Collega l'albero ry sotto rx
    if (rango[rx] == rango[ry])
        rango[rx]++; // Se avevano la stessa altezza, l'altezza di rx aumenta di 1
    return true;
}

// ---------------------------------------------------------------------
// QUICKSORT manuale su array di Edge
// ---------------------------------------------------------------------

// Scambia di posto due strutture Edge in memoria
void scambia(Edge& a, Edge& b) {
    Edge tmp = a;
    a = b;
    b = tmp;
}

// Funzione di partizionamento per Quicksort
int partiziona(Edge arr[], int basso, int alto) {
    float pivot = arr[alto].peso; // Sceglie l'ultimo elemento come valore pivot
    int i = basso - 1;            // Indice di elementi < pivot
    for (int j = basso; j < alto; ++j) {
        if (arr[j].peso <= pivot) { // Se l'elemento corrente è più piccolo o uguale al pivot
            ++i;
            scambia(arr[i], arr[j]);
        }
    }
    scambia(arr[i + 1], arr[alto]); // Riposiziona il pivot al centro
    return i + 1;                   // Ritorna l'indice del pivot
}

// Quicksort 
void quicksort(Edge arr[], int basso, int alto) {
    if (basso < alto) {
        int p = partiziona(arr, basso, alto); // partiziona l'array
        quicksort(arr, basso, p - 1);         // ordina la metà sinistra
        quicksort(arr, p + 1, alto);          // ordina la metà destra
    }
}


int main() {
    const char* filename = "distanze_linea_aria_capoluoghi_con_id.csv";

    // Apertura del file CSV contenente i dati del grafo
    ifstream file(filename);
    if (!file) {
        cerr << "Errore apertura file: " << filename << "\n";
        return 1; 
    }

    int n_nodi = N; 

    // lista di adiacenza per ogni nodo, array di puntatori
    list_t **E = new list_t *[n_nodi + 1];
    for (int i = 0; i <= n_nodi; ++i)
        E[i] = list_new(); // Inizializza ogni singola lista di adiacenza

    // serve per mappare l'id(val) al nome reale
    string *nomi = new string[n_nodi + 1];

    string line;
    getline(file, line); 

    // Lettura del file riga per riga
    //estrae la lista di adiacenza
    while (getline(file, line)) {
        stringstream ss(line); // Trasforma la stringa in uno stream per estrarre i campi
        string field;

        int origine_id = 0, destinazione_id = 0;
        float km = 0.0f;

        // Parsing dei campi del CSV separati da virgole
        getline(ss, field, ','); origine_id = stoi(field);      // Estrae e converte l'ID origine
        getline(ss, field, ','); destinazione_id = stoi(field); // Estrae e converte l'ID destinazione

        string origine_nome, destinazione_nome;
        getline(ss, field, ','); origine_nome = field;      // Estrae il nome dell'origine
        getline(ss, field, ','); destinazione_nome = field; // Estrae il nome della destinazione
        getline(ss, field, ','); km = stof(field);          // Estrae e converte la distanza in chilometri

        // Inserisce l'arco in entrambe le liste di adiacenza, grafo non orientato
        list_insert_front(E[origine_id], destinazione_id, km);
        list_insert_front(E[destinazione_id], origine_id, km);

        // Salva i nomi delle città nei rispettivi indici dell'array dei nomi
        nomi[origine_id] = origine_nome;
        nomi[destinazione_id] = destinazione_nome;
    }
    file.close(); // Chiude il file CSV dopo la lettura

    // una volta estratta la lista di aidacenza, individuiamo gli archi
    int maxArchi = n_nodi * (n_nodi - 1) / 2;
    Edge *archi = new Edge[maxArchi]; // Array lineare che conterrà tutti gli archi per poterli ordinare
    int numArchi = 0;                 // Contatore effettivo degli archi inseriti nell'array

    // Trasferisce gli archi dalle liste di adiacenza all'array lineare
    for (int i = 1; i <= n_nodi; ++i) {
        node_t *elem = E[i]->head;
        while (elem != NULL) {
            // non inseriamo due volte l'arco, grafo non orientato
            if (elem->val > i) { 
                archi[numArchi].u = i;
                archi[numArchi].v = elem->val;
                archi[numArchi].peso = elem->w;
                ++numArchi;
            }
            elem = elem->next;
        }
    }

    // Ordina tutti gli archi letti in ordine di peso crescente 
    quicksort(archi, 0, numArchi - 1);

   //KRUSKAL 

    ds_init(n_nodi); // Inizializza la struttura Union-Find per i nodi

    // Un MST contiene sempre esattamente (V - 1) archi, dove V è il numero di nodi
    Edge *mst = new Edge[n_nodi - 1]; 
    int numMst = 0; // Contatore degli archi inseriti finora nel MST

    // Scorre gli archi ordinati dal più leggero al più pesante
    for (int k = 0; k < numArchi && numMst < n_nodi - 1; ++k) {
        int u = archi[k].u; //estremo dell'arco
        int v = archi[k].v; //estremo dell'arco
        
        // Se ds_unisci restituisce true significa che u e v non creano cicli e vengono uniti nel set
        if (ds_unisci(u, v)) {
            mst[numMst] = archi[k]; // Aggiunge l'arco all'array del MST
            ++numMst;               // Incrementa il contatore degli archi dell'MST
        }
    }

    // Calcolo del costo complessivo dell'MST sommando i pesi degli archi scelti
    float pesoTotale = 0.0f;
    for (int i = 0; i < numMst; ++i)
        pesoTotale += mst[i].peso;

    // Output riassuntivo dei risultati a console
    cout << "=== ESECUZIONE ALGORITMO DI KRUSKAL ===" << endl;
    cout << "Numero di archi letti dal CSV: " << numArchi << endl;
    cout << "Archi inseriti nel MST: " << numMst << " (Attesi: " << n_nodi - 1 << ")" << endl;
    cout << "Peso totale del Minimum Spanning Tree: " << pesoTotale << " km" << endl;

    //clustering gerarchico di Kruskal
    //funziona in questo modo. Dopo averapplicato
    //l'algoritmo di kruskal, se si vogliono k cluster sarà 
    // necessario togliere k - 1 nodi. Togliendo il nodo piu pesante 
    // dall'mst, si ottengono più componenti connesse


    int K = 5; // Numero di archi piu lunghi da evidenziare
    if (K > numMst) K = numMst; // Protezione nel caso in cui l'MST avesse meno di K archi

    // Stampa a schermo degli ultimi K archi inseriti (quelli a distanza maggiore prima della chiusura dell'MST)
    cout << "\nUltimi " << K << " archi aggiunti al MST (Cluster più distanti):" << endl;
    for (int i = numMst - K; i < numMst; ++i) {
        cout << "  [" << i + 1 << "/" << numMst << "] "
             << nomi[mst[i].u] << " -- " << nomi[mst[i].v] << " : " << mst[i].peso << " km" << endl;
    }

    //scrittura grafo
    ofstream dot("graph.dot"); // Crea o sovrascrive il file graph.dot
    if (dot) {
        dot << "graph G {\n";
        dot << "  layout=neato;\n"; // Indica a Graphviz di usare l'algoritmo di posizionamento energetico/fisico
        
        // Impostazioni estetiche predefinite per i nodi
        dot << "  node [shape=ellipse, style=filled, fillcolor=lightgray];\n";

        // Scrittura delle relazioni (archi dell'MST) nel file DOT
        for (int i = 0; i < numMst; ++i) {
            bool is_last_edge = (i >= numMst - K); // Controlla se fa parte degli ultimi K archi
            
            dot << "  \"" << nomi[mst[i].u] << "\" -- \"" << nomi[mst[i].v] << "\"";
            
            if (is_last_edge) {
                // Gli ultimi K archi vengono colorati di rosso e ispessiti per evidenziarli
                dot << " [label=\"" << (int)mst[i].peso << " km\", color=red, penwidth=3.0];\n";
            } else {
                dot << " [label=\"" << (int)mst[i].peso << "\"];\n";
            }
        }
        dot << "}\n";
        dot.close(); // Chiude il flusso di scrittura sul file DOT
        cout << "\n[OK] Struttura salvata correttamente nel file 'graph.dot'" << endl;
    } else {
        cerr << "\n[ERRORE] Impossibile creare il file 'graph.dot'" << endl;
    }

    // -------------------------------------------------------------
    // PULIZIA MEMORIA (Deallocazione per evitare Memory Leak)
    // -------------------------------------------------------------
    for (int i = 0; i <= n_nodi; ++i) {
        node_t *elem = E[i]->head;
        while (elem != NULL) {
            node_t *tmp = elem;
            elem = elem->next;
            delete tmp; // Rilascia i singoli nodi delle liste concatenate
        }
        delete E[i]; // Rilascia la struttura di controllo della lista
    }
    // Rilascia gli array dinamici allocati inizialmente con l'operatore 'new[]'
    delete[] E; delete[] nomi; delete[] archi; delete[] mst;

    return 0; // Il programma termina correttamente
}