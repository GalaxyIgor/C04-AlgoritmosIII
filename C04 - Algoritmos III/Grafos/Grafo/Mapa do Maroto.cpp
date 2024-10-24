/*
  Harry, Rony e Hermione fizeram o favor de perder o Mapa do Maroto. E como solução para os seus problemas eles resolveram propor um desafio para um bruxo da Escola de Magia e Telecomunicações de Santa Rita. Eles pensaram que seria melhor criar, de forma temporária, um programa para ler apenas alguns pontos específicos de Hogwarts e suas distâncias e armazenar essas informações em um Grafo. As salas são os vértices e as distâncias são os pesos das arestas.

     Faça um programa que leia os dados dos vértices e arestas e os armazene em uma Lista de Adjacências.

Entrada

A primeira linha contém dois inteiro correspondendo ao número de vértices do grafo e o segundo define se o grafo é orientado (1) ou não orientado (0). As demais linhas contém três inteiros correspondentes ao vértice de origem, o vértice de destino e o peso de cada aresta, respectivamente. A entrada termina quando ocorrer uma linha com três números iguais a -1 (esta não deve ser registrada).

Saída

A saída deverá mostrar a lista de adjacências gerada


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

*/
#include <iostream>
#include <list>
using namespace std;

struct Aresta {
    int origem, destino, peso;
};

int main() {
    int vertices, orientado;
    cin >> vertices >> orientado;

    list<Aresta> grafo[vertices];
    int origem, destino, peso;

    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) break;
        grafo[origem].push_back({origem, destino, peso});
        if (orientado == 0) {
            grafo[destino].push_back({destino, origem, peso});
        }
    }

    for (int i = 0; i < vertices; i++) {
        for (auto it = grafo[i].begin(); it != grafo[i].end(); it++) {
            cout << it->origem << " " << it->destino << " " << it->peso << endl;
        }
    }

    return 0;
}
/*  Harry, Rony e Hermione fizeram o favor de perder o Mapa do Maroto. E como solução para os seus problemas eles resolveram propor um desafio para um bruxo da Escola de Magia e Telecomunicações de Santa Rita. Eles pensaram que seria melhor criar, de forma temporária, um programa para ler apenas alguns pontos específicos de Hogwarts e suas distâncias e armazenar essas informações em um Grafo. As salas são os vértices e as distâncias são os pesos das arestas.

     Faça um programa que leia os dados dos vértices e arestas e os armazene em uma Lista de Adjacências.

Entrada

A primeira linha contém dois inteiro correspondendo ao número de vértices do grafo e o segundo define se o grafo é orientado (1) ou não orientado (0). As demais linhas contém três inteiros correspondentes ao vértice de origem, o vértice de destino e o peso de cada aresta, respectivamente. A entrada termina quando ocorrer uma linha com três números iguais a -1 (esta não deve ser registrada).

Saída

A saída deverá mostrar a lista de adjacências gerada


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









*/