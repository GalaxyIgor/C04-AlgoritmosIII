#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Função para encontrar o menor caminho usando BFS
int bfs(int N, vector<int> adj[], int S, int D) {
    vector<int> dist(N + 1, INT_MAX);  // Distâncias, inicializadas com infinito
    vector<int> parent(N + 1, -1);     // Vetor para armazenar o caminho
    queue<int> q;

    // Inicializa a sala de entrada
    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int atual = q.front();
        q.pop();

        // Verifica todas as salas conectadas à sala atual
        for (int vizinho : adj[atual]) {
            if (dist[vizinho] == INT_MAX) {  // Se ainda não foi visitado
                dist[vizinho] = dist[atual] + 1;
                parent[vizinho] = atual;
                q.push(vizinho);
                
                // Se chegarmos na sala do dragão, podemos parar
                if (vizinho == D) {
                    // Contando o número de salas no caminho de S a D
                    int num_salas = 1;
                    int temp = vizinho;
                    while (parent[temp] != -1) {
                        temp = parent[temp];
                        num_salas++;
                    }
                    return num_salas;
                }
            }
        }
    }

    // Se não encontramos o dragão
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> adj[N + 1];  // Lista de adjacências para o grafo

    // Leitura das arestas (corredores)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Grafo não direcionado
    }

    int S, D;
    cin >> S >> D;

    // Executa BFS para encontrar o menor caminho de S até D
    int resultado = bfs(N, adj, S, D);

    if (resultado == -1) {
        cout << "IMPOSSIVEL" << endl;
    } else {
        cout << resultado << endl;
    }

    return 0;
}
/*Contexto:
Em um reino distante, um dragão amigável foi capturado e preso no labirinto de um terrível vilão. O herói do reino, 
Sir Code-a-lot, precisa encontrar o caminho mais curto através do labirinto para resgatar o dragão. 
O labirinto é representado como um grafo, onde cada sala é um vértice e os corredores são as arestas que conectam estas salas. 
Sir Code-a-lot pode se mover de uma sala para outra se existir um corredor direto entre elas. 
Ajude Sir Code-a-lot a determinar o menor caminho entre a entrada do labirinto e a sala onde o dragão está preso.

Entrada e Limites:

A primeira linha contém dois inteiros, N e M, representando o número de salas (1 ≤ N ≤ 1000) e o número de corredores.
As próximas M linhas descrevem os corredores, cada uma contendo dois inteiros u e v (1 ≤ u, v ≤ N), 
indicando um corredor que conecta as salas u e v.
A última linha contém dois inteiros, S e D, representando a sala de entrada e a sala onde o dragão está preso, respectivamente.
Saída e Limites:

Imprima o número de salas no menor caminho da sala S até a sala D, incluindo a entrada e a sala do dragão. Se não houver caminho possível, imprima "IMPOSSIVEL".
Entrada:
6 7
1 2
1 3
2 4
3 4
4 5
5 6
4 6
1 6


Saída: 
4
*/