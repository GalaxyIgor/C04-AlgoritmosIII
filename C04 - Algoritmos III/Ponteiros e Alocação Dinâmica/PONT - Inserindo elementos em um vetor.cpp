#include <iostream>
using namespace std;

int main() {
    int N;  // Tamanho do vetor
    
    // Lê o tamanho do vetor
    cout << "Digite o tamanho do vetor: ";
    cin >> N;

    // Aloca dinamicamente um vetor de inteiros de tamanho N
    int *v = new int[N];
    int *p = v;  // Ponteiro que vai percorrer o vetor

    // Lê os N inteiros e os insere no vetor usando o ponteiro
    cout << "Digite " << N << " inteiros: ";
    for (int i = 0; i < N; i++) {
        cin >> *p;  // Insere o valor na posição do ponteiro
        p++;        // Avança o ponteiro para a próxima posição
    }

    // Reinicializa o ponteiro para o início do vetor
    p = v;

    // Varre o vetor e exibe seu conteúdo usando o ponteiro
    for (int i = 0; i < N; i++) {
        cout << *p << " ";  // Mostra o valor na posição do ponteiro
        p++;                // Avança o ponteiro
    }
    
    cout << endl;

    // Desaloca a memória alocada dinamicamente
    delete[] v;

    return 0;
}
