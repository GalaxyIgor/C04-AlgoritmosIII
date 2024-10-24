#include <iostream>
#include <list>

using namespace std;

struct Aresta {
    int destino;
    int dificuldade;
};

void dijkstra(int S, list<Aresta> adj[], int dist[]) {
    bool visitado[S];
    for (int i = 0; i < S; i++) {
        dist[i] = 1e9;  // Uso de um valor grande como "infinito"
        visitado[i] = false;
    }

    dist[0] = 0;

    for (int i = 0; i < S - 1; i++) {
        int u = -1;

        for (int j = 0; j < S; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == 1e9)
            break;

        visitado[u] = true;

        for (auto aresta : adj[u]) {
            int v = aresta.destino;
            int peso = aresta.dificuldade;

            if (dist[u] + peso < dist[v])
                dist[v] = dist[u] + peso;
        }
    }
}

int main() {
    int S, C;
    cin >> S >> C;

    list<Aresta> adj[S];
    for (int i = 0; i < C; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        adj[u].push_back({v, k});
        adj[v].push_back({u, k});
    }

    int dist[S];
    dijkstra(S, adj, dist);

    for (int i = 1; i < S; i++) {
        cout << dist[i] << endl;
    }

    return 0;
}
/*Beso da Silva é um arqueólogo famoso. Ele ganhou vários prêmios internacionais ao encontrar vestígios de uma vila ancestral nos arredores de Anatricé. Atualmente ele está explorando a ruína de uma masmorra em busca de vestígios dos antigos habitantes dessas redondezas. 

Ele fez um mapa de todos as salas dessa masmorra usando um sonar. O sonar consegue indicar quais salas têm conexões umas com as outras, além de mostrar a dificuldade de passar por essa conexão, dada que algumas passagens estão parcialmente obstruídas. Ele quer enfrentar a menor dificuldade possível para explorar essas ruínas. Por isso ele precisas da sua ajuda.

Dado o número de salas, as conexões entre as salas e os níveis de dificuldade de fazer a travessia por essa conexão, retorne uma lista da distância da sala original (sala 0) para todas as outras. 

Obs.: Considere que o valor de dificuldade é cumulativo, ou seja, se eu precisar enfrentar uma dificuldade 3 para passar da sala 1 para a sala 2 e depois um nível de dificuldade 10 para passar da sala 2 para a sala 5, no total eu preciso enfrentar uma dificuldade 13 para sair da sala 1 para a sala 5.

Entrada

A primeira linha da entrada contem dois número inteiros S e C indicando a quantidade de salas e a quantidade de conexões respectivamente. Cada uma das C linhas a seguir contem três números inteiros, indicando as salas i e j que têm uma conexão ( 0 <= i < j < S) e um valor inteiro k ( 0 <= k <= 10) indicando o nível de dificuldade para atravessar por essa conexão.

Saída

A saída deve ter S-1 linhas contendo, em cada linha, um número inteiro indicando o nível de dificuldade para atravessar da sala 0 para cada uma das outras S-1 salas.



Exemplo de entrada 

5 6
0 1 5
1 2 3
1 3 6
2 4 6
3 4 5
0 4 10



Exemplo de saída

5
8
11
10*/