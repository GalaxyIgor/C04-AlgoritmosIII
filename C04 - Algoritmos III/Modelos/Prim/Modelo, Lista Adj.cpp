#include<iostream>
#include<list>

#define MAX_VERTICES 10
#define INT_MAX 999999

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

// Função Prim utilizando lista de adjacência
void primLista(list<Aresta> adj[], int n, int start) {
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
        list<Aresta>::iterator it;

        // Atualiza as distâncias para os vizinhos
        for (it = adj[v].begin(); it != adj[v].end(); it++) {
            Aresta aresta = *it;
            if (distance[aresta.destino] > aresta.peso && !intree[aresta.destino]) {
                distance[aresta.destino] = aresta.peso;
                parent[aresta.destino] = v;
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

    list<Aresta> grafo[vertices];

    // Construir o grafo com lista de adjacência
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino >> peso;
        grafo[origem].push_back({origem, destino, peso});
        grafo[destino].push_back({destino, origem, peso});
    }

    // Exibir o grafo (lista de adjacência)
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (list<Aresta>::iterator it = grafo[i].begin(); it != grafo[i].end(); it++)
            cout << it->destino << "(" << it->peso << "); ";
        cout << endl;
    }

    // Executar o algoritmo de Prim
    primLista(grafo, vertices, 0);

    return 0;
}
