#include <iostream>
using namespace std;
/*

a=3; n=3 -> 3*?
a=3; n=2 -> 3*??
a=3; n=1 -> 3*???
a=3; n=0 -> 1

por meio de pilha de recursão
mais rapida do que a interativa

*/

int potencia_interativa(int a, int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++)
    {
        resultado = resultado * a; 
    }
    return resultado;
}

// Função recursiva para calcular a^n
int potencia_recursiva(int a, int n) {
    if (n==0)
    {
        return 1;
    }
    
    return a * potencia_recursiva(a, n-1);
}

int main() {
    //declara as variaveis de a^n
    int resultado = potencia_recursiva(3,3);
    cout << resultado << endl;
    return 0;
}

