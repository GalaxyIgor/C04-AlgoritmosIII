#include <iostream>
using namespace std;

// Função recursiva para calcular a^n
int power(int a, int n) {
    // Caso base: se n == 0, retorne 1
    if (n == 0) {
        return 1;
    }
    // Caso recursivo: a * (a^(n-1))
    return a * power(a, n - 1);
}

int main() {
    int a, n;
    
    // Leitura dos valores de a e n
    cin >> a >> n;
    
    // Chama a função recursiva e imprime o resultado
    cout << power(a, n) << endl;
    
    return 0;
}
