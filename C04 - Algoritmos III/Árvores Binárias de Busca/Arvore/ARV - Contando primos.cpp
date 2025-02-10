#include <iostream>
using namespace std;

struct node {
    int info;
    node *left, *right;
};

// Fun��o para inserir um n�mero na �rvore bin�ria de busca
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

// Fun��o para verificar se um n�mero � primo
bool isPrime(int num) {
    if (num <= 1) return false;  // 0 e 1 n�o s�o primos
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;  // se for divis�vel por i, n�o � primo
    }
    return true;
}

// Fun��o para percorrer a �rvore e contar os n�meros primos
int contaPrimos(node *curr) {
    if (curr == NULL) return 0;
    int count = 0;
    if (isPrime(curr->info)) {
        count = 1;
    }
    // Recurs�o em ambos os filhos da �rvore
    count += contaPrimos(curr->left);
    count += contaPrimos(curr->right);
    return count;
}

int main() {
    node *root = NULL;
    int num;

    // Leitura dos n�meros at� -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Chamada da fun��o que conta os n�meros primos e exibe o resultado
    int primos = contaPrimos(root);
    cout << primos << " numeros primos" << endl;

    return 0;
}
