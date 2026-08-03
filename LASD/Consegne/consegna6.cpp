#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

// Adattare l'algoritmo di Needleman-Wunsch per ottenere un confronto tra 
// versioni diverse di un codice sorgente. Preparare un test con un file C++ 
// da almeno 100 righe. L'obiettivo è quello di dare priorità alla struttura
//  dei blocchi del codice e poi ai caratteri, per ipotizzare un matching 
//  strutturale dei vari body annidati. E' possibile processare i token e 
//  considerarli come singoli caratteri con una adeguata funzione di scoring. 
//  L'obiettivo è essere tolleranti a testi modificati (es. rinomina di variabili) 
//  ma non confondere un identificatore con un numero. Opzionale: gli spazi/tab 
//  invece possono essere aggiunti o tolti senza penalità. L'output deve indicare 
//  i cambiamenti effettuati, come lista di azioni o stringa di cambiamento 
//  (- per cancellazione e caratteri aggiunti o modificati) 

// ==========================================
// 1. STRUTTURE DATI E DEFINIZIONI
// ==========================================

enum TokenType {
    TYPE_STRUCTURAL, // parentesi, punti e virgola (es. { } ( ) ; )
    TYPE_KEYWORD,    // parole chiave (es. int, if, while)
    TYPE_IDENTIFIER, // nomi di variabili, funzioni
    TYPE_NUMBER,     // valori numerici
    TYPE_OPERATOR,   // operatori (es. +, -, =, <, >)
    TYPE_UNKNOWN
};

struct Token {
    TokenType type;
    char text[64];
};

//funzioni per tokenizzare il file

bool is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_structural(char c) {
    return c == '{' || c == '}' || c == '(' || c == ')' || c == ';' || c == '[' || c == ']' || c == ',';
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '&' || c == '|' || c == '!';
}

bool is_keyword(const char* str) {
    const char* keywords[] = {"int", "void", "if", "else", "while", "for", "return", "class", "public", "private", "struct", "new", "delete"};
    int num_keywords = 13;
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) return true;
    }
    return false;
}

// Estrae i token da un file sorgente ignorando spazi e tab
Token* tokenize_file(const char* filename, int& num_tokens) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Errore apertura file " << filename << endl;
        num_tokens = 0;
        return NULL;
    }

    // allocazione di array di token
    int max_tokens = 5000;
    Token* tokens = new Token[max_tokens];
    num_tokens = 0;

    char c;
    while (file.get(c)) {
        if (is_space(c)) continue; // Spazi e tab vengono scartati senza penalità

        Token t;
        int idx = 0;

        if (is_structural(c)) {
            t.type = TYPE_STRUCTURAL; // identifica il tipo del token
            t.text[0] = c; t.text[1] = '\0';
            tokens[num_tokens++] = t;
        } 
        else if (is_operator(c)) {
            t.type = TYPE_OPERATOR; // identifica il tipo del token
            t.text[idx++] = c;
            // gestisce operatori doppi tipo == o <=
            char next_c = file.peek(); //legge senza scorrere il cursore
            if (is_operator(next_c)) {
                t.text[idx++] = next_c;
                file.get(c);
            }
            t.text[idx] = '\0';
            tokens[num_tokens++] = t;
        }
        else if (is_alpha(c)) {
            t.text[idx++] = c;
            while (file.get(c)) {
                if (is_alpha(c) || is_digit(c)) { //forma le parole e li mette in un unico token (if, else, variabili ecc.)
                    if (idx < 63) t.text[idx++] = c;
                } else {
                    file.putback(c); //rimette nel file, verra utilizzato dopo
                    break;
                }
            }
            t.text[idx] = '\0';
            t.type = is_keyword(t.text) ? TYPE_KEYWORD : TYPE_IDENTIFIER; //se è una variabile diventa TYPE_IDENTIFIER, se no viene identificata la keyword
            tokens[num_tokens++] = t;
        }
        else if (is_digit(c)) { //forma i numeri a più cifre
            t.text[idx++] = c;
            while (file.get(c)) {
                if (is_digit(c) || c == '.') {
                    if (idx < 63) t.text[idx++] = c;
                } else {
                    file.putback(c); //rimette nel file, verra utilizzato dopo
                    break;
                }
            }
            t.text[idx] = '\0';
            t.type = TYPE_NUMBER;  // identifica il tipo del token
            tokens[num_tokens++] = t;
        }
    }
    file.close();
    return tokens;
}

// Needleman-Wunsch adattato

// Funzione di scoring per allineamento strutturale
int fscore(Token t1, Token t2) {
    // Match esatto
    if (t1.type == t2.type && strcmp(t1.text, t2.text) == 0) {
        if (t1.type == TYPE_STRUCTURAL) return 20; // Massima priorità alla struttura
        if (t1.type == TYPE_KEYWORD) return 15;    // Alta priorità alle parole chiave
        return 10; // Match esatto su identificatori o numeri
    }
    
    // Mismatch tollerato (stesso tipo ma testo diverso)
    if (t1.type == t2.type) {
        if (t1.type == TYPE_IDENTIFIER) return 5;  // Probabile rinomina di variabile
        if (t1.type == TYPE_NUMBER) return 2;      // Numero cambiato
        if (t1.type == TYPE_OPERATOR) return 2;    // Operatore cambiato (es. + in -)
        if (t1.type == TYPE_STRUCTURAL) return -10; // Strutture diverse (es. { vs ( ) non devono matchare
    }

    // Mismatch totale (tipi diversi: es. Identificatore vs Numero)
    return -10;
}

// Algoritmo riadattato dal codice di lezione
void allinea_codice(Token* seq1, int s1, Token* seq2, int s2) {
    int costo_indel = -5; // Penalità per inserimento/cancellazione
    
    // Allocazione matrici come viste a lezione
    int** M = new int*[s1 + 1];
    char** P = new char*[s1 + 1];
    for (int i = 0; i < s1 + 1; i++) {
        M[i] = new int[s2 + 1];  //matrice dei punteggi, dice quanto è buono l'allineamento
        P[i] = new char[s2 + 1]; //char per efficienza di memoria
        // P dice il percorso fatto per ottenere il punteggio in M
    }

    // Setup per Needleman-Wunsch 
    M[0][0] = 0;
    P[0][0] = -1;
    for (int i = 1; i < s1 + 1; i++) {
        M[i][0] = i * costo_indel;
        P[i][0] = 0; // 0: vengo da sopra (i - 1)
    }
    for (int j = 1; j < s2 + 1; j++) {
        M[0][j] = j * costo_indel;
        P[0][j] = 1; // 1: vengo da sinistra (j - 1)
    }

    // Popolamento Matrice DP
    for (int i = 1; i < s1 + 1; i++) {
        for (int j = 1; j < s2 + 1; j++) {
            int score = fscore(seq1[i - 1], seq2[j - 1]);
            
            int match_val = M[i - 1][j - 1] + score;
            int delete_val = M[i - 1][j] + costo_indel;
            int insert_val = M[i][j - 1] + costo_indel;
            
            //PER TRACEBAK: 2 diagonale (match), 1 sinistra (inserimento), 0 alto (cancellazione)
            int max_val = match_val;  // trova il max
            P[i][j] = 2; // diagonale 

            if (delete_val > max_val) {
                max_val = delete_val;
                P[i][j] = 0; // alto
            }
            if (insert_val > max_val) {
                max_val = insert_val;
                P[i][j] = 1; // sinistra
            }
            
            M[i][j] = max_val;
        }
    }

    // Traceback e memorizzazione output 
    // Seguo le "frecce"
   int i = s1, j = s2;
    int max_ops = s1 + s2;
    bool* is_changed = new bool[max_ops]; // true se modificato/aggiunto/cancellato, false se invariato
    Token* op_tokens = new Token[max_ops];
    int op_idx = 0;

    while (i > 0 || j > 0) {
        if (P[i][j] == 2) { // Diagonale
            if (strcmp(seq1[i - 1].text, seq2[j - 1].text) == 0) {
                is_changed[op_idx] = false; // Match esatto
            } else {
                is_changed[op_idx] = true; // Modifica tollerata (es. variabile rinominata)
            }
            op_tokens[op_idx] = seq2[j - 1]; // mostriamo il nuovo
            i--; j--; //mi sposto in diagonale
        } else if (P[i][j] == 0) { // Sopra (Cancellato dal file 1)
            is_changed[op_idx] = true;
            op_tokens[op_idx] = seq1[i - 1];
            i--; //mi sposto sopra
        } else if (P[i][j] == 1) { // Sinistra (Aggiunto nel file 2)
            is_changed[op_idx] = true;
            op_tokens[op_idx] = seq2[j - 1];
            j--; //mi sposto a sinistra
        }
        op_idx++;
    }

    // Stampa dal primo all'ultimo (invertendo l'array, poichè calcolato bottom-up)
    cout << "\n=== RISULTATO ALLINEAMENTO STRUTTURALE ===\n";
    cout << "Legenda: [ ] Invariato | [-] Cambiamento (aggiunta, rimozione o modifica)\n\n";
    
    int cols = 0;
    for (int k = op_idx - 1; k >= 0; k--) {
        if (is_changed[k]) {
            cout << "\n[- " << op_tokens[k].text << "] ";
            cols = 0; // conta i token stampati sulla stessa riga
        } else {
            cout << op_tokens[k].text << " ";
            cols++;
        }
        
        // A capo per simulare una struttura base
        if (op_tokens[k].type == TYPE_STRUCTURAL && (op_tokens[k].text[0] == ';' || op_tokens[k].text[0] == '{' || op_tokens[k].text[0] == '}')) {
            cout << "\n";  //se il token è del tipo STRUCTURAL allora va a capo
            cols = 0;
        } else if (cols > 15) { // se i token nella stessa riga sono 16+ va a capo
            cout << "\n";
            cols = 0;
        }
    }
    cout << "\n";

    // Deallocazione
    for (int x = 0; x < s1 + 1; x++) {
        delete[] M[x];
        delete[] P[x];
    }
    delete[] M;
    delete[] P;
    delete[] is_changed;
    delete[] op_tokens;
}


// ==========================================
// 4. GENERAZIONE FILE DI TEST E MAIN
// ==========================================

void crea_file_test() {
   
    ofstream f1("test1.cpp");
    f1 << "class Node {\n"
       << "public:\n"
       << "    int val;\n"
       << "    Node* next;\n"
       << "};\n"
       << "\n"
       << "class LinkedList {\n"
       << "private:\n"
       << "    Node* head;\n"
       << "    int count;\n"
       << "public:\n"
       << "    LinkedList() {\n"
       << "        head = 0;\n"
       << "        count = 0;\n"
       << "    }\n"
       << "    void insert(int v) {\n"
       << "        Node* n = new Node;\n"
       << "        n->val = v;\n"
       << "        n->next = head;\n"
       << "        head = n;\n"
       << "        count++;\n"
       << "    }\n"
       << "    void remove(int v) {\n"
       << "        Node* temp = head;\n"
       << "        Node* prev = 0;\n"
       << "        while (temp != 0) {\n"
       << "            if (temp->val == v) {\n"
       << "                if (prev != 0) {\n"
       << "                    prev->next = temp->next;\n"
       << "                } else {\n"
       << "                    head = temp->next;\n"
       << "                }\n"
       << "                delete temp;\n"
       << "                count--;\n"
       << "                return;\n"
       << "            }\n"
       << "            prev = temp;\n"
       << "            temp = temp->next;\n"
       << "        }\n"
       << "    }\n"
       << "    int getSize() {\n"
       << "        return count;\n"
       << "    }\n"
       << "    void display() {\n"
       << "        Node* temp = head;\n"
       << "        while (temp != 0) {\n"
       << "            temp = temp->next;\n"
       << "        }\n"
       << "    }\n"
       << "};\n"
       << "\n"
       << "struct TreeNode {\n"
       << "    int data;\n"
       << "    TreeNode* left;\n"
       << "    TreeNode* right;\n"
       << "};\n"
       << "\n"
       << "TreeNode* createNode(int value) {\n"
       << "    TreeNode* newNode = new TreeNode;\n"
       << "    newNode->data = value;\n"
       << "    newNode->left = 0;\n"
       << "    newNode->right = 0;\n"
       << "    return newNode;\n"
       << "}\n"
       << "\n"
       << "TreeNode* insertTree(TreeNode* root, int value) {\n"
       << "    if (root == 0) return createNode(value);\n"
       << "    if (value < root->data) {\n"
       << "        root->left = insertTree(root->left, value);\n"
       << "    } else {\n"
       << "        root->right = insertTree(root->right, value);\n"
       << "    }\n"
       << "    return root;\n"
       << "}\n"
       << "\n"
       << "TreeNode* searchTree(TreeNode* root, int value) {\n"
       << "    if (root == 0 || root->data == value) {\n"
       << "        return root;\n"
       << "    }\n"
       << "    if (value < root->data) {\n"
       << "        return searchTree(root->left, value);\n"
       << "    }\n"
       << "    return searchTree(root->right, value);\n"
       << "}\n"
       << "\n"
       << "void inorder(TreeNode* root) {\n"
       << "    if (root != 0) {\n"
       << "        inorder(root->left);\n"
       << "        inorder(root->right);\n"
       << "    }\n"
       << "}\n"
       << "\n"
       << "void preorder(TreeNode* root) {\n"
       << "    if (root != 0) {\n"
       << "        preorder(root->left);\n"
       << "        preorder(root->right);\n"
       << "    }\n"
       << "}\n"
       << "\n"
       << "int main() {\n"
       << "    LinkedList list;\n"
       << "    for(int i = 0; i < 100; i++) {\n"
       << "        list.insert(i);\n"
       << "    }\n"
       << "    list.remove(50);\n"
       << "    int size = list.getSize();\n"
       << "    \n"
       << "    TreeNode* root = 0;\n"
       << "    root = insertTree(root, 50);\n"
       << "    root = insertTree(root, 30);\n"
       << "    root = insertTree(root, 20);\n"
       << "    root = insertTree(root, 40);\n"
       << "    root = insertTree(root, 70);\n"
       << "    root = insertTree(root, 60);\n"
       << "    root = insertTree(root, 80);\n"
       << "    \n"
       << "    inorder(root);\n"
       << "    preorder(root);\n"
       << "    \n"
       << "    TreeNode* found = searchTree(root, 40);\n"
       << "    return 0;\n"
       << "}\n";
    f1.close();

   
    ofstream f2("test2.cpp");
    f2 << "class ListNode {\n"
       << "public:\n"
       << "    int value;\n"
       << "    ListNode* ptrNext;\n"
       << "};\n"
       << "\n"
       << "class LinkedList {\n"
       << "private:\n"
       << "    ListNode* head;\n"
       << "    int totalItems;\n"
       << "public:\n"
       << "    LinkedList() {\n"
       << "        head = 0;\n"
       << "        totalItems = 0;\n"
       << "    }\n"
       << "    void insert(int v) {\n"
       << "        ListNode* n = new ListNode;\n"
       << "        n->value = v;\n"
       << "        n->ptrNext = head;\n"
       << "        head = n;\n"
       << "        totalItems++;\n"
       << "    }\n"
       << "    void remove(int v) {\n"
       << "        ListNode* curr = head;\n"
       << "        ListNode* prevNode = 0;\n"
       << "        while (curr != 0) {\n"
       << "            if (curr->value == v) {\n"
       << "                if (prevNode != 0) {\n"
       << "                    prevNode->ptrNext = curr->ptrNext;\n"
       << "                } else {\n"
       << "                    head = curr->ptrNext;\n"
       << "                }\n"
       << "                delete curr;\n"
       << "                totalItems--;\n"
       << "                return;\n"
       << "            }\n"
       << "            prevNode = curr;\n"
       << "            curr = curr->ptrNext;\n"
       << "        }\n"
       << "    }\n"
       << "    int getSize() {\n"
       << "        return totalItems;\n"
       << "    }\n"
       << "    void display() {\n"
       << "        ListNode* temp = head;\n"
       << "        while (temp != 0) {\n"
       << "            temp = temp->ptrNext;\n"
       << "        }\n"
       << "    }\n"
       << "};\n"
       << "\n"
       << "struct TreeNode {\n"
       << "    int item;\n"
       << "    TreeNode* leftChild;\n"
       << "    TreeNode* rightChild;\n"
       << "};\n"
       << "\n"
       << "TreeNode* createNode(int val) {\n"
       << "    TreeNode* node = new TreeNode;\n"
       << "    node->item = val;\n"
       << "    node->leftChild = 0;\n"
       << "    node->rightChild = 0;\n"
       << "    return node;\n"
       << "}\n"
       << "\n"
       << "TreeNode* insertTree(TreeNode* root, int val) {\n"
       << "    if (root == 0) return createNode(val);\n"
       << "    if (val < root->item) {\n"
       << "        root->leftChild = insertTree(root->leftChild, val);\n"
       << "    } else {\n"
       << "        root->rightChild = insertTree(root->rightChild, val);\n"
       << "    }\n"
       << "    return root;\n"
       << "}\n"
       << "\n"
       << "TreeNode* searchTree(TreeNode* root, int val) {\n"
       << "    if (root == 0 || root->item == val) {\n"
       << "        return root;\n"
       << "    }\n"
       << "    if (val < root->item) {\n"
       << "        return searchTree(root->leftChild, val);\n"
       << "    }\n"
       << "    return searchTree(root->rightChild, val);\n"
       << "}\n"
       << "\n"
       << "void inorder(TreeNode* root) {\n"
       << "    if (root != 0) {\n"
       << "        inorder(root->leftChild);\n"
       << "        inorder(root->rightChild);\n"
       << "    }\n"
       << "}\n"
       << "\n"
       << "void preorder(TreeNode* root) {\n"
       << "    if (root != 0) {\n"
       << "        preorder(root->leftChild);\n"
       << "        preorder(root->rightChild);\n"
       << "    }\n"
       << "}\n"
       << "\n"
       << "int main() {\n"
       << "    LinkedList list;\n"
       << "    for(int idx = 0; idx < 150; idx++) {\n"
       << "        list.insert(idx);\n"
       << "    }\n"
       << "    list.remove(25);\n"
       << "    int len = list.getSize();\n"
       << "    \n"
       << "    TreeNode* root = 0;\n"
       << "    root = insertTree(root, 50);\n"
       << "    root = insertTree(root, 30);\n"
       << "    root = insertTree(root, 20);\n"
       << "    root = insertTree(root, 40);\n"
       << "    root = insertTree(root, 70);\n"
       << "    root = insertTree(root, 60);\n"
       << "    root = insertTree(root, 99);\n"
       << "    \n"
       << "    inorder(root);\n"
       << "    preorder(root);\n"
       << "    \n"
       << "    TreeNode* target = searchTree(root, 99);\n"
       << "    return 1;\n"
       << "}\n";
    f2.close();
}

int main() {
    cout << "Generazione file di test..." << endl;
    crea_file_test();

    int n_tokens1 = 0, n_tokens2 = 0;
    
    cout << "Tokenizzazione file 1" << endl;
    Token* seq1 = tokenize_file("test1.cpp", n_tokens1);
    
    cout << "Tokenizzazione file 2" << endl;
    Token* seq2 = tokenize_file("test2.cpp", n_tokens2);

    if (seq1 != NULL && seq2 != NULL) {
        cout << "Trovati " << n_tokens1 << " tokens in test1.cpp" << endl;
        cout << "Trovati " << n_tokens2 << " tokens in test2.cpp" << endl;
        
        allinea_codice(seq1, n_tokens1, seq2, n_tokens2);
        
        delete[] seq1;
        delete[] seq2;
    }

    return 0;
}