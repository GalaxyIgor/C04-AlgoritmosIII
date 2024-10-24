//primeiro passo biliotecas , iostream é a padrao, e o list vai nos ajudar parra criar uma lista
//geralmente igual
#include <iostream>
#include <list>
#define MAX_VERTICES 10
#define INT_MAX 999999
using namespace std;


/*O algoritmo de Prim é um método para encontrar a árvore geradora mínima (MST) de um grafo ponderado não direcionado. 
Ele começa com um vértice inicial e, iterativamente, 
adiciona as arestas de menor peso que conectam um vértice fora da árvore a um vértice dentro dela, 
até que todos os vértices estejam incluídos na MST.*/



//geralmente todo exercicio prim tem essa estruct para determinarmos a origem e o fim, 
//e o peso de cada aresta, para podermos dizer o melhor caminho 
struct Aresta {
    int origem, destino, peso;
};




//nesse daqui não tem tanta alteração de um pro outro
void prim(list<Aresta> adj[], int n, int start) {
    bool intree[MAX_VERTICES];  // Array fixo para verificar se o vértice está na árvore
    int distance[MAX_VERTICES];  // Array fixo para distâncias
    int parent[MAX_VERTICES];     // Array fixo para os pais

    for (int i = 0; i < n; i++) {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;  // Adiciona o vértice à árvore

        // Atualiza as distâncias para os vértices adjacentes
        for (Aresta aresta : adj[v]) {
            if (distance[aresta.destino] > aresta.peso && !intree[aresta.destino]) {
                distance[aresta.destino] = aresta.peso;
                parent[aresta.destino] = v;
            }
        }

        // Encontra o próximo vértice a ser adicionado
        v = -1; 
        int dist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!intree[i] && distance[i] < dist) {
                dist = distance[i];
                v = i;
            }
        }
    }

    // Exibe a árvore geradora mínima
    int total = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << endl;
            total += distance[i]; // Soma o custo das arestas
        }
    }
    cout << "Custo: " << total << endl;
}

int main() {
    //declaracção
    int vertices, orientado, start, origem, destino, peso;
    //entrda
    cin >> vertices >> orientado >> start;

    //lista
    list<Aresta> grafo[MAX_VERTICES]; // Lista de adjacências

    //while p/ entrada e termino do codigo
    while (true) {
        cin >> origem >> destino >> peso;
        //if p/terminar a lista
        if (origem == -1 && destino == -1 && peso == -1) break;

        // Adiciona arestas ao grafo
        grafo[origem].push_back({origem, destino, peso});
        if (orientado == 0) {
            grafo[destino].push_back({destino, origem, peso}); // Se não é orientado, adiciona em ambas as direções
        }
    }

    // Chama a função de Prim para encontrar a árvore geradora mínima
    prim(grafo, vertices, start);

    return 0;
}
