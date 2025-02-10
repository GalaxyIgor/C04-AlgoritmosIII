#include<iostream>
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

// Fun��o para percorrer a �rvore em Pr�-Ordem
bool pre_order(node *curr, int city) {
    if (curr == NULL) return false;
    if (curr->info == city) return true;
    if (pre_order(curr->left, city)) return true;
    return pre_order(curr->right, city);
}

// Fun��o para percorrer a �rvore em Em-Ordem
bool in_order(node *curr, int city) {
    if (curr == NULL) return false;
    if (in_order(curr->left, city)) return true;
    if (curr->info == city) return true;
    return in_order(curr->right, city);
}

// Fun��o para percorrer a �rvore em P�s-Ordem
bool post_order(node *curr, int city) {
    if (curr == NULL) return false;
    if (post_order(curr->left, city)) return true;
    if (post_order(curr->right, city)) return true;
    if (curr->info == city) return true;
    return false;
}

int main() {
    node *root = NULL;
    int num;

    // Leitura das cidades at� -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Leitura da cidade X onde est� o chocolate
    int city;
    cin >> city;

    // Verificar qual o caminho mais r�pido
    if (pre_order(root, city)) {
        cout << "Pre" << endl;
    } else if (in_order(root, city)) {
        cout << "Em" << endl;
    } else if (post_order(root, city)) {
        cout << "Pos" << endl;
    }

    return 0;
}
