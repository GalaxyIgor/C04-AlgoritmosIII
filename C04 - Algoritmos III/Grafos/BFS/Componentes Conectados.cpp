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
/*Como vimos, é possível saber se um grafo é conexo usando um percurso em largura: se todos os vértices forem visitados, então o grafo é conexo.

Faça um programa que faça uso do algoritmo de busca em largura e verifique se um dado grafo é ou não conexo.

Entrada

A entrada consiste de várias linhas:
A primeira linha contém 2 inteiros: 

- o primeiro corresponde ao número de vértices do grafo. Você pode considerar que a rede não tem mais que 10 vértices. 

- o segundo identifica o vértice inicial (start) 

As demais linhas têm dois números inteiros, que correspondem aos vértices de origem e destino de uma aresta.

A entrada de dados termina quando ocorrer uma linha com dois números iguais a -1 (que não deve ser considerada).

Saída
Na saída, o programa deve dizer se o grafo é ou não conexo.


Observação: para este problema, considere que o grafo é não direcionado, e que cada aresta tem peso 1.


Exemplo de entrada         
Exemplo de saída
9 0 
0 1
0 7
1 2 
1 7
2 3
2 5
2 8
3 4
3 5
4 5
5 6
6 7
6 8
7 8
-1 -1	Conexo













8 0
0 1
0 3
3 2
2 4
5 6
5 7
-1 -1	 Nao conexo








*/