// Vjezba 6, zadatak 4: napisite klasu Board iznad main.

#include <iostream>

class Board {
    char* data;
    int r, c;
public:
    Board(int rows, int cols, char border) : r(rows), c(cols) {
        data = new char[r * c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                data[i * c + j] = (i == 0 || j == 0 || i == r - 1 || j == c - 1) ? border : ' ';
    }
    ~Board() { delete[] data; }
    Board(const Board& other) : r(other.r), c(other.c) {
        data = new char[r * c];
        for (int i = 0; i < r * c; i++) data[i] = other.data[i];
    }
    Board& operator=(const Board& other) {
        if (this != &other) {
            char* fresh = new char[other.r * other.c];
            for (int i = 0; i < other.r * other.c; i++) fresh[i] = other.data[i];
            delete[] data; data = fresh; r = other.r; c = other.c;
        }
        return *this;
    }
    void set(int i, int j, char ch) {
        if (i > 0 && i < r - 1 && j > 0 && j < c - 1) data[i * c + j] = ch;
    }
    char get(int i, int j) const {
        return (i >= 0 && i < r && j >= 0 && j < c) ? data[i * c + j] : '\0';
    }
    int rows() const { return r; }
    int cols() const { return c; }
    void print() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) std::cout << data[i * c + j];
            std::cout << '\n';
        }
    }
};

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;          // copy konstruktor
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');     // rub se ne mijenja
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/
