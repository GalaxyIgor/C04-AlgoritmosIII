#include <iostream>
using namespace std;

// Função recursiva para calcular a^n
int potencia_interativa(int a, int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++)
    {
        resultado = resultado * a; 
    }
    return resultado;
}

int main() {
    //declara as variaveis de a^n
    int resultado = potencia_interativa(3,3);
    cout << resultado << endl;
    return 0;
}

