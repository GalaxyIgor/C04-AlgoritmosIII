/*Contexto:
As cidades de Graphlandia estão ameaçadas por um grande vilão, Disconnecto, que planeja destruir algumas pontes (arestas) para isolar as cidades. CodeMaster precisa identificar quais cidades se tornarão inacessíveis se uma determinada ponte for destruída, usando uma matriz de adjacência.

Entrada:
A primeira linha contém dois inteiros N e M, onde N é o número de cidades (nós) (1 ≤ N ≤ 100) e M é o número de caminhos (arestas) (1 ≤ M ≤ N*(N-1)/2). As próximas M linhas descrevem os caminhos, cada uma contendo dois inteiros A e B (1 ≤ A, B ≤ N), indicando um caminho bidirecional entre as cidades A e B. Seguido por um par de inteiros X e Y (1 ≤ X, Y ≤ N), indicando a ponte em questão.

Saída:
Imprima uma lista de todas as cidades que se tornarão inacessíveis de X, se a ponte entre X e Y for destruída.

Entrada: 
4 3
1 2
2 3
3 4
2 3

Saída: 
3 4
*/

#include <iostream>
#include <list>
using namespace std;

#define MAX_VERTICES 100

void bfs(list<int> adj[], int n, int start, bool visitado[]) {
    list<int> fila;
    fila.push_back(start);
    visitado[start] = true;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop_front();

        for (auto v : adj[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                fila.push_back(v);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    list<int> adj[MAX_VERTICES];
    int A, B;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int X, Y;
    cin >> X >> Y;

    // Remover a ponte entre X e Y
    adj[X].remove(Y);
    adj[Y].remove(X);

    // Realizar BFS a partir de X
    bool visitado[MAX_VERTICES] = {false};
    bfs(adj, N, X, visitado);

    // Verificar quais cidades não foram visitadas
    bool first = true;
    for (int i = 1; i <= N; i++) {
        if (!visitado[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}
