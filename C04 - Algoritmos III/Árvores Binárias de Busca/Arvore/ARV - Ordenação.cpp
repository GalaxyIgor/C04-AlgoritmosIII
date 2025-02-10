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

// Fun��o para exibir os elementos da �rvore em ordem decrescente
void in_order_desc(node *curr) {
    if (curr != NULL) {
        in_order_desc(curr->right);
        cout << curr->info << " ";
        in_order_desc(curr->left);
    }
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

    // Exibe os n�meros em ordem decrescente
    in_order_desc(root);
    cout << endl;

    // Desaloca a mem�ria da �rvore
    destruct(root);

    return 0;
}
