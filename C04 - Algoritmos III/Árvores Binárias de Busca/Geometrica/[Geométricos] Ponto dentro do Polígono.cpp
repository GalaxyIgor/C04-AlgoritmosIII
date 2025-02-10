#include <iostream>
using namespace std;

// Estrutura para representar um ponto
struct Point {
    int x, y;
};

// Função para verificar a orientação de três pontos
// Retorna:
// 0 -> colinear
// 1 -> horário
// 2 -> anti-horário
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Colinear
    return (val > 0) ? 1 : 2; // Horário ou anti-horário
}

// Função para verificar se um ponto q está na linha pr
bool onSegment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

// Função para verificar se dois segmentos (p1q1 e p2q2) se cruzam
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Caso geral
    if (o1 != o2 && o3 != o4) return true;

    // Casos especiais
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

// Função para verificar se um ponto está dentro de um polígono
bool isInside(Point polygon[], int n, Point p) {
    // Criar um ponto fora dos limites do polígono
    Point extreme = {10001, p.y};

    // Contar o número de interseções
    int count = 0;
    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // Verificar se a linha do ponto ao extremo intersecta o lado do polígono
        if (doIntersect(p1, p2, p, extreme)) {
            // Se o ponto é colinear com o lado do polígono, verificar se está no segmento
            if (orientation(p1, p, p2) == 0)
                return onSegment(p1, p, p2);
            count++;
        }
    }

    // Verificar se o número de interseções é ímpar
    return count % 2 == 1;
}

int main() {
    int n;
    cin >> n;

    Point polygon[n];
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point p;
    cin >> p.x >> p.y;

    if (isInside(polygon, n, p)) {
        cout << "DENTRO" << endl;
    } else {
        cout << "!(DENTRO)" << endl;
    }

    return 0;
}
