#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x{};
    double y{};
};

void move_by(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b) {
    return sqrt((a->x - b->x) * (a->x - b->x) +
                (a->y - b->y) * (a->y - b->y));
}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

int main() {

    Point a{1, 2};
    Point b{4, 6};

    move_by(&a, 2, 3);

    cout << "Tocka a: " << a.x << " " << a.y << endl;
    cout << "Udaljenost: " << dist(&a, &b) << endl;

    move_by(a, 1, 1);

    cout << "Tocka a: " << a.x << " " << a.y << endl;
    cout << "Udaljenost: " << dist(a, b) << endl;

    Point points[5] = {
        {3, 4},
        {1, 2},
        {5, 6},
        {0, 1},
        {7, 8}
    };

    Point origin{0, 0};

    int minIndex{0};

    for (int i{1}; i < 5; i++) {
        if (dist(points[i], origin) <
            dist(points[minIndex], origin)) {
            minIndex = i;
        }
    }

    cout << "Najbliza tocka ishodistu: "
         << points[minIndex].x << " "
         << points[minIndex].y << endl;

    return 0;
}