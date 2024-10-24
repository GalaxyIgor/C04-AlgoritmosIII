#include<iostream>
#include<list>
#define MAX_V 100

using namespace std;

struct Aresta {
    int origem, destino;
};

// Função DFS utilizando lista de adjacência
void dfsLista(list<Aresta> grafo[], int vertices, int origem, bool visitado[]) {
    visitado[origem] = true;
    list<Aresta>::iterator it;

    // Percorre a lista de adjacências
    for (it = grafo[origem].begin(); it != grafo[origem].end(); it++) {
        int destino = it->destino;
        if (!visitado[destino]) {
            dfsLista(grafo, vertices, destino, visitado);
        }
    }

    cout << origem << endl;  // Exibe o nó visitado
}

// Função principal (usando lista de adjacência)
int main() {
    int vertices, origem, destino;
    cin >> vertices;

    list<Aresta> grafo[vertices];

    // Construir o grafo com lista de adjacências
    while (cin >> origem >> destino && origem != -1 && destino != -1) {
        grafo[origem].push_back({origem, destino});
        grafo[destino].push_back({destino, origem});
    }

    // Inicializar o array de visitados
    bool visitado[vertices];
    for (int i = 0; i < vertices; i++) {
        visitado[i] = false;
    }

    // Executar DFS começando do vértice 0
    dfsLista(grafo, vertices, 0, visitado);

    return 0;
}
