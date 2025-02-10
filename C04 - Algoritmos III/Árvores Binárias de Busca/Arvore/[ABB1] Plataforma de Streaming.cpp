#include <iostream>
#include <string>
using namespace std;

// Estrutura para armazenar as informações de um filme
struct node {
    string nome;
    string genero;
    int duracao;        // Em minutos
    int classificacao;  // Idade mínima
    int ano;
    node* left;        // Subárvore esquerda
    node* right;       // Subárvore direita
};

// Função para inserir um filme na árvore
void inserir(node*& curr, const string& nome, const string& genero, int duracao, int classificacao, int ano) {
    if (curr == NULL) {
        curr = new node{nome, genero, duracao, classificacao, ano, NULL, NULL};
    } else if (nome < curr->nome) {
        inserir(curr->left, nome, genero, duracao, classificacao, ano);
    } else if (nome > curr->nome) {
        inserir(curr->right, nome, genero, duracao, classificacao, ano);
    } else {
        cout << "Filme já inserido." << endl;  // Caso de nomes duplicados
    }
}

// Função para buscar um filme pelo nome
node* buscar(node* curr, const string& nome) {
    if (curr == NULL || curr->nome == nome) {
        return curr;
    }
    if (nome < curr->nome) {
        return buscar(curr->left, nome);
    } else {
        return buscar(curr->right, nome);
    }
}

// Função para liberar a memória da árvore
void destruir(node*& curr) {
    if (curr != NULL) {
        destruir(curr->left);
        destruir(curr->right);
        delete curr;
        curr = NULL;
    }
}


int main() {
    node* root = NULL;  // Ponteiro para a raiz da árvore
    int opcao;

    do {
        cin >> opcao;
        if (opcao == 1) {
            // Inserir um filme
            string nome, genero;
            int duracao, classificacao, ano;
            cin.ignore();  // Ignorar o \n restante do último input
            getline(cin, nome);
            getline(cin, genero);
            cin >> duracao >> classificacao >> ano;
            inserir(root, nome, genero, duracao, classificacao, ano);
        } else if (opcao == 2) {
            // Pesquisar um filme
            string nome;
            cin.ignore();
            getline(cin, nome);
            node* resultado = buscar(root, nome);
            if (resultado != NULL) {
                cout << "Nome: " << resultado->nome << endl;
                cout << "Genero: " << resultado->genero << endl;
                cout << "Duracao: " << resultado->duracao << " mins" << endl;
                cout << "Classificacao: " << resultado->classificacao << endl;
                cout << "Ano: " << resultado->ano << endl;
            } else {
                cout << "Filme nao encontrado" << endl;  // Mensagem corrigida
            }
        } else if (opcao != 0) {
            // Operação inválida
            cout << "Operacao invalida" << endl;
        }
    } while (opcao != 0);

    destruir(root);  // Libera a memória ao sair do programa
    return 0;
}
