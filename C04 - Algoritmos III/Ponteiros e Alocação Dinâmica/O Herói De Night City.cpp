#include <iostream>
#include <iomanip>  // Para manipular precisão decimal
#include <string>   // Para trabalhar com strings
using namespace std;

// Struct que representa um implante
struct Implante {
    string nome;
    string fabricante;
    int tier;
    float taxa_psicose;
};

// Função principal
int main() {
    int N;  // Quantidade de implantes a serem registrados
    cin >> N;

    // Alocando dinamicamente o vetor de implantes
    Implante* implantes = new Implante[N];

    // Leitura dos dados de cada implante
    for (int i = 0; i < N; ++i) {
        cin.ignore();  // Limpar o buffer antes de ler strings
        getline(cin, implantes[i].nome);
        getline(cin, implantes[i].fabricante);
        cin >> implantes[i].tier;
        cin >> implantes[i].taxa_psicose;
    }

    // Calculando a soma total das taxas de psicose usando ponteiros
    float soma_psicose = 0.0;
    for (int i = 0; i < N; ++i) {
        soma_psicose += (*(implantes + i)).taxa_psicose;
    }

    // Exibindo o resultado
    cout << fixed << setprecision(2);
    if (soma_psicose > 60.0) {
        cout << "Alerta! Recompensa de 50000 edinhos pela cabeça do Ciberpsicopata.\n";
    } else {
        cout << "Vamos tchum! Temos uma cidade pra conquistar!\n";
    }

    // Liberando a memória alocada dinamicamente
    delete[] implantes;

    return 0;
}
