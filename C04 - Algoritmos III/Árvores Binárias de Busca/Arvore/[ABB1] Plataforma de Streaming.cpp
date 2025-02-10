#include <iostream>
#include <string>
using namespace std;

// Estrutura para armazenar as informa��es de um filme
struct node {
    string nome;
    string genero;
    int duracao;        // Em minutos
    int classificacao;  // Idade m�nima
    int ano;
    node* left;        // Sub�rvore esquerda
    node* right;       // Sub�rvore direita
};

// Fun��o para inserir um filme na �rvore
void inserir(node*& curr, const string& nome, const string& genero, int duracao, int classificacao, int ano) {
    if (curr == NULL) {
        curr = new node{nome, genero, duracao, classificacao, ano, NULL, NULL};
    } else if (nome < curr->nome) {
        inserir(curr->left, nome, genero, duracao, classificacao, ano);
    } else if (nome > curr->nome) {
        inserir(curr->right, nome, genero, duracao, classificacao, ano);
    } else {
        cout << "Filme j� inserido." << endl;  // Caso de nomes duplicados
    }
}

// Fun��o para buscar um filme pelo nome
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

// Fun��o para liberar a mem�ria da �rvore
void destruir(node*& curr) {
    if (curr != NULL) {
        destruir(curr->left);
        destruir(curr->right);
        delete curr;
        curr = NULL;
    }
}


int main() {
    node* root = NULL;  // Ponteiro para a raiz da �rvore
    int opcao;

    do {
        cin >> opcao;
        if (opcao == 1) {
            // Inserir um filme
            string nome, genero;
            int duracao, classificacao, ano;
            cin.ignore();  // Ignorar o \n restante do �ltimo input
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
            // Opera��o inv�lida
            cout << "Operacao invalida" << endl;
        }
    } while (opcao != 0);

    destruir(root);  // Libera a mem�ria ao sair do programa
    return 0;
}
