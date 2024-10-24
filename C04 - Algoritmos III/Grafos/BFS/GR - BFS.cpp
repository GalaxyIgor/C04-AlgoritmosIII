#include <iostream>
#include <list>
using namespace std;

struct Aresta {
    int destino, peso;
};

void bfs(list<Aresta> adj[], int nVertices, int s) {
    char state[nVertices];
    int pai[nVertices];
    list<int> Q;

    for (int u = 0; u < nVertices; u++) {
        if (u != s) {
            state[u] = 'u'; // undiscovered
            pai[u] = -1; // sem pais
        }
    }

    state[s] = 'd'; // discovered
    pai[s] = -1;
    Q.push_back(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        cout << u << endl;

        for (auto p = adj[u].begin(); p != adj[u].end(); p++) {
            int v = p->destino;
            cout << u << " " << v << endl;
            if (state[v] == 'u') {
                state[v] = 'd';
                pai[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 'p'; // processed
    }
}

int main() {
    int vertices, start;
    cin >> vertices >> start;

    list<Aresta> grafo[vertices];
    int origem, destino, peso;

    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) break;
        grafo[origem].push_back({destino, peso});
        grafo[destino].push_back({origem, peso}); // Grafo não orientado
    }

    bfs(grafo, vertices, start);

    return 0;
}
/*Faça um programa que leia dos dados dos vértices e arestas de um grafo não orientado, e os armazene em uma lista de adjacências. Depois o programa deve mostrar o percurso em largura do grafo gerado.

Faça uma função para implementar o percurso em largura. O cabeçalho desta função deve ser:

void bfs(list<no>adj[], int nVertices, int s)

O algoritmo de busca em largura é mostrado abaixo:

BFS(adj[], nVertices, s) ​
    for u = 0 até nVertices-1
        if u != s
            state[u] = ‘u’ // undiscovered​
            pai[u] = -1 // sem pais  ​
 ​
    state[s] = ‘d’ // discovered​
    pai[s] = -1 ​
    Q.push_back(s)​
 ​
    while (!Q.empty())​
        u = *Q.begin()​
        Q.pop_front() ​
        print u ​
        for (p=adj[u].begin();p!=adj[u].end();p++)​
            v = p->v
            print (u,v) ​
            if state[v] = ‘u’​
                state[v] = ‘d’ ​
                pai[v] = u ​
                Q.push_back(v)​
        state[u] = ‘p’ // processed​
Entrada
A entrada consiste de várias linhas:
- a primeira linha contém dois inteiros: o primeiro corresponde ao número de vértices do grafo, e o segundo ao vértice inicial. 

- as demais linhas três inteiros, que correspondem ao vértice de origem, o ´vertice de destino e o peso de cada aresta, respectivamente. A entrada de dados termina quando ocorrer uma linha com três números iguais a -1 (esta não deve ser inserida no grafo).

Saída
A saída deverá mostrar os vértices e arestas visitados, como no exemplo abaixo.

Exemplo de entrada   
Exemplo de saída
5 0
0 1 0
0 4 0
1 2 0
1 3 0
1 4 0
2 3 0
3 4 0
-1 -1 -1










0
0 1
0 4
1
1 0
1 2
1 3
1 4
4
4 0
4 1
4 3
2
2 1
2 3
3
3 1 
3 2
3 4

*/