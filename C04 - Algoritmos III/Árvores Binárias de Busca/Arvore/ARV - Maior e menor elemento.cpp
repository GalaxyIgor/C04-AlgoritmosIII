#include <iostream>
using namespace std;

// Estrutura de um nó da árvore binária
struct node {
    int info;
    node *left, *right;
};

// Função para inserir elementos na árvore
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

// Função para encontrar o maior elemento da árvore
int maior(node *arvore) {
    while (arvore->right != NULL) {
        arvore = arvore->right;
    }
    return arvore->info;
}

// Função para encontrar o menor elemento da árvore
int menor(node *arvore) {
    while (arvore->left != NULL) {
        arvore = arvore->left;
    }
    return arvore->info;
}

// Função para desalocar a árvore
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

    // Lê os números e insere na árvore até encontrar -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Verifica se a árvore contém elementos antes de calcular o menor e maior
    if (root != NULL) {
        int menor_valor = menor(root);
        int maior_valor = maior(root);
        cout << menor_valor << " e " << maior_valor << endl;
    } else {
        cout << "A árvore está vazia." << endl;
    }

    // Desaloca a memória da árvore
    destruct(root);

    return 0;
}
