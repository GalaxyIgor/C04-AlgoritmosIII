#include <iostream>
#include <iomanip> // Para configurar a precisão da saída
using namespace std;

// Estrutura do nó da árvore binária
struct node {
    int info;
    node* left;
    node* right;
};

// Função para inserir um número na árvore
void insert(node*& curr, int new_info) {
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

// Função auxiliar para calcular a soma dos elementos e a quantidade de nós na árvore
void calcular_soma_e_contagem(node* curr, int& soma, int& contagem) {
    if (curr != NULL) {
        soma += curr->info;
        contagem++;
        calcular_soma_e_contagem(curr->left, soma, contagem);
        calcular_soma_e_contagem(curr->right, soma, contagem);
    }
}

// Função para calcular a média
float media(node* arvore) {
    int soma = 0, contagem = 0;
    calcular_soma_e_contagem(arvore, soma, contagem);
    if (contagem == 0) {
        return 0.0; // Caso a árvore esteja vazia
    }
    return static_cast<float>(soma) / contagem;
}

// Função para liberar a memória da árvore
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

    // Leitura dos números até encontrar -1
    int num;
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Calcular e exibir a média
    float resultado = media(root);
    cout << fixed << setprecision(2);
    cout << "Media: " << resultado << endl;

    // Liberar a memória
    destruct(root);

    return 0;
}
