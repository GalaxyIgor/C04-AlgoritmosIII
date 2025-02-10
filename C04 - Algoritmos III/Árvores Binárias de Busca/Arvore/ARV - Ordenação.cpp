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

// Função para exibir os elementos da árvore em ordem decrescente
void in_order_desc(node *curr) {
    if (curr != NULL) {
        in_order_desc(curr->right);
        cout << curr->info << " ";
        in_order_desc(curr->left);
    }
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

    // Exibe os números em ordem decrescente
    in_order_desc(root);
    cout << endl;

    // Desaloca a memória da árvore
    destruct(root);

    return 0;
}
