#include<iostream>
#include<list>

#define MAX_VERTICES 10

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

// Função BFS usando lista de adjacência
void bfsLista(list<Aresta> grafo[], int vertices, int origem) {
    bool visitado[vertices];        // Marca os vértices visitados
    list<int> fila_visitacao;       // Fila para visitar os vértices
    list<Aresta>::iterator it;

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
        for (it = grafo[atual].begin(); it != grafo[atual].end(); it++) {
            int i = it->destino;
            if (!visitado[i]) {
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

    list<Aresta> grafo[vertices];

    // Preenchendo a lista de adjacência com as arestas
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino;
        grafo[origem].push_back({origem, destino, 0});
        grafo[destino].push_back({destino, origem, 0});
    }

    // Exibe a lista de adjacência
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (list<Aresta>::iterator it = grafo[i].begin(); it != grafo[i].end(); it++) {
            cout << it->destino << "; ";
        }
        cout << endl;
    }

    // Executa o algoritmo BFS a partir do vértice 5
    bfsLista(grafo, vertices, 5);

    return 0;
}
