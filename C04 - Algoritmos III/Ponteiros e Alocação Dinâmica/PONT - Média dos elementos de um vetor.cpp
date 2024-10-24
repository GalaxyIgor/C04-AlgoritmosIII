#include <iostream>
#include <iomanip> // Para manipular a precisão decimal
using namespace std;

int main() {
    int N;
    cout << "Digite o tamanho do vetor: ";
    cin >> N;

    // Alocando dinamicamente o vetor
    int* vetor = new int[N];

    cout << "Digite " << N << " números inteiros: ";
    for (int i = 0; i < N; ++i) {
        cin >> vetor[i];  // Lendo os elementos do vetor
    }

    // Calculando a soma dos elementos usando um ponteiro
    int* p = vetor;  // Ponteiro para percorrer o vetor
    int soma = 0;
    for (int i = 0; i < N; ++i) {
        soma += *(p + i);  // Acessando os elementos via ponteiro
    }

    // Calculando a média
    double media = static_cast<double>(soma) / N;

    // Exibindo a média com duas casas decimais
    cout << fixed << setprecision(2) << media << endl;

    // Liberando a memória alocada
    delete[] vetor;

    return 0;
}
