#include <iostream>
#include <list>
using namespace std;

void bfs(bool grafo[][100], int vertices, int origem) {
    // criando array de visitados
    bool visitado[100] = {false};
    // criando lista
    list<int> fila_visitacao;

    // visitando o primeiro n� (origem)
    cout << origem << endl;
    visitado[origem] = true;
    fila_visitacao.push_back(origem);

    while (!fila_visitacao.empty()) {
        // obt�m o primeiro elemento da fila
        int atual = fila_visitacao.front();
        fila_visitacao.pop_front();

        // visita os vizinhos
        for (int i = 0; i < vertices; i++) {
            if (grafo[atual][i] && !visitado[i]) {
                cout << i << endl;
                visitado[i] = true;
                fila_visitacao.push_back(i);
            }
        }
    }
}

int main() {
    // vertices e arestas para o grafo
    int vertices, arestas, origem, destino;
    
    // entrada de vertices e arestas
    cin >> vertices >> arestas;
    
    // grafo como matriz de adjac�ncia
    bool grafo[100][100] = {false};  // Limite de 100 v�rtices

    // inicializando a matriz com as arestas
    for (int i = 0; i < arestas; i++) {
        cin >> origem >> destino;
        // se for direcional apenas uma dire��o
        grafo[origem][destino] = true;
        // se for bidirecional, ambas as dire��es
        grafo[destino][origem] = true;
    }

    // exibi��o da matriz de adjac�ncia
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }

    // executando BFS a partir do v�rtice 0
    bfs(grafo, vertices, 0);

    return 0;
}
