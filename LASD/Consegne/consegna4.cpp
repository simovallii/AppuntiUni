#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
// Estendere il codice di base di shortest path, sostituendo la gestione
// per l'estrazione del minimo nodo (attualmente con un ciclo O ( n ) ),
// con l'heap utilizzato nelle lezioni precedenti. Il punto di attenzione
// principale e' di garantire la complessita' log ( n ) e di recuperare
// correttamente l'indice dell'array dell'heap a partire dal codice del
// nodo (ad esempio nella decrease_key). Assicurarsi di non confondere
// l'indice del nodo del grafo con l'indice della posizione dell'elemento
// nell'heap. NON usare implementazione di heap alternative.
// Studiare e implementare l'algoritmo di Bellman-Ford, sfruttando il
// codice di shortest path già scritto. Provare con un esempio di grafo
// con almeno un arco di peso negativo e un altro grafo con un ciclo di
// archi di peso tutti negativi. Opzionale: adattare le visualizzazioni
// dei grafi con dot per mostrare il suo corretto funzionamento.
// compilazione: g++ consegna4.cpp
#define INFTY 1000000
int details = 0;
int n_operazione = 0; /// contatore di operazioni per visualizzare i vari step

//////////////////////////////////////////////////
/// Definizione della struttura dati lista
//////////////////////////////////////////////////
typedef struct node {
int val; /// prossimo nodo
float w; /// peso dell'arco
struct node *next;
} node_t;
typedef struct list {
node *head;
} list_t;
//////////////////////////////////////////////////
/// Fine Definizione della struttura dati lista
//////////////////////////////////////////////////

int *heap; // heap[i] = codice del nodo di grafo in posizione i
int *pos_in_heap; // pos_in_heap[nodo] = indice i in heap[] ; -1 se il nodo non e' nello heap
int heap_size = 0; // dimensione attuale dello heap
int n_nodi = 0;
float *V_dist; // distanza da sorgente
int *V_prev; // nodo precedente dalla visita
int *V_visitato; // nodo visitato?
list_t **E; /// array di puntatori a le liste di adiacenza per ogni nodo

/// uso -1 per indicare un indice non esistente
//immaginarsi struttura ad albero
int parent_idx(int n) {
if (n == 0)
return -1;
return (n - 1) / 2;
}
int child_L_idx(int n) {
if (2 * n + 1 >= heap_size)
return -1;
return 2 * n + 1;
}
int child_R_idx(int n) {
if (2 * n + 2 >= heap_size)
return -1;
return 2 * n + 2;
}
int is_leaf(int n) {
return (child_L_idx(n) == -1);
}
/// scambia il contenuto di due
/// posizioni dell'array heap e mantiene sincronizzato pos_in_heap.
/// E' l'unico punto in cui avviene uno scambio fisico dentro heap[], cosi'
/// da avere un solo posto da mantenere corretto per pos_in_heap.
void heap_swap(int i, int j) {
int t = heap[i];
heap[i] = heap[j];
heap[j] = t;

pos_in_heap[heap[i]] = i;
pos_in_heap[heap[j]] = j;
}
void heap_insert(int nodo) {
/// inserisco "nodo" nell'ultima posizione libera
/// dell'array heap
if (details)
printf("Inserisco nodo %d (dist %f) in posizione %d\n", nodo, V_dist[nodo], heap_size);

if (heap_size < n_nodi) { /// capienza = n_nodi, non piu' MAX_SIZE
    int i = heap_size;
    heap_size++;

    heap[i] = nodo;
    pos_in_heap[nodo] = i; /// NUOVO: registro subito dove si trova il nodo

    while (i != 0) { // non sono sulla radice
        int p = parent_idx(i);
        /// MIN-heap
        if (V_dist[heap[p]] <= V_dist[heap[i]]) { /// proprieta' rispettata, esco
            if (details)
                printf("Il genitore ha dist %f <= del nodo %f, esco\n", V_dist[heap[p]], V_dist[heap[i]]);
            return;
        }

        if (details)
            printf("Il genitore ha dist %f > del nodo %f, swap\n", V_dist[heap[p]], V_dist[heap[i]]);

        heap_swap(p, i); // tengo aggiornato pos_in_heap

        i = p;
    }

} else
    printf("Heap pieno!\n");
}
//funzione che sistema l'heap e fa rispettare la proprieta
//controlla che le distanze siano minori e, in caso contrario, scambia
// i due nodi fino ad arrivare alla radice
//alla radice
void decrease_key(int nodo) {
int i = pos_in_heap[nodo]; //posizione del nodo nell'heap

if (i == -1) {
    printf("decrease_key: il nodo %d non e' nello heap\n", nodo);
    return;
}

while (i != 0) { // non sono sulla radice
    int p = parent_idx(i);
    if (V_dist[heap[p]] <= V_dist[heap[i]]) /// proprieta' rispettata, esco
        return;

    heap_swap(p, i);
    i = p;
}
}
// adattata da heap_remove_max
// scambio l'elemento minimo (il primo per definizione) con l'ultimo elemento
//dell'heap. Estraggo qindi l'ultimo elemento dall'heap e successivamente
//cerco la posizione per l'elemento attualmente radice
int heap_extract_min() {
if (heap_size <= 0) { /// heap vuoto!
printf("Errore: heap vuoto\n");
return -1;
}

int minimo = heap[0];

if (details)
    printf("Minimo identificato: nodo %d (dist %f)\n", minimo, V_dist[minimo]);

/// scambio la radice con l'ultima foglia, usando
/// heap_swap per mantenere coerente pos_in_heap
heap_swap(0, heap_size - 1);

pos_in_heap[minimo] = -1; /// il nodo estratto non e' piu' nello heap
heap_size--;              /// elimino il minimo (ora in fondo all'array)

/// stessa struttura di lezione11 adattata al min heap
int i = 0; // indice di lavoro (parto dalla root)

while (!is_leaf(i)) {
    if (details)
        printf("Lavoro con il nodo in posizione i = %d, nodo %d\n", i, heap[i]);

    int con_chi_mi_scambio = -1;

    if (V_dist[heap[i]] > V_dist[heap[child_L_idx(i)]]) { // il nodo i e' piu' grande del figlio L
        con_chi_mi_scambio = child_L_idx(i);

        if (child_R_idx(i) >= 0 &&
            V_dist[heap[child_L_idx(i)]] > V_dist[heap[child_R_idx(i)]]) {
            con_chi_mi_scambio = child_R_idx(i); // il figlio R e' ancora piu' piccolo di L
        }
    } else { // il nodo i e' piu' piccolo o uguale al figlio L
        if (child_R_idx(i) >= 0) { // esiste il figlio R
            if (V_dist[heap[i]] > V_dist[heap[child_R_idx(i)]]) {
                con_chi_mi_scambio = child_R_idx(i);
            } else
                break;
        } else
            break;
    }

    heap_swap(i, con_chi_mi_scambio); //aggiorno correttamente l'heap

    i = con_chi_mi_scambio; 
}

return minimo;
}
int heap_is_empty() {
return heap_size == 0;
}
//////////////////////////////////////////////////
/// Fine Definizione della struttura dati HEAP
//////////////////////////////////////////////////

list_t *global_ptr_ref = NULL; /// usato per memorizzare il puntatore alla prima lista allocata
int get_address(void *node) {
return (int)((long)node - (long)global_ptr_ref);
}

void list_print(list_t *l) {
if (l->head == NULL) {
printf("Lista vuota\n");
} else {
node_t *current = l->head;

    while (current != NULL) {
        if (!details)
            printf("%d w:%f, ", current->val, current->w);
        else {
            if (current->next == NULL)
                printf("allocato in %d [Val: %d, W: %f, Next: NULL]\n",
                       get_address(current), current->val, current->w);
            else
                printf("allocato in %d [Val: %d, W: %f, Next: %d]\n",
                       get_address(current), current->val, current->w, get_address(current->next));
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
void list_insert_front(list_t *l, int elem, float w) {
node_t *new_node = new node_t;
new_node->next = NULL;
new_node->val = elem;
new_node->w = w;
new_node->next = l->head;
l->head = new_node;
}

/// shortest_path, ottimizzato
void shortest_path(int n) {

//inizializzo dati
for (int i = 0; i < n_nodi; i++) {
V_dist[i] = INFTY;
V_prev[i] = -1;
V_visitato[i] = 0;
}
//con tutte le altre distanza ad infinito
V_dist[n] = 0;

heap_insert(n); /// inserisco il nodo sorgente (unico nodo con dist=0 all'inizio)

while (!heap_is_empty()) {
    int u = heap_extract_min(); /// O(log n) invece di O(n)
    V_visitato[u] = 1;

    /// esploro la lista di adiacenza 
    //analizzzo i vicini
    node_t *elem = E[u]->head;
    while (elem != NULL) {
        int v = elem->val; /// arco u --> v

        if (V_visitato[v] == 0) { /// considero solo nodi non ancora visitati
            ///nuovo costo
            float alt = V_dist[u] + elem->w;

            if (alt < V_dist[v]) { //se il nuovo costo è migliore
                V_dist[v] = alt;
                V_prev[v] = u;

                if (details)
                    printf("Dijkstra - Rilasso arco %d -> %d: nuova dist[%d] = %f\n", u, v, v, alt);

                //se v non e' mai stato messo in coda -> lo inserisco ora
                //se v e' gia' nello heap -> gli faccio fare decrease_key
                //in modo da metterlo nella posizione corretta dell'heap
                if (pos_in_heap[v] == -1)
                    heap_insert(v);
                else
                    decrease_key(v);
            }
        }
        elem = elem->next;
    }
}
}

//////////////////////////////////////////////////
/// Bellman-Ford
//////////////////////////////////////////////////
///
/// Per testare Bellman-Ford servono grafi piccoli, costruiti a mano, con
/// pesi anche negativi (Dijkstra invece richiede pesi non negativi, quindi
/// per quel test si e' tenuto il grafo a griglia con pesi calcolati come
/// pow(V[u]-V[v],2), sempre >= 0).
///
/// alloca le strutture dati del grafo per n nodi, senza archi (NUOVA, ma
/// stessa tecnica di allocazione gia' usata in main() per il grafo a
/// griglia: new[] dimensionato a n_nodi)
void alloca_grafo(int n) {
n_nodi = n;
heap_size = 0;

V_visitato = new int[n_nodi];
V_prev = new int[n_nodi];
V_dist = new float[n_nodi];

heap = new int[n_nodi];
pos_in_heap = new int[n_nodi];

E = new list_t *[n_nodi];

for (int i = 0; i < n_nodi; i++) {
    V_visitato[i] = 0;
    V_prev[i] = -1;
    V_dist[i] = INFTY;
    pos_in_heap[i] = -1;

    E[i] = list_new();
    if (i == 0)
        global_ptr_ref = E[i];
}
}

/// dealloca tutte le strutture create da alloca_grafo (o dall'init a griglia
/// in main, che usa la stessa tecnica): libera prima le liste di adiacenza
/// nodo per nodo, poi gli array.
void dealloca_grafo() {
if (n_nodi == 0) return;
for (int i = 0; i < n_nodi; i++) {
node_t *cur = E[i]->head;
while (cur != NULL) {
node_t *nxt = cur->next;
delete cur;
cur = nxt;
}
delete E[i];
}
delete[] E;
delete[] V_visitato;
delete[] V_prev;
delete[] V_dist;
delete[] heap;
delete[] pos_in_heap;
n_nodi = 0;
}

/// aggiunge l'arco orientato u->v di peso w (RIUSA list_insert_front, gia'
/// usata anche per il grafo a griglia)
void aggiungi_arco(int u, int v, float w) {
list_insert_front(E[u], v, w);
}

/// Bellman-Ford.
/// Ritorna 1 se e' stato rilevato un ciclo di peso negativo raggiungibile
/// dalla sorgente, 0 altrimenti.
/// L'algoritmo si basa sul "rilassamento" degli archi. "rilassare" un arco significa
/// trovare la distanza minima dal nodo di partenza. L'algoritmo effettua V - 1 iterazioni
//(dove V è il numero di nodi) e ad ogni iterazione
int bellman_ford(int sorgente) {
///inizializzo i dati
for (int i = 0; i < n_nodi; i++) {
V_dist[i] = INFTY;
V_prev[i] = -1;
V_visitato[i] = 0;
}
V_dist[sorgente] = 0;

for (int iter = 0; iter < n_nodi - 1; iter++) {
    int cambiato = 0; /// se in una intera passata nessun arco viene
                       /// rilassato, posso fermarmi, se no V-1 iterazioni

    for (int u = 0; u < n_nodi; u++) {
        if (V_dist[u] == INFTY) /// nodo non ancora raggiunto: nessun arco
            continue;           /// uscente da lui puo' essere rilassato

        node_t *elem = E[u]->head;
        while (elem != NULL) {
            int v = elem->val;
            float alt = V_dist[u] + elem->w;

            /// RILASSAMENTO
            if (alt < V_dist[v]) {
                V_dist[v] = alt;
                V_prev[v] = u;
                cambiato = 1;

                printf("Bellman-Ford - Rilasso arco %d -> %d: nuova dist[%d] = %f\n", u, v, v, alt);
            }

            elem = elem->next;
        }
    }

    if (!cambiato)
        break;
}

/// iterazione di verifica: se un arco e' ancora rilassabile, c'e' un
/// ciclo di peso negativo raggiungibile dalla sorgente
int ciclo_negativo = 0;
for (int u = 0; u < n_nodi; u++) {
    if (V_dist[u] == INFTY)
        continue;

    node_t *elem = E[u]->head;
    while (elem != NULL) {
        int v = elem->val;
        float alt = V_dist[u] + elem->w;

        if (alt < V_dist[v]) {
            ciclo_negativo = 1;
            printf("Ciclo negativo: l'arco %d -> %d e' ancora rilassabile\n", u, v);
        }
        elem = elem->next;
    }
}

return ciclo_negativo;
}

void stampa_distanze(int sorgente) {
for (int i = 0; i < n_nodi; i++) {
if (V_dist[i] < INFTY)
printf("distanza da %d a %d: %f (prev: %d)\n", sorgente, i, V_dist[i], V_prev[i]);
else
printf("distanza da %d a %d: INF (non raggiungibile)\n", sorgente, i);
}
}

/// TEST: piccolo grafo per testare shortest_path (Dijkstra)
void test_shortest_path() {
dealloca_grafo(); /// libero il grafo usato dal test precedente

alloca_grafo(6);

aggiungi_arco(0, 1, 4);
aggiungi_arco(0, 2, 2);
aggiungi_arco(1, 2, 1);
aggiungi_arco(1, 3, 5);
aggiungi_arco(2, 3, 8);
aggiungi_arco(2, 4, 10);
aggiungi_arco(3, 4, 2);
aggiungi_arco(3, 5, 6);
aggiungi_arco(4, 5, 3);

shortest_path(0);

printf("\nShortest path (Dijkstra), cammini minimi su grafo di test:\n");
stampa_distanze(0);
}

/// TEST 1: grafo con un arco di peso negativo, ma SENZA cicli negativi
void test_bellman_ford_arco_negativo() {
dealloca_grafo(); /// libero il grafo usato dal test precedente

alloca_grafo(5);

aggiungi_arco(0, 1, 4);
aggiungi_arco(0, 2, 5);
aggiungi_arco(1, 2, -3); /// unico arco di peso negativo
aggiungi_arco(1, 3, 6);
aggiungi_arco(2, 3, 4);
aggiungi_arco(3, 4, 2);

int ciclo_negativo = bellman_ford(0);

if (ciclo_negativo)
    printf("ERRORE: rilevato (erroneamente) un ciclo negativo\n");
else {
    printf("\nNessun ciclo negativo, cammini minimi corretti:\n");
    stampa_distanze(0);
}
}

/// TEST 2: grafo con un CICLO di archi TUTTI di peso negativo, raggiungibile
/// dalla sorgente. Bellman-Ford deve accorgersene e segnalarlo (le distanze
/// dei nodi sul ciclo, o raggiungibili da esso, non sono ben definite: si
/// potrebbero diminuire all'infinito percorrendo il ciclo piu' volte).
void test_bellman_ford_ciclo_negativo() {
dealloca_grafo();

alloca_grafo(4);

aggiungi_arco(0, 1, 1);
aggiungi_arco(1, 2, -1);
aggiungi_arco(2, 3, -1);
aggiungi_arco(3, 1, -1); /// chiude il ciclo 1->2->3->1, peso totale -3

int ciclo_negativo = bellman_ford(0);

if (ciclo_negativo)
    printf("\nRilevato correttamente un ciclo di peso negativo: le distanze calcolate NON sono attendibili\n");
else
    printf("\nERRORE: il ciclo negativo non e' stato rilevato\n");
}
//////////////////////////////////////////////////
/// Fine Bellman-Ford
//////////////////////////////////////////////////

int parse_cmd(int argc, char **argv) {
int ok_parse = 0;
for (int i = 1; i < argc; i++) {
if (argv[i][1] == 'v') {
details = 1;
ok_parse = 1;
}
}

if (argc > 1 && !ok_parse) {
    printf("Usage: %s [Options]\n", argv[0]);
    printf("Options:\n");
    printf("  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n");
    return 1;
}

return 0;
}

int main(int argc, char **argv) {
srand((unsigned)time(NULL));

if (parse_cmd(argc, argv))
    return 1;

int N = 8;
int n_nodi_grid = N * N;

alloca_grafo(n_nodi_grid);

for (int i = 0; i < n_nodi; i++) {
    int x = i % N;
    int y = i / N;

    for (int dx = -2; dx <= 2; dx += 1)
        for (int dy = -2; dy <= 2; dy += 1)
            if ((abs(dx) + abs(dy) >= 1 &&
                 abs(dx) + abs(dy) <= 2 &&
                 abs(dx) < 2 &&
                 abs(dy) < 2) ||
                ((abs(dx) == 2 && abs(dy) == 1) ||
                 (abs(dx) == 1 && abs(dy) == 2))) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < N &&
                    ny >= 0 && ny < N) {
                    int j = nx + N * ny;
                    list_insert_front(E[i], j, 15 * sqrt(dx * dx + dy * dy));
                }
            }
}

int arrivo = n_nodi - 1;

for (int i = 0; i < n_nodi; i++) {
    printf("Sono il nodo di indice %d nell'array\n", i);
    printf("La lista di adiacenza e'\n");
    list_print(E[i]);
}

// Calcolo del percorso sulla griglia prima che venga cancellata nei test
shortest_path(0);
printf("\n--> Distanza calcolata per il nodo di arrivo (%d) sulla griglia: %f\n", arrivo, V_dist[arrivo]);

printf("\n\n========================================\n");
printf("TEST DIJKSTRA: Grafo di esempio\n");
printf("========================================\n");
test_shortest_path();

printf("\n\n========================================\n");
printf("TEST BELLMAN-FORD: grafo con un arco negativo (nessun ciclo negativo)\n");
printf("========================================\n");
test_bellman_ford_arco_negativo();

printf("\n\n========================================\n");
printf("TEST BELLMAN-FORD: grafo con un ciclo di peso negativo\n");
printf("========================================\n");
test_bellman_ford_ciclo_negativo();

dealloca_grafo(); /// libero l'ultimo grafo allocato

return 0;
}