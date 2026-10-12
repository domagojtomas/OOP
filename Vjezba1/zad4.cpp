#include <iostream>
using namespace std;

namespace geo {
    const double PI{3.14159};

    double area(double r) {
        return PI * r * r;
    }

    double area(double a, double b) {
        return a * b;
    }

    int area(int a) {
        return a * a;
    }
}

void print_line(char c = '-', int length = 30) {
    for (int i{0}; i < length; i++) {
        cout << c;
    }
    cout << endl;
}

int main() {

    print_line();

    cout << "area(5): " << geo::area(5) << endl;
    cout << "area(5.0): " << geo::area(5.0) << endl;

    print_line('*', 20);

    cout << "area(2, 3): " << geo::area(2, 3) << endl;
    cout << "area('A'): " << geo::area('A') << endl;

    print_line();

    return 0;
}