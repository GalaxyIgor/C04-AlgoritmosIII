#include <iostream>
using namespace std;

// Função recursiva para realizar a busca binária
int buscaBinaria(int arr[], int inicio, int fim, int valor) {
    if (inicio > fim) {
        return -1; // Valor não encontrado
    }
    
    int meio = inicio + (fim - inicio) / 2;
    
    if (arr[meio] == valor) {
        return meio; // Valor encontrado
    } else if (arr[meio] > valor) {
        return buscaBinaria(arr, inicio, meio - 1, valor); // Buscar na metade esquerda
    } else {
        return buscaBinaria(arr, meio + 1, fim, valor); // Buscar na metade direita
    }
}

int main() {
    //A entrada consiste em um único valor inteiro N correspondente ao tamanho do vetor de inteiros
    int N;
    cin >> N;

    int arr[N];

    // seguido de N inteiros armazenados no vetor
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    //e por fim um valor inteiro a ser buscado.
    int valor;
    cin >> valor;

    // Chamada da função de busca binária 
    // A saída deve conter a posição em que o número foi achado. Caso não exista, deve imprimir -1.
    int resultado = buscaBinaria(arr, 0, N - 1, valor);

    // Imprimir o resultado
    cout << resultado << endl;

    //return
    return 0;
}

/*Escreva uma função para realizar uma busca binária em um vetor ordenado de inteiros. 
A função deve receber como parâmetros o vetor ordenado, 
o valor a ser buscado e os índices de início e fim do vetor. 
A função deve retornar o índice do elemento buscado se ele estiver presente no vetor e -1 caso contrário.

Dica: Utilize a estratégia de divisão e conquista, 
dividindo o vetor ao meio a cada chamada recursiva e comparando o valor buscado com o elemento do meio do vetor.

Entrada
A entrada consiste em um único valor inteiro N correspondente ao tamanho do vetor de inteiros, 
seguido de N inteiros armazenados no vetor, e por fim um valor inteiro a ser buscado.

Saída
A saída deve conter a posição em que o número foi achado. Caso não exista, deve imprimir -1.

Exemplo de entrada
ex1
6
1 2 3 4 5 6
3
ex2
9
10 20 30 40 50 60 70 80 90
45

Exemplo de Saída
ex1
2
ex2
-1
*/