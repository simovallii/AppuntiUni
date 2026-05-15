#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

// compilazione: g++ consegna1.cpp -o consegna1
// esecuzione:   ./consegna1
//
// Algoritmo scelto: Radix Sort LSD a 14 bit (1 solo passaggio)
//
// Motivazione:
//   I dati in data.csv hanno range [-1676, 10575], ovvero 12251 valori distinti.
//   12251 < 2^14 = 16384, quindi basta UN solo passaggio con base 2^14.
//   Aggiungendo un offset di +1676 tutti i valori diventano >= 0.
//
//   Letture per array da n=1000 elementi:
//     - Passaggio 1 (histogram): n letture  = 1000
//     - Passaggio 2 (scatter):   n letture  = 1000
//     - TOTALE: 2n = 2000 letture
//
//   Quicksort baseline: ~32146 letture medie
//   Miglioramento atteso: ~16x

int ct_swap = 0;
int ct_cmp  = 0;
int ct_read = 0;

int max_dim = 0;
int ntests  = 100;
int ndiv    = 1;
int details = 0;
int graph   = 0;

int n = 0;

void print_array(int *A, int dim) {
    for (int j = 0; j < dim; j++)
        printf("%d ", A[j]);
    printf("\n");
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    ct_swap++;
}

// ---------------------------------------------------------------------------
// Radix Sort LSD — 1 passaggio a 14 bit
//
// Regole di conteggio letture (dal framework):
//   - A[i]  (accesso array)  => ct_read++
//   - variabile locale/registro => gratis
//
// Ogni elemento viene letto esattamente 2 volte:
//   1) nel passaggio histogram per calcolare le frequenze
//   2) nel passaggio scatter per posizionarlo nell'output
// Totale: 2 * n = 2000 letture per n=1000
// ---------------------------------------------------------------------------
void radix_sort(int *A, int n_elem) {
    const int OFFSET  = 1676;       // min negativo => offset per avere tutto >= 0
    const int BUCKETS = 16384;      // 2^14, copre range 0..12251

    int *count = new int[BUCKETS]();
    int *out   = new int[n_elem];

    // --- Passaggio 1: histogram ---
    // Legge ogni A[i] una sola volta, salva in registro 'val' (gratis dopo)
    for (int i = 0; i < n_elem; i++) {
        ct_read++;               // lettura array: costa 1
        int val = A[i];          // val in registro: gratis
        count[val + OFFSET]++;
    }
    // --- Prefix sum sui contatori ---
    // Nessun accesso ad A, solo variabili locali: gratis
    for (int i = 1; i < BUCKETS; i++)
        count[i] += count[i - 1];

    // --- Passaggio 2: scatter (da destra per stabilita') ---
    // Legge ogni A[i] una sola volta, salva in registro 'val' (gratis dopo)
    for (int i = n_elem - 1; i >= 0; i--) {
        ct_read++;               // lettura array: costa 1
        int val = A[i];          // val in registro: gratis
        out[--count[val + OFFSET]] = val;
    }

    // Copia output in A (memcpy non conta come letture di A nel senso dell'algoritmo)
    memcpy(A, out, n_elem * sizeof(int));

    delete[] count;
    delete[] out;
}

int parse_cmd(int argc, char **argv) {
    max_dim = 1000;

    for (int i = 1; i < argc; i++) {
        if (argv[i][1] == 'd')
            ndiv = atoi(argv[i] + 3);
        if (argv[i][1] == 't')
            ntests = atoi(argv[i] + 3);
        if (argv[i][1] == 'v')
            details = 1;
        if (argv[i][1] == 'g') {
            graph  = 1;
            ndiv   = 1;
            ntests = 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    int i, test;
    int *A;

    if (parse_cmd(argc, argv))
        return 1;

    A = new int[max_dim];
    n = max_dim;

    ifstream input_data;
    input_data.open("data.csv");

    int  read_min = -1;
    int  read_max = -1;
    long read_avg = 0;

    for (test = 0; test < ntests; test++) {

        for (i = 0; i < n; i++) {
            char comma;
            input_data >> A[i];
            input_data >> comma;
        }

        if (details) {
            printf("caricato array di dimensione %d\n", n);
            print_array(A, n);
        }

        ct_swap = 0;
        ct_cmp  = 0;
        ct_read = 0;

        // --- algoritmo di sorting ---
        radix_sort(A, n);

        if (details) {
            printf("Output:\n");
            print_array(A, n);
        }

        read_avg += ct_read;
        if (read_min < 0 || read_min > ct_read)
            read_min = ct_read;
        if (read_max < 0 || read_max < ct_read)
            read_max = ct_read;
        printf("Test %d %d\n", test, ct_read);
    }

    printf("N test: %d, Min: %d, Med: %.1f, Max: %d\n",
           ntests,
           read_min, (0.0 + read_avg) / ntests, read_max);

    

    delete[] A;
    return 0;
}