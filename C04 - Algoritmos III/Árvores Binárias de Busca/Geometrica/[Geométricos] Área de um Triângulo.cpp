#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Fun��o para calcular a �rea de um tri�ngulo
float area_trigulo(Point a, Point b, Point c) {
    float area = a.x * b.y - a.y * b.x + a.y * c.x - a.x * c.y + b.x * c.y - b.y * c.x;
    area = area / 2.0;
    if (area < 0) area = -area; // Garantir que a �rea seja positiva
    return area;
}

int main() {
    Point p1, p2, p3;

    // Entradas das coordenadas dos tr�s pontos
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    // Calcular a �rea do tri�ngulo
    float area = area_trigulo(p1, p2, p3);

    // Exibir a �rea com uma casa decimal
    cout << fixed;
    cout.precision(1);
    cout << area << endl;

    return 0;
}
