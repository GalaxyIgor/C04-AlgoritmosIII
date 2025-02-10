#include <iostream>
#include <iomanip> // Para configurar a precis�o da sa�da
using namespace std;

// Estrutura do n� da �rvore bin�ria
struct node {
    int info;
    node* left;
    node* right;
};

// Fun��o para inserir um n�mero na �rvore
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

// Fun��o auxiliar para calcular a soma dos elementos e a quantidade de n�s na �rvore
void calcular_soma_e_contagem(node* curr, int& soma, int& contagem) {
    if (curr != NULL) {
        soma += curr->info;
        contagem++;
        calcular_soma_e_contagem(curr->left, soma, contagem);
        calcular_soma_e_contagem(curr->right, soma, contagem);
    }
}

// Fun��o para calcular a m�dia
float media(node* arvore) {
    int soma = 0, contagem = 0;
    calcular_soma_e_contagem(arvore, soma, contagem);
    if (contagem == 0) {
        return 0.0; // Caso a �rvore esteja vazia
    }
    return static_cast<float>(soma) / contagem;
}

// Fun��o para liberar a mem�ria da �rvore
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

    // Leitura dos n�meros at� encontrar -1
    int num;
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Calcular e exibir a m�dia
    float resultado = media(root);
    cout << fixed << setprecision(2);
    cout << "Media: " << resultado << endl;

    // Liberar a mem�ria
    destruct(root);

    return 0;
}
