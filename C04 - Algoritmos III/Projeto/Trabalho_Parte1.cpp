#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Estrutura para armazenar uma palavra e seus poss�veis significados
struct Palavra {
    string ficticio;
    string significados[10]; // Limite de at� 10 significados por palavra
    int contador; // Quantidade de significados adicionados
    
    //construtor inicia o contador como 0
    Palavra() : contador(0) {}
};


// Vetor para armazenar as palavras
Palavra palavras[100];
int totalPalavras = 0;


// Fun��o para inserir uma palavra e seu significado
void inserirPalavra(const string& ficticio, const string& portugues) {
    for (int i = 0; i < totalPalavras; i++) {
        if (palavras[i].ficticio == ficticio) {
            // Adiciona o significado se a palavra j� existe
            if (palavras[i].contador < 10) {
                palavras[i].significados[palavras[i].contador++] = portugues;
                cout << "Traducao adicionada para '" << ficticio << "'.\n";
            } else {
                cout << "Limite de significados alcancado para '" << ficticio << "'.\n";
            }
            return;
        }
    }
    // Insere nova palavra no array
    palavras[totalPalavras].ficticio = ficticio;
    palavras[totalPalavras].significados[palavras[totalPalavras].contador++] = portugues;
    totalPalavras++;
    cout << "Palavra '" << ficticio << "' inserida com sucesso.\n";
}


// Fun��o para listar significados de uma palavra fict�cia
void listarSignificados(const string& ficticio) {
    for (int i = 0; i < totalPalavras; ++i) {
        if (palavras[i].ficticio == ficticio) {
            cout << "Significados de '" << ficticio << "':\n";
            for (int j = 0; j < palavras[i].contador; ++j) {
                cout << "- " << palavras[i].significados[j] << "\n";
            }
            return;
        }
    }
    cout << "Palavra '" << ficticio << "' nao encontrada.\n";
}


// Fun��o para buscar a tradu��o de uma palavra fict�cia
void buscarPalavra(const string& ficticio) {
    for (int i = 0; i < totalPalavras; ++i) {
        if (palavras[i].ficticio == ficticio) {
            cout << "Traducoes de '" << ficticio << "': ";
            for (int j = 0; j < palavras[i].contador; ++j) {
                cout << palavras[i].significados[j];
                if (j < palavras[i].contador - 1) cout << ", ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "Palavra '" << ficticio << "' nao encontrada.\n";
}


// Menu para acessar as funcionalidades
void menu() {
    int opcao;
    do {
    	// Mostrando opcoes do Menu
        cout << "\nMenu:\n";
        cout << "1. Inserir palavra\n";
        cout << "2. Listar significados\n";
        cout << "3. Buscar palavra\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        
        //ja tem o tratamento de erro
        // Verificar se a entrada � v�lida
        if (!(cin >> opcao)) {
        	// Mostra ao usuario o erro
            cout << "Entrada invalida. Por favor, digite um numero.\n";
            cin.clear(); // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a linha de entrada inv�lida
            continue; // Volta ao in�cio do loop para tentar novamente
        }

        cin.ignore();  // Limpa o buffer para o getline 

		// IF para escolher uma opcao
        if (opcao == 1) {
            string ficticio, portugues;
            cout << "Digite a palavra ficticia: ";
            getline(cin, ficticio);
            cout << "Digite o significado em portugues: ";
            getline(cin, portugues);
            inserirPalavra(ficticio, portugues);
        }
        else if (opcao == 2) {
            string ficticio;
            cout << "Digite a palavra ficticia para listar significados: ";
            getline(cin, ficticio);
            listarSignificados(ficticio);
        }
        else if (opcao == 3) {
            string ficticio;
            cout << "Digite a palavra ficticia para buscar: ";
            getline(cin, ficticio);
            buscarPalavra(ficticio);
        }
    } while (opcao != 0);
}

// Fun��o Principal
int main() {
	// Chama a fun��o principal
    menu();
    return 0;
}
