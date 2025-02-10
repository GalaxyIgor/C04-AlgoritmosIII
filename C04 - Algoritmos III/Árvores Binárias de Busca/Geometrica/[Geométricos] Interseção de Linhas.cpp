#include <iostream>
using namespace std;

// Estrutura para representar um ponto
struct Point {
    int x, y;
};

// Para encontrar a orientação do triplo ordenado (p, q, r)
// Retornos:
// 0 -> colinear
// 1 -> sentido horário
// 2 -> sentido anti-horário
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Colinear
    return (val > 0) ? 1 : 2; // Horário ou anti-horário
}

// Função para verificar se um ponto q está na linha pr
bool onSegment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

// Função para verificar se duas linhas (p1q1 e p2q2) se cruzam
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Encontrar as orientações necessárias
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Caso geral: as linhas se cruzam se as orientações forem diferentes
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos especiais
    // p2 está na linha p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // q2 está na linha p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p1 está na linha p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // q1 está na linha p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    // Nenhum dos casos acima: as linhas não se cruzam
    return false;
}

int main() {
    Point p1, q1, p2, q2;
    cin >> p1.x >> p1.y >> q1.x >> q1.y;
    cin >> p2.x >> p2.y >> q2.x >> q2.y;

    // Verificar se as linhas se cruzam
    if (doIntersect(p1, q1, p2, q2)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
