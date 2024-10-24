
#include <iostream>
#include <list>
using namespace std;
int main(){
    //N é o número de cidades (nós) (1 ≤ N ≤ 100),M é o número de caminhos (arestas) (1 ≤ M ≤ N*(N-1)/2)
    int N,M;

    //entrada pode ser feito um if para restringir (1 ≤ N ≤ 100) e (1 ≤ M ≤ N*(N-1)/2
    cin >> N >> M;

    //criando matriz de adjacencia
    //(1 ≤ N ≤ 100) 
    int matrizAdjacencia[100][100] = {0}; 

    //M linhas descrevem os caminhos,
    for (int i = 0; i < M; i++){
        //cada uma contendo dois inteiros A e B (1 ≤ A, B ≤ N)
        int A,B;
        
        cin >> A >> B;
        
        //indicando um caminho bidirecional entre as cidades A e B.(1 ≤ A, B ≤ N)
        //marcando que visitou
        matrizAdjacencia[A-1][B-1] = 1;
        matrizAdjacencia[B-1][A-1] = 1;
    }

    //saida
    //imprime a matriz
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << matrizAdjacencia[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
/*Contexto:

Em uma terra distante chamada Graphlandia, cada cidade é um nó em um vasto reino de dados. Os caminhos entre as cidades são arestas que conectam estes nós. Um jovem herói, CodeMaster, tem a tarefa de mapear todas as conexões entre as cidades usando uma matriz de adjacência, para garantir que todas as rotas estão seguras e acessíveis para os viajantes.

Entradas: 

A primeira linha contém dois inteiros N e M, onde N é o número de cidades (nós) (1 ≤ N ≤ 100) e M é o número de caminhos (arestas) (1 ≤ M ≤ N*(N-1)/2). As próximas M linhas descrevem os caminhos, cada uma contendo dois inteiros A e B (1 ≤ A, B ≤ N), indicando um caminho bidirecional entre as cidades A e B.

Saída: 

Imprima uma matriz de adjacência de N×N que represente as conexões entre as cidades. Se houver um caminho entre A e B, marque como 1; caso contrário, 0.

Entrada: 

4 4 

1 2 

2 3 

3 4 

4 1

Saída: 

0 1 0 1 

1 0 1 0 

0 1 0 1 

1 0 1 0



*/