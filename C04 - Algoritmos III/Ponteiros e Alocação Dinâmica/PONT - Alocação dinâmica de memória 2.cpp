#include<iostream>
#include<iomanip> // Para usar o setprecision
using namespace std;

//o progrma é similar ao primeiro codigo porem ele mde a media de uma turma, logo utilização de for é nescessario
//


// Definição da struct para armazenar as notas e a média de cada aluno
struct Aluno {
    int notas[4];   // Armazena as 4 notas
    float media;    // Armazena a média das notas
};

int main() {
    int N;  // Número de alunos
    
    // Lê o número de alunos
    cout << "Digite o número de alunos: ";
    cin >> N;
    
    // Aloca dinamicamente um vetor de structs Aluno para N alunos
    Aluno* turma = new Aluno[N];
    
    // Variável para calcular a média da turma
    float soma_medias = 0;

    // Loop para ler as notas de cada aluno
    for (int i = 0; i < N; i++) {
        cout << "Digite as 4 notas do aluno " << i + 1 << ": ";
        int soma = 0;
        
        // Lê as 4 notas e as armazena na struct
        for (int j = 0; j < 4; j++) {
            cin >> turma[i].notas[j];
            soma += turma[i].notas[j];  // Soma as notas
        }
        
        // Calcula a média do aluno e armazena na struct
        turma[i].media = soma / 4.0;
        soma_medias += turma[i].media;  // Soma a média do aluno para a média da turma
    }

    // Calcula a média da turma
    float media_turma = soma_medias / N;

    // Exibe a média da turma com 2 casas decimais
    cout << fixed << setprecision(2);
    cout << "Média da turma: " << media_turma << endl;

    // Desaloca a memória
    delete[] turma;

    return 0;
}
