#include <iostream>
#include <iomanip> // Para manipulação de precisão
#include <stdlib.h>

using namespace std;

// Função recursiva para calcular a raiz quadrada
double raiz(double x, double x0, double epsilon) {
    // Calcula o próximo valor de x0
    double x1 = (x0 + x / x0) / 2;
    
    // Verifica a condição de parada |x1^2 - x| <= epsilon
    if (abs(x1 * x1 - x) <= epsilon) {
        return x1;
    }
    
    // Caso contrário, continue a recursão com o novo x1
    return raiz(x, x1, epsilon);
}

int main() {
    double x, x0, epsilon;
    
    // Leitura dos valores de x, x0 e epsilon
    cin >> x >> x0 >> epsilon;
    
    // Calcula a raiz quadrada usando a função recursiva
    double resultado = raiz(x, x0, epsilon);
    
    // Mostra o resultado com 4 casas decimais
    cout << fixed << setprecision(4) << resultado << endl;
    
    return 0;
}
