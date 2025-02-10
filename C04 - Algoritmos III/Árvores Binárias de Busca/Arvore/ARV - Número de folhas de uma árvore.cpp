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

// Função para contar o número de folhas na árvore
int contaFolhas(node *curr) {
    if (curr == NULL) return 0;  // Se a árvore está vazia, retorna 0

    // Se o nó é uma folha (não tem filhos)
    if (curr->left == NULL && curr->right == NULL) {
        return 1;
    }

    // Se não for folha, contar as folhas nas subárvores
    return contaFolhas(curr->left) + contaFolhas(curr->right);
}

int main() {
    node *root = NULL;
    int num;

    // Leitura dos números até -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Chamada da função que conta as folhas e exibe o resultado
    int folhas = contaFolhas(root);
    cout << folhas << endl;

    return 0;
}
