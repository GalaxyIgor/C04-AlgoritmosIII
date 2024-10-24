#include<iostream>
#define MAX_V 100

using namespace std;

// Função DFS utilizando matriz de adjacência
void dfsMatriz(bool grafo[MAX_V][MAX_V], int vertices, int origem, bool visitado[]) {
    visitado[origem] = true;

    // Percorre as conexões do vértice "origem"
    for (int destino = 0; destino < vertices; destino++) {
        if (grafo[origem][destino] && !visitado[destino]) {
            dfsMatriz(grafo, vertices, destino, visitado);
        }
    }

    cout << origem << endl;  // Exibe o nó visitado
}

// Função principal (usando matriz de adjacência)
int main() {
    int vertices, origem, destino;
    cin >> vertices;

    bool grafo[MAX_V][MAX_V] = {false};

    // Inicializar a matriz de adjacências
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo[i][j] = false;
        }
    }

    // Construir o grafo com matriz de adjacências
    while (cin >> origem >> destino && origem != -1 && destino != -1) {
        grafo[origem][destino] = true;
        grafo[destino][origem] = true;
    }

    // Inicializar o array de visitados
    bool visitado[vertices];
    for (int i = 0; i < vertices; i++) {
        visitado[i] = false;
    }

    // Executar DFS começando do vértice 0
    dfsMatriz(grafo, vertices, 0, visitado);

    return 0;
}
