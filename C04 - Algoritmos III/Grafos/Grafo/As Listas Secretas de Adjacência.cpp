#include <iostream>
#include <list>
using namespace std;

// Estrutura para representar a lista de adjacência
struct Aresta {
    int destino; // Cidade adjacente
};

// Função para criar arestas
void cria_aresta(list<Aresta> adj[], int u, int v) {
    Aresta aresta1 = {v};
    Aresta aresta2 = {u};
    adj[u].push_back(aresta1); // Adiciona a aresta de u para v
    adj[v].push_back(aresta2); // Adiciona a aresta de v para u (bidirecional)
}

int main() {
    int N, M;
    
    // Leitura do número de cidades e caminhos
    cin >> N >> M;

    // Criando a lista de adjacência
    list<Aresta> adj[N + 1]; // +1 para usar índices de 1 a N

    // Lendo os caminhos
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        cria_aresta(adj, A, B);
    }

    // Processando e exibindo a lista de adjacência
    for (int i = 1; i <= N; i++) {
        // Armazenando cidades conectadas em um array fixo
        int cidadesConectadas[100]; // Número máximo de cidades
        int count = 0;

        // Copiando as cidades conectadas para o array
        for (const auto& aresta : adj[i]) {
            cidadesConectadas[count++] = aresta.destino;
        }

        // Ordenando as cidades conectadas (Bubble Sort)
        for (int j = 0; j < count - 1; j++) {
            for (int k = 0; k < count - j - 1; k++) {
                if (cidadesConectadas[k] > cidadesConectadas[k + 1]) {
                    // Troca
                    int temp = cidadesConectadas[k];
                    cidadesConectadas[k] = cidadesConectadas[k + 1];
                    cidadesConectadas[k + 1] = temp;
                }
            }
        }

        // Imprimindo o número de cidades conectadas e os índices
        cout << count; // Número de cidades conectadas
        for (int j = 0; j < count; j++) {
            cout << " " << cidadesConectadas[j]; // Cidades conectadas
        }
        cout << endl; // Nova linha para a próxima cidade
    }

    return 0;
}
/*Contexto: 


Em Graphlandia, os mensageiros usam rotas secretas para entregar mensagens entre as cidades. CodeMaster descobre sobre essas rotas e decide mapeá-las usando listas de adjacência para cada cidade, identificando todas as cidades conectadas diretamente a ela.


Entradas: 

A primeira linha contém dois inteiros N e M, onde N é o número de cidades (nós) (1 ≤ N ≤ 100) e M é o número de caminhos (arestas) (1 ≤ M ≤ N*(N-1)/2). As próximas M linhas descrevem os caminhos, cada uma contendo dois inteiros A e B (1 ≤ A, B ≤ N), indicando um caminho bidirecional entre as cidades A e B.

Saídas: 

Para cada cidade i (1 ≤ i ≤ N), imprima uma linha começando com o número de cidades diretamente conectadas a i, seguido pelos índices dessas cidades, ordenados em ordem crescente.

Entrada: 

4 4 

1 2 

2 3 

3 4 

4 1

Saída: 

2 2 4 

2 1 3 

2 2 4 

2 1 3





*/