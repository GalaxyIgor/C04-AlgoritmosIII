#include <iostream>
using namespace std;

int main() {
    int N;

    // Lendo o tamanho do vetor
    cin >> N;

    // Alocação dinâmica do vetor
    int* vetor = new int[N];

    // Lendo os elementos do vetor
    for (int i = 0; i < N; ++i) {
        cin >> vetor[i];
    }

    // Usando ponteiro para encontrar o maior elemento
    int* ptr = vetor;
    int maior = *ptr;  // Inicializa com o primeiro elemento

    for (int i = 1; i < N; ++i) {
        if (*(ptr + i) > maior) {
            maior = *(ptr + i);
        }
    }

    // Exibindo o maior elemento
    cout << maior << endl;

    // Liberando a memória alocada
    delete[] vetor;

    return 0;
}
