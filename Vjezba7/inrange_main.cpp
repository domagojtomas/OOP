// Vjezba 7, zadatak 5: kopirajte Vec2 iz zadatka 1 i napisite klasu InRange.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ovdje kopirajte Vec2 i operatore iz zadatka 1
struct Vec2 {
    int x, y;
    Vec2& operator+=(const Vec2& other) { x += other.x; y += other.y; return *this; }
    Vec2& operator-=(const Vec2& other) { x -= other.x; y -= other.y; return *this; }
};
Vec2 operator+(Vec2 a, const Vec2& b) { return a += b; }
Vec2 operator-(Vec2 a, const Vec2& b) { return a -= b; }
Vec2 operator*(Vec2 v, int n) { return {v.x * n, v.y * n}; }
Vec2 operator*(int n, Vec2 v) { return v * n; }
bool operator==(const Vec2& a, const Vec2& b) { return a.x == b.x && a.y == b.y; }
bool operator!=(const Vec2& a, const Vec2& b) { return !(a == b); }
std::ostream& operator<<(std::ostream& os, const Vec2& v) { return os << "(" << v.x << ", " << v.y << ")"; }


// ovdje napisite struct Enemy
struct Enemy {
    std::string name;
    Vec2 position;
};


// ovdje napisite klasu InRange
class InRange {
    Vec2 center;
    int radius;
public:
    InRange(Vec2 c, int r) : center(c), radius(r) {}
    bool operator()(const Enemy& e) const {
        Vec2 d = e.position - center;
        return d.x * d.x + d.y * d.y <= radius * radius;
    }
};


int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{3, 3};

    InRange near(player, 2);                                           // konstruktor, 2 je domet
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';  // operator()

    /* ovdje pozovite count_if s funkcijskim objektom */
    std::cout << std::count_if(enemies.begin(), enemies.end(), near) << '\n';
    int range = 2;

    /* ovdje pozovite count_if s lambdom */
    std::cout << std::count_if(enemies.begin(), enemies.end(), [player, range](const Enemy& e) {
        Vec2 d = e.position - player;
        return d.x * d.x + d.y * d.y <= range * range;
    }) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/
