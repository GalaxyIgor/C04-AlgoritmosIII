#include <iostream>
#include <list>

using namespace std;

// Função para realizar a união de duas listas e manter a ordem crescente
list<int> unirListas(list<int>& lista1, list<int>& lista2) {
    list<int> lista3;
    auto it1 = lista1.begin();
    auto it2 = lista2.begin();

    // Fazendo a união enquanto percorre as duas listas
    while (it1 != lista1.end() && it2 != lista2.end()) {
        if (*it1 < *it2) {
            lista3.push_back(*it1);
            ++it1;
        } else if (*it2 < *it1) {
            lista3.push_back(*it2);
            ++it2;
        } else {  // Se forem iguais, adiciona uma vez e avança ambas
            lista3.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    // Adicionando os elementos restantes, se houver, de cada lista
    while (it1 != lista1.end()) {
        lista3.push_back(*it1);
        ++it1;
    }

    while (it2 != lista2.end()) {
        lista3.push_back(*it2);
        ++it2;
    }

    return lista3;
}

int main() {
    list<int> lista1, lista2;
    int num;

    // Lendo os números da lista 1
    while (cin >> num && num != 0) {
        lista1.push_back(num);
    }

    // Lendo os números da lista 2
    while (cin >> num && num != 0) {
        lista2.push_back(num);
    }

    // Criando a lista 3 com a união das duas listas
    list<int> lista3 = unirListas(lista1, lista2);

    // Exibindo os elementos da lista 3
    for (int valor : lista3) {
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}

/*Faça um programa que leia os dados de duas listas ligadas cujos elementos estão em ordem crescente, crie e mostre uma terceira lista ligada, formada pela união dos elementos das duas listas originais, também ordenada em ordem crescente.
Entrada
A entrada consiste duas linhas:
- A primeira contém vários números inteiros, que devem ser colocados na lista 1. O final desta linha é sinalizado pelo número 0, que não deve ser inserido na lista 1.

- A segunda também contém vários números inteiros, que devem ser colocados na lista 2. O final desta linha é sinalizado pelo número 0, que não deve ser inserido na lista 2.


Saída
Na saída, o programa deve mostrar os elementos da lista 3, formada pela união dos elementos das duas listas, ordenados em ordem crescente.

Exemplo de entrada   
Exemplo de saída
1 2 3 5 0
1 3 5 7 0	1 2 3 5 7


*/