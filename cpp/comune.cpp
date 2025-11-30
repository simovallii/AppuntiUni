#include<iostream>
#include<cstring>
using namespace std;


bool comune (char* str1, char str2) {

    bool trovata;

    for (int i = 0; str1[i]!= '\0'; i++) {

        for (int j; str1[i - 1 + j] != '\0'; j++) {

            char sottostringa[100];
            strcpy(sottostringa, str1 - 1);
            sottostringa[j] = '\n';

            if (strstr(str1, sottostringa) != nullptr) {

                trovata = true;
                cout << "sottostringa = " << sottostringa << endl;
            }
        }
    }
}
int main (){

    char str[101], str2[101];

    cout << "inserire la prima parola" << endl;
    cin.getline(str, 100);

    cout << "inserire seconda parola" << endl;
    cin.getline(str2, 100);
    return 0;
}