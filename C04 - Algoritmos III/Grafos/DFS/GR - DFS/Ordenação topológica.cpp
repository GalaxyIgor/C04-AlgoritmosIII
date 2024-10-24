#include <iostream>
#include <list>

using namespace std;

struct No {
    int destino;
};

void dfs_visit(list<No> adj[], int u, int cor[], int f[], int& tempo, int ordem[], int& index) {
    cor[u] = 1; // GRAY
    tempo++;
    for (auto& no : adj[u]) {
        int v = no.destino;
        if (cor[v] == 0) { // WHITE
            dfs_visit(adj, v, cor, f, tempo, ordem, index);
        }
    }
    cor[u] = 2; // BLACK
    f[u] = ++tempo;
    ordem[index--] = u; // Adiciona o vértice à ordem topológica
}

void dfs(list<No> adj[], int nVertices, int f[], int ordem[]) {
    int cor[nVertices]; // WHITE
    int tempo = 0;
    int index = nVertices - 1;

    for (int i = 0; i < nVertices; i++) {
        cor[i] = 0; // WHITE
    }

    for (int u = 0; u < nVertices; u++) {
        if (cor[u] == 0) { // WHITE
            dfs_visit(adj, u, cor, f, tempo, ordem, index);
        }
    }
}

void ordenacao_topologica(int ordem[], int nVertices) {
    for (int i = 0; i < nVertices; i++) {
        cout << ordem[i] << " ";
    }
    cout << endl;
}

int main() {
    int nVertices, orientado;
    cin >> nVertices >> orientado;

    list<No> adj[nVertices];

    int origem, destino;
    while (cin >> origem >> destino && origem != -1 && destino != -1) {
        adj[origem].push_back({destino});
        if (!orientado) {
            adj[destino].push_back({origem});
        }
    }

    int f[nVertices];
    int ordem[nVertices];

    dfs(adj, nVertices, f, ordem);
    ordenacao_topologica(ordem, nVertices);

    return 0;
}
/*Uma ordenação topológica de um grafo direcionado acíclico (DAG) é uma ordem linear de seus nós em que cada nó vem antes de todos nós para os quais este tenha arestas de saída. Cada DAG tem uma ou mais ordenações topológicas.

Para encontrar a ordenação topológica, utilizamos um percurso em profundidade, cujo é mostrado abaixo:

DFS(G)
    for each vertex u ∈ V[G]
        color[u] ← WHITE
        π[u]← NIL
    time ← 0
    for each vertex u ∈ V[G]
        if color[u] = WHITE
            DFS-VISIT(u)
DFS-VISIT(u)
    color[u] ← GRAY // White vertex u has just been discovered.
    time ← time+1
    d[u] ← time
    for each v ∈ Adj[u] // Explore edge (u, v).
        if color[v] = WHITE
            π[v] ← u
            DFS-VISIT(v)
    color[u] ← BLACK // Blacken u; it is finished.
    f [u] ← time ← time+1
Depois, para determinar a ordenação topológica do grafo, basta mostrar os vértices de G em ordem decrescente do valor de f[].



Faça um programa que leia dos dados dos vértices e arestas de um grafo e os armazene em uma lista de adjacências. Dpois o programa deve mostrar a ordenação topológica do grafo.

Faça uma função para implementar o percurso em profundidade. O cabeçalho desta função deve ser:

void dfs(list<no>adj[], int nVertices)
Depois, faça uma função para mostrar a ordenação topológica deste grafo. O cabeçalho desta função deve ser:

void ordenacao_topologica(int f[], int nVertices)

Entrada
A entrada consiste de várias linhas:
- A primeira linha contém 2 inteiros: 

  * o primeiro corresponde ao número de vértices do grafo. Você pode considerar que o grafo terá no máximo 10 vértices.

  * o segundo define se o grafo é orientado (1) ou não orientado (0)

- As demais linhas contêm dois inteiros, que correspondem ao vértice de origem e ao vertice de destino. A entrada de dados termina quando ocorrer uma linha com dois números iguais a -1 (esta não deve ser inserida no grafo).

Saída
A saída deverá mostrar a ordenação topológica do grafo, conforme o exemplo abaixo:

Exemplo de entrada         
Exemplo de saída
5 1
0 1
0 3
1 2
1 4
2 4
3 2
3 4
-1 -1	0 3 1 2 4










*/