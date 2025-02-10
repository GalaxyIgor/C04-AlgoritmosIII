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

// Fun��o para contar o n�mero de folhas na �rvore
int contaFolhas(node *curr) {
    if (curr == NULL) return 0;  // Se a �rvore est� vazia, retorna 0

    // Se o n� � uma folha (n�o tem filhos)
    if (curr->left == NULL && curr->right == NULL) {
        return 1;
    }

    // Se n�o for folha, contar as folhas nas sub�rvores
    return contaFolhas(curr->left) + contaFolhas(curr->right);
}

int main() {
    node *root = NULL;
    int num;

    // Leitura dos n�meros at� -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Chamada da fun��o que conta as folhas e exibe o resultado
    int folhas = contaFolhas(root);
    cout << folhas << endl;

    return 0;
}
