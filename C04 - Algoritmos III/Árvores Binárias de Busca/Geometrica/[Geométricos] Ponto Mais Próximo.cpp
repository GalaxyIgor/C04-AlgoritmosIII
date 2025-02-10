#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Função para calcular a distância quadrada entre dois pontos
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    int n;
    cin >> n;

    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Point user;
    cin >> user.x >> user.y;

    // Inicializar o ponto mais próximo como o primeiro ponto
    Point closest = points[0];
    int minDist = distSq(user, closest);

    for (int i = 1; i < n; i++) {
        int currentDist = distSq(user, points[i]);

        // Atualizar o ponto mais próximo com base nos critérios
        if (currentDist < minDist || 
           (currentDist == minDist && points[i].x < closest.x) || 
           (currentDist == minDist && points[i].x == closest.x && points[i].y < closest.y)) {
            closest = points[i];
            minDist = currentDist;
        }
    }

    // Exibir o ponto mais próximo
    cout << closest.x << " " << closest.y << endl;

    return 0;
}
