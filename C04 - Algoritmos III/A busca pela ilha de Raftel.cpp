#include <iostream>
#include <string>
using namespace std; 

//Primeiro presciso da divisão e conquista, obs: busca binaria é divisão e conquista
int BuscaBinaria(string arr[], int esquerda, int direita, string chave){
    //busca binaria começa com while
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;

        //verifica se a chave está no meio
        if(arr[meio] == chave){
            return  meio;
        }

        //se a chave for maior, ignora a metade esquerda
        if (arr[meio] == chave){
            esquerda = meio -1;
        }        
        
        //se a chave for menor, ignora a metade direita
        else{
            direita = meio - 1;
        }
    }

    //retorna -1 se a chave não for achada
    return -1;
}

//main
int main(){
    //ilhas
    string ilhas[] = {"Alabasta", "Dressrosa", "Enies Lobby", "Skypiea", "Thriller Bark", "Wano", "Water 7"};
    
    //pista a ser buscada
    string pistaBuscada = "Skypiea";

    //A divisão dos dois resultados dá o número de elementos no array.
    int tamanho = sizeof(ilhas) / sizeof(ilhas[0]);

    //chama a busca binaria
    int indice = BuscaBinaria(ilhas, 0, tamanho - 1, pistaBuscada);

    //if basico para dizer se foi encontrado em determinado indice ou não 
    if (indice != -1) {
    cout << "Índice da pista encontrada: " << indice << endl;
    } else {
        cout << "Pista não encontrada." << endl;
    }

    //finaliza
    return 0;
}
//0.94s
/*
#include <iostream>
using namespace std;
// Função que recebe o array e seu tamanho como parâmetros
int buscaBinaria(string arr[], int tamanho, string chave) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == chave)
            return meio;
        if (arr[meio] < chave)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return -1;
}

int main() {
    string ilhas[] = {"Alabasta", "Dressrosa", "Enies Lobby", "Skypiea", "Thriller Bark", "Wano", "Water 7"};
    
    // O tamanho do array é calculado e passado como argumento
    int tamanho = 7;  // tamanho do array
    
    string pistaBuscada = "Skypiea";
    
    int indice = buscaBinaria(ilhas, tamanho, pistaBuscada);

    if (indice != -1) {
        cout << "Índice da pista encontrada: " << indice << endl;
    } else {
        cout << "Pista não encontrada." << endl;
    }

    return 0;
}
//0.104s
*/