#include <iostream>
using namespace std;

// Estrutura para representar um ponto
struct Point {
    int x, y;
};

// Fun��o para verificar a orienta��o de tr�s pontos
// Retorna:
// 0 -> colinear
// 1 -> hor�rio
// 2 -> anti-hor�rio
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Colinear
    return (val > 0) ? 1 : 2; // Hor�rio ou anti-hor�rio
}

// Fun��o para verificar se um ponto q est� na linha pr
bool onSegment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

// Fun��o para verificar se dois segmentos (p1q1 e p2q2) se cruzam
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

// Fun��o para verificar se um ponto est� dentro de um pol�gono
bool isInside(Point polygon[], int n, Point p) {
    // Criar um ponto fora dos limites do pol�gono
    Point extreme = {10001, p.y};

    // Contar o n�mero de interse��es
    int count = 0;
    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // Verificar se a linha do ponto ao extremo intersecta o lado do pol�gono
        if (doIntersect(p1, p2, p, extreme)) {
            // Se o ponto � colinear com o lado do pol�gono, verificar se est� no segmento
            if (orientation(p1, p, p2) == 0)
                return onSegment(p1, p, p2);
            count++;
        }
    }

    // Verificar se o n�mero de interse��es � �mpar
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
