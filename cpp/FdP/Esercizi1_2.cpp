#include<iostream>
#include<cstring>
using namespace std;


bool hasZeroSum (int a[], int dim) {

    int somma = 0;
    
   for (int i = 0; i < dim; i++) {

        somma = a[i];

        for (int j = i + 1; j < dim; j++) {

           
            somma += a[j];

            if (somma == 0){

                return true;
            }
        }
   
}
return false;
}

int countUnique (char* str, int dim) {

    int count = 0;
    int c = 0;
    char lettera;

    for (int i = 0; i < dim; i++) {
        c = 0;
        lettera = str[i];

        for (int j = 0; j < dim; j++) {

            if (lettera == str[j]) {

                c++;
            }
        }
        if (c == 1) {

            count++;
        }
    }

    return count;
}
int findLongest (char* str) {

    int len;
    int c = 0;
    int conta = 0;

    while (*str != '\0') {

        

       if (*str != ' ' ) {
        c++;
       }
       else {

      
        if (conta < c) {

            conta = c;
        }
       c = 0;
        }
        str++;
    }

    return conta;
}

char * replace_spaces (char* str) {

char* start = str;
    while (*str != '\0') {

        if (*str == ' ') {

            *str = '_';
        }
        str++;
    }
    return start;
}
int coincide (int a[], int dim) {

int somma = 0;
int cont = 0;
    for (int i = 0; i < dim; i++) {
        

        somma = a[i];

        for (int j = i + 1; j < dim; j++) {

            somma = somma + a[j];
            if (somma == 0) {
                cont++;
            }
        }

    }

    return cont;
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
   
void rotate (int a[], int dim) {

    int fine = a[dim -1 ];

    for (int i = dim - 1; i >= 0; i--) {

    a[i] = a[i - 1];
          
       
    }

    a[0] = fine;

}

int SumK(int arr[], int dim, int k) {

    int c = 0;
    int somma = 0;

    for (int i = 0; i < dim; i++) {

        somma = arr[i];

        for (int j = 0; j < dim; j++) {

            somma += arr[j];

            if (somma == k) {

                c++;
            }
        }
    }

    return c;
}

char* revert (char* str) {

    
    char tmp;

    int inizio = 0;
    int fine = 0;
    
            for ( int i = 0; str[i] != '\0'; i++) {
                fine++;

            }
    fine--;
            while (inizio < fine) {

                tmp = str[inizio];
                str[inizio] = str[fine];
                str[fine] = tmp;
                inizio++;
                fine--;
            }

            return str;
}

int compact (int a[], int dim, int b[]) {

    int dimb = 0;
    b[dimb] = a[0];
    dimb++;
    bool trovato;

    for (int i = 0; i < dim; i++) {

        for (int j = 0; j < dimb; j++) {

            trovato = false;
            if (a[i] != b[j]) {

                trovato = true;
                break;
            }
        }
        if (trovato == true) {

            b[dimb] = a[i];
            dimb++;
        }
    }

    return dimb;
}

int mostFrequent (int a[], int dim) {

    int max = 0;
    int num = 0;
    int freq = 0;
    int freqMax = 0;

    for (int i = 0; i < dim; i++) {

        num = a[i];

        for (int j = 0; j < dim; j++) {

            if(num == a[j]) {

                freq++;
            }
        }

        if (freq > freqMax) {

            freqMax = freq;
            max = num;
        }

        freq = 0;
    }

    return max;
}

char* noVowels (char* str) {
   static char str2[100];   // USO DI STATIC
    int i = 0;
    int dim = 0;
    
    while (str[i] != '\0') {

        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'  ) {

            str2[dim] = str[i];
            dim++;

        }
        i++;
    }

str2[dim] = '\0';

return str2;
}
int main() {

char str[] = "aoaoaoaobbbb";

cout << noVowels(str);

}