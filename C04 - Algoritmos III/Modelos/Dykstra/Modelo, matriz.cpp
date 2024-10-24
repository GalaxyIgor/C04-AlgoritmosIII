#include<iostream>

#define MAX_VERTICES 10
#define INT_MAX 999999

using namespace std;

// Função para inicializar o grafo a partir da entrada do usuário usando matriz de adjacências
void construirGrafoMatriz(int grafo[][MAX_VERTICES], int vertices, int arestas) {
    int origem, destino, peso;
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino >> peso;
        grafo[origem][destino] = peso;
        grafo[destino][origem] = peso;
    }
}

// Função para exibir o grafo (matriz de adjacência)
void exibirGrafoMatriz(int grafo[][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (grafo[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

// Função para calcular o menor caminho (Dijkstra com matriz de adjacência)
int dijkstraMatriz(int grafo[][MAX_VERTICES], int n, int start, int end) {
    bool intree[n];
    int distance[n], parent[n];

    for (int i = 0; i < n; i++) {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (intree[v] == false) {
        intree[v] = true;
        for (int i = 0; i < n; i++) {
            if (grafo[v][i] != INT_MAX && distance[i] > distance[v] + grafo[v][i] && intree[i] == false) {
                distance[i] = distance[v] + grafo[v][i];
                parent[i] = v;
            }
        }

        v = 0;
        int dist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (intree[i] == false && dist > distance[i]) {
                dist = distance[i];
                v = i;
            }
        }
    }

    // Exibir o caminho mínimo
    cout << "Caminho minimo:" << endl;
    int aux = end;
    while (aux != start) {
        cout << aux << " <- ";
        aux = parent[aux];
    }
    cout << start << endl;

    cout << "\nCusto: " << distance[end] << endl;

    return distance[end];
}

// Função principal (usando matriz de adjacência)
int main() {
    int vertices, arestas;
    cin >> vertices >> arestas;

    int grafo[MAX_VERTICES][MAX_VERTICES];

    // Inicializar a matriz com infinito (INT_MAX)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j)
                grafo[i][j] = 0;
            else
                grafo[i][j] = INT_MAX;
        }
    }

    // Construir o grafo com os dados de entrada usando matriz de adjacências
    construirGrafoMatriz(grafo, vertices, arestas);
    
    // Exibir o grafo
    exibirGrafoMatriz(grafo, vertices);

    // Executar o algoritmo de Dijkstra e mostrar o custo mínimo
    int custo_minimo = dijkstraMatriz(grafo, vertices, 0, 4);

    return 0;
}
