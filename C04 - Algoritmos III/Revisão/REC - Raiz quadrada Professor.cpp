#include <iostream>
#include <iomanip> 
using namespace std;

float raiz(float x, float x0, float e) {
    float resultado = (x0 * x0) - x;
    if (resultado < 0) {
        resultado = -resultado;
    }
    if (resultado <= e) {
        return x0;
    }
    x0 = ((x0 * x0) + x) / (2 * x0);
    return raiz(x, x0, e);
}

int main() {
    float resultado = raiz(15, 4, 0.0001);

    cout << fixed << setprecision(4) << resultado << endl;
    return 0;
}
