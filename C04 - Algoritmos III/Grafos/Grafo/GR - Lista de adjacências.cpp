/*Faça um programa que leia dos dados dos vértices e arestas de um grafo e os armazene em uma lista de adjacências. Depoism mostre o grafo gerado.
Cada nó da lista de adjacências deve conter o vértice de destino e o peso da aresta.

Use a struct abaixo para implementar seu programa. 

struct no
{
    int v; // vertice adjacente
    int peso; // peso da aresta
};
Faça uma função para criar as arestas. O cabeçalho desta função deve ser:

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
Entrada
A entrada consiste de várias linhas:
- a primeira linha contém dois inteiros: o primeiro corresponde ao número de vértices do grafo, e o segundo define se o grafo é orientado (1) ou não orientado (0).

- as demais linhas três inteiros, que correspondem ao vértice de origem, o ´vertice de destino e o peso de cada aresta, respectivamente. A entrada de dados termina quando ocorrer uma linha com três números iguais a -1 (esta não deve ser inserida no grafo).

Saída
A saída deverá mostrar a lista de adjacências gerada, como no exemplo abaixo.

Exemplo de entrada   
5 1
4 1 3
0 2 4
1 3 2
3 1 3
0 1 2
2 4 7
3 4 2
4 0 1
-1 -1 -1	

Exemplo de saída
0 2 4
0 1 2
1 3 2
2 4 7
3 1 3
3 4 2
4 1 3
4 0 1

Exemplo de entrada   
5 0
4 1 3
0 2 4
1 3 2
3 1 3
0 1 2
2 4 7
3 4 2
4 0 1
-1 -1 -1

Exemplo de saída
0 2 4
0 1 2
0 4 1
1 4 3
1 3 2
1 3 3
1 0 2
2 0 4
2 4 7
3 1 2
3 1 3
3 4 2
4 1 3
4 2 7
4 3 2
4 0 1
*/

#include <iostream>
//p/lista de adjacências
#include <list>
using namespace std;

//informado no problema
// a estrutura de um nó da lista de adjacência
struct no {
    int v; // vértice adjacente
    int peso; // peso da aresta
};

//apenas cabeçalho informado
// Função para criar uma aresta no grafo
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    no novo_no;
    novo_no.v = v;
    novo_no.peso = p;
    adj[u].push_back(novo_no);

    // Se o grafo não for orientado, adicionamos a aresta oposta
    if (!orientado) {
        novo_no.v = u;
        adj[v].push_back(novo_no);
    }
}

int main() {
    int num_vertices, orientado;

    // a primeira linha contém dois inteiros: o primeiro corresponde ao número de vértices do grafo, 
    //e o segundo define se o grafo é orientado (1) ou não orientado (0).
    cin >> num_vertices >> orientado;

    // Lista de adjacências
    list<no> adj[num_vertices];

    // Leitura das arestas
    while (true) {
        int origem, destino, peso;
        //as demais linhas três inteiros, que correspondem ao vértice de origem, 
        //o ´vertice de destino e o peso de cada aresta, respectivamente. 
        //A entrada de dados termina quando ocorrer uma linha com três números iguais a -1 (esta não deve ser inserida no grafo).
        cin >> origem >> destino >> peso;

        // Condição de parada três números iguais a -1 
        if (origem == -1 && destino == -1 && peso == -1)
            break;

        // Criação da aresta
        cria_aresta(adj, origem, destino, peso, orientado);
    }

    // Exibição da lista de adjacências
    // A saída deverá mostrar a lista de adjacências gerada.
    for (int i = 0; i < num_vertices; i++) {
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << i << " " << it->v << " " << it->peso << endl;
        }
    }

    return 0;
}

/*Faça um programa que leia dos dados dos vértices e arestas de um grafo e os armazene em uma lista de adjacências. Depoism mostre o grafo gerado.
Cada nó da lista de adjacências deve conter o vértice de destino e o peso da aresta.

Use a struct abaixo para implementar seu programa. 

struct no
{
    int v; // vertice adjacente
    int peso; // peso da aresta
};
Faça uma função para criar as arestas. O cabeçalho desta função deve ser:

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
Entrada
A entrada consiste de várias linhas:
- a primeira linha contém dois inteiros: o primeiro corresponde ao número de vértices do grafo, e o segundo define se o grafo é orientado (1) ou não orientado (0).

- as demais linhas três inteiros, que correspondem ao vértice de origem, o ´vertice de destino e o peso de cada aresta, respectivamente. A entrada de dados termina quando ocorrer uma linha com três números iguais a -1 (esta não deve ser inserida no grafo).

Saída
A saída deverá mostrar a lista de adjacências gerada, como no exemplo abaixo.

Exemplo de entrada   
Exemplo de saída
5 1
4 1 3
0 2 4
1 3 2
3 1 3
0 1 2
2 4 7
3 4 2
4 0 1
-1 -1 -1	0 2 4
0 1 2
1 3 2
2 4 7
3 1 3
3 4 2
4 1 3
4 0 1


5 0
4 1 3
0 2 4
1 3 2
3 1 3
0 1 2
2 4 7
3 4 2
4 0 1
-1 -1 -1






0 2 4
0 1 2
0 4 1
1 4 3
1 3 2
1 3 3
1 0 2
2 0 4
2 4 7
3 1 2
3 1 3
3 4 2
4 1 3
4 2 7
4 3 2
4 0 1
*/