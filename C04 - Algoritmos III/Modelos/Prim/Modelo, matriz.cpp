#include<iostream>

#define MAX_VERTICES 10
#define INT_MAX 999999

using namespace std;

// Função Prim utilizando matriz de adjacência
void primMatriz(int grafo[MAX_VERTICES][MAX_VERTICES], int n, int start) {
    bool intree[n];  // Marca se o vértice está na árvore geradora mínima
    int distance[n]; // Menor peso até cada vértice
    int parent[n];   // Vértice pai na árvore geradora mínima

    for (int i = 0; i < n; i++) {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;

        // Atualiza as distâncias para os vizinhos
        for (int i = 0; i < n; i++) {
            if (grafo[v][i] != INT_MAX && !intree[i] && distance[i] > grafo[v][i]) {
                distance[i] = grafo[v][i];
                parent[i] = v;
            }
        }

        v = 0;
        int dist = INT_MAX;

        // Escolhe o próximo vértice com menor distância
        for (int i = 0; i < n; i++) {
            if (!intree[i] && dist > distance[i]) {
                dist = distance[i];
                v = i;
            }
        }
    }

    int total = 0;
    cout << "Árvore Geradora Mínima:" << endl;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1)
            cout << parent[i] << " " << i << endl;
        total += distance[i];
    }
    cout << "Custo: " << total << endl;
}

int main() {
    int vertices, arestas, origem, destino, peso;
    cin >> vertices >> arestas;

    int grafo[MAX_VERTICES][MAX_VERTICES];

    // Inicializar a matriz de adjacência com valores infinitos
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo[i][j] = INT_MAX;
        }
    }

    // Construir o grafo com matriz de adjacência
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino >> peso;
        grafo[origem][destino] = peso;
        grafo[destino][origem] = peso;
    }

    // Exibir o grafo (matriz de adjacência)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (grafo[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << grafo[i][j] << " ";
        }
        cout << endl;
    }

    // Executar o algoritmo de Prim
    primMatriz(grafo, vertices, 0);

    return 0;
}
