#include<iostream>
#include<iomanip> // Para usar o setprecision
using namespace std;


//o programa basicamente utilisa os ponteiros de forma similar ao java, ao usar a estruct para armazenar valores
//utiliza new aluno e cria o ponteiro, ele aponta para notas inicialmente e pede as 4 notas soma elas e por fim faz a media 
//e deleta a memoria de ponteiro


struct Aluno {
    int notas[4];   // Armazena as 4 notas
    float media;    // Armazena a média das notas
};

int main() {
    // Ponteiro para a struct Aluno
    Aluno* ptr_aluno = new Aluno;

    // Lê as 4 notas do aluno
    cout << "Digite as 4 notas do aluno: ";
    for (int i = 0; i < 4; i++) {
        cin >> ptr_aluno->notas[i];
    }

    // Calcula a média
    int soma = 0;
    for (int i = 0; i < 4; i++) {
        soma += ptr_aluno->notas[i];
    }
    ptr_aluno->media = soma / 4.0;  // Armazena a média na struct

    // Exibe a média com 2 casas decimais
    cout << fixed << setprecision(2);
    cout << "Média das notas: " << ptr_aluno->media << endl;

    // Desaloca a memória
    delete ptr_aluno;

    return 0;
}
