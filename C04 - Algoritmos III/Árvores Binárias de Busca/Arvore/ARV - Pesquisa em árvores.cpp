#include<iostream>
using namespace std;

struct node {
    int info;
    node* left, * right;
};

void insert(node*& curr, int new_info) {
    if (curr == NULL) {
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    }
    else {
        if (new_info < curr->info) {
            insert(curr->left, new_info);
        }
        else {
            insert(curr->right, new_info);
        }
    }
}

node* search(node* curr, int searched_info) {
    if (curr == NULL)
        return NULL;
    if (curr->info == searched_info)
        return curr;
    if (searched_info < curr->info) {
        return search(curr->left, searched_info);
    }
    else {
        return search(curr->right, searched_info);
    }
}

int main() {
    int N, X;
    cin >> N;  // Lê a quantidade de números a serem inseridos

    node* root = NULL;
    
    // Lê os N números e os insere na árvore
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        insert(root, num);
    }
    
    cin >> X;  // Lê o número X a ser procurado na árvore
    
    // Realiza a busca e exibe o resultado
    node* result = search(root, X);
    if (result != NULL) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
