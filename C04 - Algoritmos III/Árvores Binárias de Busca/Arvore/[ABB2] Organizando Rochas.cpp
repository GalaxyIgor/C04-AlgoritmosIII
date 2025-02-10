#include <iostream>
#include <string>
using namespace std;

// Estrutura do nó para armazenar o nome e o tipo da rocha
struct node {
    string nome;
    string tipo;
    node* left;
    node* right;
};

// Função para inserir uma nova rocha na árvore
void insert(node*& curr, string nome, string tipo) {
    if (curr == NULL) {
        curr = new node;
        curr->nome = nome;
        curr->tipo = tipo;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (nome < curr->nome) {
            insert(curr->left, nome, tipo);
        } else {
            insert(curr->right, nome, tipo);
        }
    }
}

// Função para buscar uma rocha pelo nome
node* search(node* curr, string nome) {
    if (curr == NULL)
        return NULL;
    if (curr->nome == nome)
        return curr;
    if (nome < curr->nome) {
        return search(curr->left, nome);
    } else {
        return search(curr->right, nome);
    }
}

// Função auxiliar para encontrar o menor nó na subárvore
node* point_smaller(node*& curr) {
    if (curr->left == NULL) {
        node* aux = curr;
        curr = curr->right;
        return aux;
    } else {
        return point_smaller(curr->left);
    }
}

// Função para remover uma rocha da árvore pelo nome e tipo
bool remove(node*& curr, string nome, string tipo) {
    if (curr == NULL)
        return false;
    if (curr->nome == nome && curr->tipo == tipo) {
        node* aux = curr;
        if (curr->left == NULL)
            curr = curr->right;
        else if (curr->right == NULL)
            curr = curr->left;
        else {
            aux = point_smaller(curr->right);
            curr->nome = aux->nome;
            curr->tipo = aux->tipo;
        }
        delete aux;
        return true;
    } else if (nome < curr->nome) {
        return remove(curr->left, nome, tipo);
    } else {
        return remove(curr->right, nome, tipo);
    }
}

// Função para liberar toda a memória alocada pela árvore
void destruct(node*& curr) {
    if (curr != NULL) {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

int main() {
    node* root = NULL;
    int op;

    do {
        cin >> op;

        if (op == 1) { // Inserir
            string nome, tipo;
            cin >> nome >> tipo;
            insert(root, nome, tipo);
        } else if (op == 2) { // Pesquisar
            string nome;
            cin >> nome;
            node* resultado = search(root, nome);

            if (resultado != NULL) {
                cout << "Nome: " << resultado->nome << endl;
                cout << "Tipo: " << resultado->tipo << endl;
            } else {
                cout << "Rocha nao encontrada" << endl;
            }
        } else if (op == 3) { // Remover
            string nome, tipo;
            cin >> nome >> tipo;
            if (remove(root, nome, tipo)) {
                cout << "Rocha removida com sucesso" << endl;
            } else {
                cout << "Rocha nao encontrada para remocao" << endl;
            }
        } else if (op != 0) { // Operação inválida
            cout << "Operacao invalida" << endl;
        }
    } while (op != 0);

    destruct(root);
    return 0;
}
