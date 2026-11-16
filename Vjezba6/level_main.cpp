// Vjezba 6, zadatak 5: napisite klase Enemy i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

class Enemy {
    std::string name;
    int x, y, health;
public:
    Enemy(std::string n, int x, int y) : name(n), x(x), y(y), health(100) {}
    std::string get_name() const { return name; }
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_health() const { return health; }
    bool is_alive() const { return health > 0; }
    void move(int dx, int dy) { x += dx; y += dy; }
    void take_damage(int d) { if (d > 0) { health -= d; if (health < 0) health = 0; } }
};

class Level {
    int r, c;
    std::vector<Enemy> enemies;
public:
    Level(int rows, int cols) : r(rows), c(cols) {}
    bool add(const Enemy& e) {
        if (e.get_x() < 0 || e.get_x() >= c || e.get_y() < 0 || e.get_y() >= r) return false;
        enemies.push_back(e);
        return true;
    }
    void step(int dx, int dy) {
        for (Enemy& e : enemies) {
            int x = e.get_x() + dx, y = e.get_y() + dy;
            if (x >= 0 && x < c && y >= 0 && y < r) e.move(dx, dy);
        }
    }
    void print() const {
        for (const Enemy& e : enemies)
            std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ") " << e.get_health() << '\n';
    }
    void draw() const {
        std::vector<std::string> grid(r + 2, std::string(c + 2, ' '));
        for (int i = 0; i < r + 2; i++) { grid[i][0] = '#'; grid[i][c + 1] = '#'; }
        for (int j = 0; j < c + 2; j++) { grid[0][j] = '#'; grid[r + 1][j] = '#'; }
        for (const Enemy& e : enemies)
            if (!e.get_name().empty()) grid[e.get_y() + 1][e.get_x() + 1] = e.get_name()[0];
        for (const auto& row : grid) std::cout << row << '\n';
    }
};

int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}

/*
Ocekivani ispis:

    10
    Gnome (2, 2) 100
    Troll (9, 4) 100
    Gnome (3, 3) 100
    Troll (9, 4) 100
*/
