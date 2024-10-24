/*
Você foi contratado pelo Instagram como engenheiro de software para gerenciar as relações entre os usuários. 
Para essa tarefa, você opta por utilizar um grafo direcionado, em que os nós representam os usuários, 
e as arestas as relações entre eles. Um usuário pode seguir outro, mas esse outro pode não o seguir de volta, 
assim como dois usuários podem se seguir mutuamente.

Entrada
A primeira linha contém um inteiro N indicando o número de usuários a serem cadastrados. 
Seguem N linhas com os nomes dos usuários. Após isso, seguem outras N linhas, 
dessa vez contendo o número dos usuários que determinada pessoa segue, sendo a entrada de cada um interrompida pelo número -1. 
Por último temos um único inteiro, indicando o número do usuário o qual deseja-se verificar os seguidores.

Saída
A saída deve mostrar todos os seguidores da pessoa desejada.

Exemplo de entrada   
5
Amanda de Paiva
Gabriel Moreira
Cassia Reis
Helena Martins
Francisco Emanuel
1 2 3 -1
0 -1
1 3 4 -1
0 2 -1
1 -1
1	

Exemplo de saída
Amanda de Paiva
Cassia Reis
Francisco Emanuel

Exemplo de entrada   
7
Antonio Bezerra
Camila Oliveira
Marlene Silva
Sergio Carvalho
Vera Borges
Anderson Soares
Amanda Fernandes
0 2 4 6 -1
1 3 4 -1
1 3 5 6 -1
5 6 -1
0 2 3 -1
3 6 -1
0 -1
6

Exemplo de saída
Antonio Bezerra
Marlene Silva
Sergio Carvalho
Anderson Soares
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

// Estrutura para representar um usuário
struct Usuario {
    string nome;
    list<int> seguidores; // Lista para armazenar os índices dos usuários que o seguem
};

// Função para verificar e exibir os seguidores de um usuário
void mostrarSeguidores(Usuario usuarios[], int numeroUsuario) {
    cout << "Seguidores de " << usuarios[numeroUsuario].nome << ":" << endl;
    for (int i : usuarios[numeroUsuario].seguidores) {
        cout << usuarios[i].nome << endl;
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignorar o caractere de nova linha após o número de usuários

    Usuario usuarios[N];

    // Entrada dos nomes dos usuários
    for (int i = 0; i < N; i++) {
        getline(cin, usuarios[i].nome);
    }

    // Entrada das relações de seguidores
    for (int i = 0; i < N; i++) {
        int seguidor;
        while (true) {
            cin >> seguidor;
            if (seguidor == -1) break;
            usuarios[seguidor].seguidores.push_back(i); // Adiciona o usuário atual à lista de seguidores do seguidor
        }
    }

    // Entrada do usuário para verificar os seguidores
    int usuarioVerificar;
    cin >> usuarioVerificar;

    // Mostra os seguidores do usuário
    mostrarSeguidores(usuarios, usuarioVerificar);

    return 0;
}

/*Você foi contratado pelo Instagram como engenheiro de software para gerenciar as relações entre os usuários. Para essa tarefa, você opta por utilizar um grafo direcionado, em que os nós representam os usuários, e as arestas as relações entre eles. Um usuário pode seguir outro, mas esse outro pode não o seguir de volta, assim como dois usuários podem se seguir mutuamente.

Entrada

A primeira linha contém um inteiro N indicando o número de usuários a serem cadastrados. Seguem N linhas com os nomes dos usuários. Após isso, seguem outras N linhas, dessa vez contendo o número dos usuários que determinada pessoa segue, sendo a entrada de cada um interrompida pelo número -1. Por último temos um único inteiro, indicando o número do usuário o qual deseja-se verificar os seguidores.

Saída

A saída deve mostrar todos os seguidores da pessoa desejada.


Exemplo de entrada   
Exemplo de saída
5
Amanda de Paiva
Gabriel Moreira
Cassia Reis
Helena Martins
Francisco Emanuel
1 2 3 -1
0 -1
1 3 4 -1
0 2 -1
1 -1
1	
Amanda de Paiva
Cassia Reis
Francisco Emanuel

7
Antonio Bezerra
Camila Oliveira
Marlene Silva
Sergio Carvalho
Vera Borges
Anderson Soares
Amanda Fernandes
0 2 4 6 -1
1 3 4 -1
1 3 5 6 -1
5 6 -1
0 2 3 -1
3 6 -1
0 -1
6
Antonio Bezerra
Marlene Silva
Sergio Carvalho
Anderson Soares

*/