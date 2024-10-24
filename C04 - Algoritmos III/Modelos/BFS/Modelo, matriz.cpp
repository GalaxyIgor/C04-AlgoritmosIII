#include<iostream>
#include <list>

#define MAX_VERTICES 10

using namespace std;

// Função BFS usando matriz de adjacência
void bfsMatriz(bool grafo[MAX_VERTICES][MAX_VERTICES], int vertices, int origem) {
    bool visitado[vertices];        // Marca os vértices visitados
    list<int> fila_visitacao;       // Fila para visitar os vértices

    for (int i = 0; i < vertices; i++)
        visitado[i] = false;

    cout << origem << endl;
    visitado[origem] = true;
    fila_visitacao.push_back(origem);

    // Processa a fila de vértices para visitar
    while (!fila_visitacao.empty()) {
        int atual = fila_visitacao.front();
        fila_visitacao.pop_front();

        // Visita os vizinhos do vértice atual
        for (int i = 0; i < vertices; i++) {
            if (grafo[atual][i] && !visitado[i]) {
                cout << i << endl;
                visitado[i] = true;
                fila_visitacao.push_back(i);
            }
        }
    }

    // Verifica se o grafo é conexo
    bool disconexo = false;
    for (int i = 0; i < vertices; i++) {
        if (!visitado[i]) {
            cout << "Grafo disconexo" << endl;
            disconexo = true;
            break;
        }
    }
    if (!disconexo)
        cout << "Grafo conexo" << endl;
}

int main() {
    int vertices, arestas, origem, destino;
    cin >> vertices >> arestas;

    bool grafo[MAX_VERTICES][MAX_VERTICES] = {false};

    // Preenche a matriz de adjacência com as arestas
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino;
        grafo[origem][destino] = true;
        grafo[destino][origem] = true;
    }

    // Exibe a matriz de adjacência
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }

    // Executa o algoritmo BFS a partir do vértice 5
    bfsMatriz(grafo, vertices, 5);

    return 0;
}
