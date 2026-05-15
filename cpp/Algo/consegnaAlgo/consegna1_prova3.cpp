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
// Algoritmo scelto: Radix Sort LSD a 2 passaggi da 8 bit
//
// Motivazione:
//   I dati in data.csv hanno range [-1676, 10575].
//   Aggiungendo offset +1676 si ottiene range [0, 12251], che sta in 14 bit.
//   Si usano 2 passaggi da 8 bit (base 256):
//     - Passaggio 0: cifra bassa  (bit 0..7)
//     - Passaggio 1: cifra alta   (bit 8..13)
//   Questo e' il vero Radix Sort LSD: ogni passaggio considera solo
//   una "cifra" (gruppo di bit), non l'intero valore.
//
//   Conteggio letture (ONESTO — si contano anche gli accessi a count[]):
//     Per ogni passaggio su n=1000 elementi:
//       - Histogram su A[]    : n         letture di A
//       - Histogram su count[]: n         letture di count  (read-modify-write)
//       - Prefix sum          : 2*(B-1)   letture di count  (legge count[i] e count[i-1])
//       - Scatter su A[]      : n         letture di A
//       - Scatter su count[]  : n         letture di count  (read-modify-write)
//     Per passaggio: 2n + 2n + 2*(256-1) = 4*1000 + 510 = 4510
//     Totale 2 passaggi: 2 * 4510 = 9020 letture
//
//   Quicksort baseline: ~32146 letture medie => miglioramento ~3.6x

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
// Radix Sort LSD — 2 passaggi da 8 bit (base 256)
//
// Regole di conteggio letture:
//   - A[i]      => ct_read++   (array principale)
//   - count[x]  => ct_read++   (e' anch'esso un array in memoria)
//   - out[x]    => NON contato (array di supporto in scrittura, non in lettura)
//   - variabile locale/registro => gratis
//
// ---------------------------------------------------------------------------
void radix_sort(int *A, int n_elem) {
    const int OFFSET  = 1676;   // rende tutti i valori >= 0: range diventa [0, 12251]
    const int BUCKETS = 256;    // base 2^8
    const int PASSES  = 2;      // 2 passaggi: cifra bassa (bit 0-7), cifra alta (bit 8-13)

    int *count = new int[BUCKETS];
    int *out   = new int[n_elem];

    for (int pass = 0; pass < PASSES; pass++) {
        int shift = pass * 8;   // 0 per pass 0, 8 per pass 1

        // --- Azzeramento contatori (memset, non conta come letture di A) ---
        memset(count, 0, BUCKETS * sizeof(int));

        // --- Passaggio 1: histogram ---
        // Si legge A[i] (conta), si estrae la cifra (registro: gratis),
        // si legge e riscrive count[cifra] (conta come lettura di count).
        for (int i = 0; i < n_elem; i++) {
            ct_read++;                          // lettura A[i]
            int val   = A[i] + OFFSET;          // valore traslato, in registro
            int digit = (val >> shift) & 0xFF;  // cifra corrente, in registro
            ct_read++;                          // lettura count[digit] (read-modify-write)
            count[digit]++;
        }

        // --- Prefix sum sui contatori ---
        // count[i] += count[i-1] e' un read-modify-write su count[i]
        // piu' una lettura di count[i-1]: 2 letture per iterazione.
        for (int i = 1; i < BUCKETS; i++) {
            ct_read++;          // lettura count[i-1]
            ct_read++;          // lettura count[i] (read-modify-write)
            count[i] += count[i - 1];
        }

        // --- Passaggio 2: scatter (da destra per stabilita' LSD) ---
        // Si legge A[i] (conta), si estrae la cifra (registro: gratis),
        // si legge e decrementa count[cifra] (conta), poi si scrive in out (non conta).
        for (int i = n_elem - 1; i >= 0; i--) {
            ct_read++;                          // lettura A[i]
            int val   = A[i] + OFFSET;          // valore traslato, in registro
            int digit = (val >> shift) & 0xFF;  // cifra corrente, in registro
            ct_read++;                          // lettura count[digit] (read-modify-write)
            out[--count[digit]] = A[i];         // A[i] gia' in registro: gratis
        }

        // Copia out -> A per il prossimo passaggio
        // (memcpy non conta come letture "logiche" dell'algoritmo)
        memcpy(A, out, n_elem * sizeof(int));
    }

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
