#include <iostream>
using namespace std;

int main() {
    int artefato, soma = 0, posicao = 0;

    // Lê até o final da entrada (EOF) e processa cada artefato
    while (cin >> artefato) {
        cout << "Artefato coletado na terra " << posicao << ": " << artefato << endl;
        soma += artefato;  // Soma os artefatos coletados
        posicao++;  // Incrementa a posição
    }

    // Exibe a soma total ao final da jornada
    cout << "Fim da jornada! Soma total dos artefatos: " << soma << endl;

    return 0;
}
