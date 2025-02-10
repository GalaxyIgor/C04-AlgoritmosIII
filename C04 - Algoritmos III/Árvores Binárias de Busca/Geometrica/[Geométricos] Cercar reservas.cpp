//Gift Wrapping
#include <iostream>
#include <cmath>
using namespace std;

// Estrutura para representar um ponto
struct Point {
    int x, y;
};

// Função para calcular a distância entre dois pontos
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Para encontrar a orientação do triplo ordenado (p, q, r)
// 0 -> colinear, 1 -> sentido horário, 2 -> sentido anti-horário
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Função que calcula o fecho convexo usando Gift Wrapping
void gift_wrapping(Point points[], int n, Point hull[], int &hull_size) {
    if (n < 3) {
        hull_size = 0;
        return;  // Fecho convexo não possível
    }

    // Array para armazenar os índices do fecho convexo
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;

    // Encontrar o ponto mais à esquerda
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Seguir em sentido anti-horário até voltarmos ao ponto inicial
    int p = l, q;
    do {
        // Encontrar o ponto mais anti-horário em relação a p
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Armazenar o índice do próximo ponto no fecho
        next[p] = q;
        p = q;
    } while (p != l);  // Até voltarmos ao ponto inicial

    // Preencher o array de pontos do fecho
    hull_size = 0;
    for (int i = 0; i < n; i++) {
        if (next[i] != -1) {
            hull[hull_size++] = points[i];
        }
    }
}

// Função para calcular o perímetro do fecho convexo
double calculate_perimeter(Point hull[], int hull_size) {
    double perimeter = 0.0;
    for (int i = 0; i < hull_size; i++) {
        perimeter += distance(hull[i], hull[(i + 1) % hull_size]);
    }
    return perimeter;
}

int main() {
    int n;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Point hull[n];
    int hull_size;

    // Calcular o fecho convexo
    gift_wrapping(points, n, hull, hull_size);

    // Calcular o perímetro do fecho convexo
    double perimeter = calculate_perimeter(hull, hull_size);

    // Exibir o resultado arredondado para cima
    cout << ceil(perimeter) << endl;

    return 0;
}
