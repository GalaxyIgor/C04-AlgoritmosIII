#include <iostream>
//da para usar stack ou list
#include <list>
using namespace std;

int main(){
    //sempre começar com list<int> pilha
    //declarando a pilha
    list<int> pilha;

    //valores a serem lidos
    int valor;

    //como colocar valores na lista
    //o problema requer 4  valores, logo criamos um for com 4 posições
    for(int i = 0; i< 4; i++){
        //entrada dos valores a serem lidos
        cin >> valor;
        //inserindo os valores no final da lista 
        pilha.push_back(valor);
    }

    //como remover valores da lista para mostrar
    //ate que a pilha esteja vazia
    while(!pilha.empty()){
        //mostrando o ultimo elemento da lista
        cout << pilha.back() << " ";
        //remove da lista
        pilha.pop_back();
    }
    return 0;
}