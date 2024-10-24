#include<iostream>
#include<list>
#include<climits> // Para o INT_MAX

#define MAX_VERTICES 10

using namespace std;

struct Aresta {
    int destino, peso;
};

void dijkstra(list<Aresta> adj[], int n, int start, int end) {
    bool intree[MAX_VERTICES];    // Marca vértices já incluídos na solução
    int distance[MAX_VERTICES];   // Distâncias mínimas de start para cada vértice
    int parent[MAX_VERTICES];     // Guarda o caminho

    // Inicializa os arrays
    for (int i = 0; i < n; i++) {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;

        // Atualiza distâncias dos vizinhos de 'v'
        for (auto &aresta : adj[v]) {
            if (!intree[aresta.destino] && distance[aresta.destino] > distance[v] + aresta.peso) {
                distance[aresta.destino] = distance[v] + aresta.peso;
                parent[aresta.destino] = v;
            }
        }

        // Seleciona o próximo vértice a ser processado
        v = -1;
        int dist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!intree[i] && distance[i] < dist) {
                dist = distance[i];
                v = i;
            }
        }

        if (v == -1) break;  // Se não há mais vértices para processar, finaliza o loop
    }

    // Exibe o caminho e o custo
    if (distance[end] == INT_MAX) {
        cout << "Não há caminho do vértice " << start << " até o vértice " << end << endl;
    } else {
        cout << "Menor caminho: ";
        list<int> caminho;
        int atual = end;
        while (atual != -1) {
            caminho.push_front(atual);
            atual = parent[atual];
        }

        for (auto it = caminho.begin(); it != caminho.end(); ++it) {
            if (it != caminho.begin()) cout << " ";
            cout << *it;
        }

        cout << "\nCusto: " << distance[end] << endl;
    }
}

int main() {
    int vertices, orientado, start, end;
    cin >> vertices >> orientado >> start >> end;

    list<Aresta> grafo[MAX_VERTICES];

    // Lê as estradas
    while (true) {
        int origem, destino, peso;
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) {
            break;
        }

        // Adiciona a aresta ao grafo
        grafo[origem].push_back({destino, peso});
        if (orientado == 0) {
            grafo[destino].push_back({origem, peso});
        }
    }

    // Executa o algoritmo de Dijkstra
    dijkstra(grafo, vertices, start, end);

    return 0;
}

/*O algoritmo de Dijkstra, concebido pelo cientista da computação holandês Edsger Dijkstra em 1956 e publicado em 1959, 
soluciona o problema do caminho mais curto num grafo dirigido ou não dirigido com arestas de peso não negativo, 
em tempo computacional O(m + n log n) onde m é o número de arestas e n é o número de vértices.
O pseudocódigo deste algoritmo é mostrado abaixo:

SHORTEST_PATH_DIJKSTRA(G,start,end)
    para cada u em V[G]
        intree[u] = false
        distance[u] = INT_MAX
        parent[u] = -1
    distance[start] = 0
    v = start
    enquanto(intree[v] == false)
        intree[v] = true
        para cada p em Adj[v]
            dest = p->v
            weight = p->peso
            if(distance[destino] > distance[v]+weight)
                distance[destino] = distance[v]+weight
                parent[destino] = v
        v = 0
        dist = INT_MAX
        para cada u em V[G]
            se(intree[u]==false && dist>distance[u])
                dist = distance[u]
                v = u
Faça um programa que leia dos dados dos vértices e arestas de um grafo e os armazene em uma lista de adjacências. 
Dpois o programa deve mostrar a sua árvore geradora mínima.

Faça uma função para implementar o algoritmo de Dijkstra. O cabeçalho desta função deve ser:

void dijkstra(list<no>adj[], int nVertices, int start, int end)
Entrada
A entrada consiste de várias linhas:
- A primeira linha contém 4 inteiros: 

  * o primeiro corresponde ao número de vértices do grafo. Você pode considerar que o grafo terá no máximo 10 vértices.

  * o segundo define se o grafo é orientado (1) ou não orientado (0)

  * o terceiro identifica o vértice inicial do caminho

  * o quarto identifica o vértice de destino 

- As demais linhas contêm três inteiros, que correspondem ao vértice de origem, o ´vertice de destino 
e o peso de cada aresta do grafo, respectivamente. A entrada de dados termina quando ocorrer 
uma linha com três números iguais a -1 (esta não deve ser inserida no grafo).

Saída
A saída deverá mostrar o caminho de menor custo para sair do vértice inicial ao vértice de destino, como no exemplo abaixo.

Exemplo de entrada         
Exemplo de saída
5 1 0 2
0 1 10
0 4 5
1 2 1 
1 4 2
2 3 4
3 0 7
3 2 6
4 1 3
4 2 9
4 3 2
-1 -1 -1	Menor caminho: 0 4 1 2
Custo: 9
*/











