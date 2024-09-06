#include <iostream>
#include <list>
using namespace std;

int main(){
    //para declarar a fila
    list<int>fila;
    //para declhar os valores a serem inseridos
    int valor;

    //for para repetir 4 vezes
    for(int i=0; i<4; i++){
        //entrada de 4 valores
        cin >> valor;
        //para inserir no inicio da fila
        fila.push_front(valor);
    }

    //ate esvaziar a fila
    while (!fila.empty()){
        //mostrando o que ta na atras
        cout << fila.back() << " ";
        //apagando o que ta atras
        fila.pop_back();
    }
    

    return 0;
}