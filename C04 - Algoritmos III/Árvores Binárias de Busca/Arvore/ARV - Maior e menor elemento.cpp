#include <iostream>
using namespace std;

// Estrutura de um n� da �rvore bin�ria
struct node {
    int info;
    node *left, *right;
};

// Fun��o para inserir elementos na �rvore
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

// Fun��o para encontrar o maior elemento da �rvore
int maior(node *arvore) {
    while (arvore->right != NULL) {
        arvore = arvore->right;
    }
    return arvore->info;
}

// Fun��o para encontrar o menor elemento da �rvore
int menor(node *arvore) {
    while (arvore->left != NULL) {
        arvore = arvore->left;
    }
    return arvore->info;
}

// Fun��o para desalocar a �rvore
void destruct(node *&curr) {
    if (curr != NULL) {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

int main() {
    node *root = NULL;
    int num;

    // L� os n�meros e insere na �rvore at� encontrar -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Verifica se a �rvore cont�m elementos antes de calcular o menor e maior
    if (root != NULL) {
        int menor_valor = menor(root);
        int maior_valor = maior(root);
        cout << menor_valor << " e " << maior_valor << endl;
    } else {
        cout << "A �rvore est� vazia." << endl;
    }

    // Desaloca a mem�ria da �rvore
    destruct(root);

    return 0;
}
