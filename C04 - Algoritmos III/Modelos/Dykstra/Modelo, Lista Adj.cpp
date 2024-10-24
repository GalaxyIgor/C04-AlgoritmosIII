#include<iostream>
#include<list>

#define MAX_VERTICES 10
#define INT_MAX 999999

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

// Função para inicializar o grafo a partir da entrada do usuário usando lista de adjacências
void construirGrafoLista(list<Aresta> grafo[], int vertices, int arestas) {
    int origem, destino, peso;
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino >> peso;
        grafo[origem].push_back({origem, destino, peso});
        grafo[destino].push_back({destino, origem, peso});
    }
}

// Função para exibir o grafo (lista de adjacência)
void exibirGrafoLista(list<Aresta> grafo[], int vertices) {
    list<Aresta>::iterator it;
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (it = grafo[i].begin(); it != grafo[i].end(); it++) {
            cout << it->destino << "(" << it->peso << "); ";
        }
        cout << endl;
    }
}

// Função para calcular o menor caminho (Dijkstra com lista de adjacência)
int dijkstraLista(list<Aresta> adj[], int n, int start, int end) {
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
        list<Aresta>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++) {
            Aresta aresta = *it;
            if (distance[aresta.destino] > distance[v] + aresta.peso && intree[aresta.destino] == false) {
                distance[aresta.destino] = distance[v] + aresta.peso;
                parent[aresta.destino] = v;
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
    list<int> apresentacao;
    int aux = end;
    do {
        apresentacao.push_front(aux);
        aux = parent[aux];
    } while (aux != start);
    
    cout << start;
    while (!apresentacao.empty()) {
        cout << "->" << apresentacao.front();
        apresentacao.pop_front();
    }
    
    cout << "\nCusto: " << distance[end] << endl;

    return distance[end];
}

// Função principal (usando listas de adjacência)
int main() {
    int vertices, arestas;
    cin >> vertices >> arestas;

    list<Aresta> grafo[vertices];

    // Construir o grafo com os dados de entrada usando lista de adjacências
    construirGrafoLista(grafo, vertices, arestas);
    
    // Exibir o grafo
    exibirGrafoLista(grafo, vertices);

    // Executar o algoritmo de Dijkstra e mostrar o custo mínimo
    int custo_minimo = dijkstraLista(grafo, vertices, 0, 4);

    return 0;
}
