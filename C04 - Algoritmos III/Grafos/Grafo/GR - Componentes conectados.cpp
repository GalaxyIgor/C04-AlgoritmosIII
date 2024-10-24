#include <iostream>
#include <list>
using namespace std;

// Função de BFS para visitar os vértices a partir de um vértice inicial
void bfs(int start, list<int>* adjList, bool* visited, int numVertices) {
    list<int> q;  // Cria uma lista que será usada como fila
    q.push_back(start);  // Adiciona o vértice inicial no final da lista
    visited[start] = true;

    while (!q.empty()) {  // Enquanto houver vértices para visitar
        int u = q.front();  // Pega o vértice do início da lista (primeiro)
        q.pop_front();  // Remove o vértice do início da lista

        // Itera pelos vizinhos do vértice
        for (int v : adjList[u]) {
            if (!visited[v]) {  // Se o vizinho ainda não foi visitado
                visited[v] = true;  // Marca como visitado
                q.push_back(v);  // Adiciona o vizinho no final da lista (fila)
            }
        }
    }
}

int main() {
    int numVertices, start;
    cin >> numVertices >> start;

    list<int> adjList[numVertices];  // Lista de adjacências
    bool visited[numVertices];  // Vetor de visitados
    for (int i = 0; i < numVertices; i++) visited[i] = false;  // Inicializa todos como não visitados

    int u, v;

    // Leitura das arestas
    while (cin >> u >> v) {
        if (u == -1 && v == -1) break;  // Condição de parada
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Como o grafo é não direcionado
    }

    // Executa o BFS a partir do vértice inicial
    bfs(start, adjList, visited, numVertices);

    // Verifica se todos os vértices foram visitados
    bool conexo = true;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            conexo = false;
            break;
        }
    }

    // Saída
    if (conexo) {
        cout << "Conexo" << endl;
    } else {
        cout << "Nao conexo" << endl;
    }

    return 0;
}
