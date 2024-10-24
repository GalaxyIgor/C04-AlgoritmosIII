#include <iostream>
#include <list>

#define MAX_VERTICES 100 // Aumentando o tamanho máximo para 100 cidades
#define INT_MAX 999999

using namespace std;

struct Aresta {
    int u, v, custo;
};

void prim(list<Aresta> adj[], int n) {
    bool intree[MAX_VERTICES];  // Array para verificar se a cidade está na MST
    int distance[MAX_VERTICES];  // Array para distâncias
    int parent[MAX_VERTICES];     // Array para os pais

    for (int i = 1; i <= n; i++) {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[1] = 0; // Começando a partir da cidade 1
    int v = 1;

    while (true) {
        // Adiciona a cidade à MST
        intree[v] = true;

        // Atualiza as distâncias para as cidades adjacentes
        for (Aresta aresta : adj[v]) {
            if (!intree[aresta.v] && distance[aresta.v] > aresta.custo) {
                distance[aresta.v] = aresta.custo;
                parent[aresta.v] = v;
            }
        }

        // Encontra a próxima cidade a ser adicionada
        v = -1;
        int dist = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (!intree[i] && distance[i] < dist) {
                dist = distance[i];
                v = i;
            }
        }

        if (v == -1) break; // Se não houver mais cidades, sai do loop
    }

    // Calcula o custo total da MST
    int totalCusto = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1) {
            totalCusto += distance[i];
        }
    }
    
    cout << totalCusto << endl; // Saída do custo total
}

int main() {
    int N, M;
    cin >> N >> M; // Lê o número de cidades e conexões

    list<Aresta> grafo[MAX_VERTICES]; // Lista de adjacências

    // Lê as conexões
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        grafo[u].push_back({u, v, c});
        grafo[v].push_back({v, u, c}); // Adiciona em ambas as direções
    }

    // Chama a função de Prim para encontrar o custo mínimo
    prim(grafo, N);

    return 0;
}
/*Contexto:
Uma empresa de telecomunicações deseja expandir sua rede de fibra óptica conectando várias cidades. 
Para minimizar custos, a empresa quer usar o mínimo de cabo possível, garantindo que todas as cidades estejam conectadas.

Entrada:
A primeira linha contém dois inteiros, N e M, representando o número de cidades e o número de possíveis conexões, 
respectivamente. As próximas M linhas contêm três inteiros cada, u, v, e c, representando uma possível conexão entre 
a cidade u e a cidade v com um custo c.

Saída:
O custo mínimo para conectar todas as cidades.

Casos de Teste:

Exemplo de entrada         
Exemplo de saída
4 6
1 2 5
1 3 3
1 4 7
2 3 4
2 4 6
3 4 5	


12




*/