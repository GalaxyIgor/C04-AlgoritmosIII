#include <iostream>
using namespace std;

struct node {
    int info;
    node *left, *right;
};

// Função para inserir um número na árvore binária de busca
void insert(node *&curr, int new_info) {
    if (curr == NULL) {
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (new_info < curr->info) {
            insert(curr->left, new_info);
        } else {
            insert(curr->right, new_info);
        }
    }
}

// Função para verificar se um número é primo
bool isPrime(int num) {
    if (num <= 1) return false;  // 0 e 1 não são primos
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;  // se for divisível por i, não é primo
    }
    return true;
}

// Função para percorrer a árvore e contar os números primos
int contaPrimos(node *curr) {
    if (curr == NULL) return 0;
    int count = 0;
    if (isPrime(curr->info)) {
        count = 1;
    }
    // Recursão em ambos os filhos da árvore
    count += contaPrimos(curr->left);
    count += contaPrimos(curr->right);
    return count;
}

int main() {
    node *root = NULL;
    int num;

    // Leitura dos números até -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Chamada da função que conta os números primos e exibe o resultado
    int primos = contaPrimos(root);
    cout << primos << " numeros primos" << endl;

    return 0;
}
