#include <iostream>
using namespace std;

// Estrutura para armazenar as informações das pedras
struct Info
{
    string Nome;
    float Peso;
    float Volume;
    float Valor;
    bool Escolhida;
};

/*
// Função de ordenação por relação valor/peso
void OrdenacaoPorValorPeso(Info Pedra[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if ((Pedra[i].Valor / Pedra[i].Peso) < (Pedra[j].Valor / Pedra[j].Peso))
            {
                Info temp = Pedra[i];
                Pedra[i] = Pedra[j];
                Pedra[j] = temp;
            }
        }
    }
}
*/
// Função principal
int main()
{
    // Entrada: Um número inteiro N indicando quantas pedras serão informadas.
    Info Pedra[100];
    int N;
    cin >> N;

    // Entrada: N linhas contendo o nome, o peso, o volume e o valor de cada uma das pedras.
    for (int i = 0; i < N; i++)
    {
        cin >> Pedra[i].Nome >> Pedra[i].Peso >> Pedra[i].Volume >> Pedra[i].Valor;
        Pedra[i].Escolhida = false; // Inicializa como não escolhida
    }
    /*
    // Chama a função de ordenação
    OrdenacaoPorValorPeso(Pedra, N);
    */

    float pesoTotal = 0, volumeTotal = 0;

    // Seleção das pedras
    for (int i = 0; i < N; i++)
    {
        if (pesoTotal + Pedra[i].Peso <= 400 && volumeTotal + Pedra[i].Volume <= 1)
        {
            Pedra[i].Escolhida = true;
            pesoTotal += Pedra[i].Peso;
            volumeTotal += Pedra[i].Volume;
        }
    }

    // Saída: Uma lista de nomes das pedras preciosas escolhidas
    for (int i = 0; i < N; i++)
    {
        if (Pedra[i].Escolhida)
        {
            cout << Pedra[i].Nome << endl;
        }
    }

    return 0;
}
