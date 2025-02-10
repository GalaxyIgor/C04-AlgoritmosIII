#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Função para determinar a orientação entre três pontos
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Função Gift Wrapping para calcular o casco convexo
void gift_wrapping(Point points[], int n) {
    if (n < 3) return; // O casco convexo precisa de ao menos 3 pontos

    int hull[n]; // Array para armazenar os índices dos pontos no casco
    int hull_size = 0;

    // Encontrar o ponto mais à esquerda
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Construir o casco convexo
    int p = l, q;
    do {
        hull[hull_size++] = p; // Adicionar o ponto atual ao casco
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i; // Encontrar o próximo ponto no sentido anti-horário
        }
        p = q;
    } while (p != l); // Repetir até voltar ao ponto inicial

    // Exibir os pontos do casco convexo em ordem anti-horária
    for (int i = 0; i < hull_size; i++) {
        cout << points[hull[i]].x << " " << points[hull[i]].y << endl;
    }
}

int main() {
    int n;
    cin >> n;
    Point points[n];

    // Entrada dos pontos
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Calcular e exibir o casco convexo
    gift_wrapping(points, n);

    return 0;
}
