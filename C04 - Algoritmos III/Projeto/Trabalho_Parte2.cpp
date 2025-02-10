#include <iostream>
#include <string>
#include <cmath> // Para cálculos de distância
#include <limits>

using namespace std;

struct Palavra {
    string ficticio;
    string significados[10];
    int adj[10];
    int contadorSignificados;
    int contadorAdj;
    float x, y, z;

    Palavra() : contadorSignificados(0), contadorAdj(0), x(0), y(0), z(0) {}
};

Palavra palavras[100];
int totalPalavras = 0;

// Função para encontrar índice da palavra
int encontrarPalavra(const string& ficticio) {
    for (int i = 0; i < totalPalavras; i++) {
        if (palavras[i].ficticio == ficticio) {
            return i;
        }
    }
    return -1;
}

// Função para inserir palavra
void inserirPalavra(const string& ficticio, const string& portugues, float x, float y, float z) {
    int indice = encontrarPalavra(ficticio);
    if (indice == -1) {
        indice = totalPalavras++;
        palavras[indice].ficticio = ficticio;
        palavras[indice].x = x;
        palavras[indice].y = y;
        palavras[indice].z = z;
    }

    if (palavras[indice].contadorSignificados < 10) {
        palavras[indice].significados[palavras[indice].contadorSignificados++] = portugues;
        cout << "Significado '" << portugues << "' adicionado para a palavra '" << ficticio << "'.\n";
    } else {
        cout << "Limite de significados alcançado para '" << ficticio << "'.\n";
    }
}

// Função para listar significados
void listarSignificados(const string& ficticio) {
    int indice = encontrarPalavra(ficticio);
    if (indice == -1) {
        cout << "Palavra '" << ficticio << "' nao encontrada.\n";
        return;
    }
    cout << "Significados de '" << ficticio << "':\n";
    for (int i = 0; i < palavras[indice].contadorSignificados; i++) {
        cout << "- " << palavras[indice].significados[i] << "\n";
    }
}

// Função para buscar palavra
void buscarPalavra(const string& ficticio) {
    int indice = encontrarPalavra(ficticio);
    if (indice == -1) {
        cout << "Palavra '" << ficticio << "' nao encontrada.\n";
    } else {
        cout << "Palavra '" << ficticio << "' encontrada nas coordenadas (" 
             << palavras[indice].x << ", " << palavras[indice].y << ", " << palavras[indice].z << ").\n";
        listarSignificados(ficticio);
    }
}

// Função para ordenar as palavras por ordem alfabética usando'bubble sort'
void ordenarAlfabeticamente() {
    for (int i = 0; i < totalPalavras - 1; i++) {
        for (int j = 0; j < totalPalavras - i - 1; j++) {
            if (palavras[j].ficticio > palavras[j + 1].ficticio) {
                Palavra temp = palavras[j];
                palavras[j] = palavras[j + 1];
                palavras[j + 1] = temp;
            }
        }
    }
}

// Função para ordenar as palavras por comprimento usando 'bubble sort' 
void ordenarPorTamanho() {
    for (int i = 0; i < totalPalavras - 1; i++) {
        for (int j = 0; j < totalPalavras - i - 1; j++) {
            if (palavras[j].ficticio.length() > palavras[j + 1].ficticio.length()) {
                Palavra temp = palavras[j];
                palavras[j] = palavras[j + 1];
                palavras[j + 1] = temp;
            }
        }
    }
}


// Função para listar palavras ordenadas
void listarOrdenadas() {
    Palavra ordenadas[100];
    for (int i = 0; i < totalPalavras; i++) {
        ordenadas[i] = palavras[i];
    }

    // Ordena alfabeticamente
    ordenarAlfabeticamente();
    cout << "\nPalavras ordenadas alfabeticamente:\n";
    for (int i = 0; i < totalPalavras; i++) {
        cout << palavras[i].ficticio << "\n";
    }

    // Ordena por tamanho
    ordenarPorTamanho();
    cout << "\nPalavras ordenadas por tamanho:\n";
    for (int i = 0; i < totalPalavras; i++) {
        cout << palavras[i].ficticio << " (" << palavras[i].ficticio.size() << " caracteres)\n";
    }
}

void menu() {
    int opcao;
    do {
        cout << "\nMenu:\n";
        cout << "1. Inserir palavra\n";
        cout << "2. Listar significados\n";
        cout << "3. Buscar palavra\n";
        cout << "4. Listar palavras ordenadas\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, digite um valor numerico relacionado as opcoes.\n";
            continue;
        }

        cin.ignore();

        if (opcao == 1) {
            string ficticio, portugues;
            float x, y, z;
            cout << "Digite a palavra ficticia: ";
            getline(cin, ficticio);
            cout << "Digite o significado em portugues: ";
            getline(cin, portugues);
            cout << "Digite as coordenadas (x, y, z): ";
            cin >> x >> y >> z;
            cin.ignore();
            inserirPalavra(ficticio, portugues, x, y, z);
        } else if (opcao == 2) {
            string ficticio;
            cout << "Digite a palavra ficticia para listar significados: ";
            getline(cin, ficticio);
            listarSignificados(ficticio);
        } else if (opcao == 3) {
            string ficticio;
            cout << "Digite a palavra ficticia para buscar: ";
            getline(cin, ficticio);
            buscarPalavra(ficticio);
        } else if (opcao == 4) {
            listarOrdenadas();
        } else if (opcao != 0) {
            cout << "Operacao invalida.\n";
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
