#include <iostream>
#include <list>

using namespace std;

// Função para contar o número de nós na lista
int contar(list<int> lista) {
    return lista.size();  // A função size() retorna o número de elementos na lista
}

int main() {
    list<int> lista;
    int num;

    // Lendo os números e inserindo na lista
    while (cin >> num && num != 0) {
        lista.push_back(num);
    }

    // Exibindo o número de nós na lista
    cout << contar(lista) << endl;

    return 0;
}
/*Faça uma função que receba em sua entrada um ponteiro para uma lista ligada, e retorne o número de nós nesta lista. Esta função deve ter o seguinte cabeçalho:

int contar(list<int> lista)
Depois, faça um programa que vá lendo vários números e os inserindo na lista, e em seguida mostre o número de nós desta lista.

Entrada
A entrada consiste vários números inteiros, que devem ser colocados na lista. O final da entrada é sinalizado pelo número 0, que não deve ser inserido na lista.
Saída
Na saída, o programa deve mostrar o número de nós que foram inseridos na lista.

Exemplo de entrada    
Exemplo de saída 
1 4 2 6 5 4 7 0
7
2 -1 4 7 3 0
5

*/