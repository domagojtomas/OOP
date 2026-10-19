#include <iostream>
#include <string>
using namespace std;

inline int my_max(int a, int b) {
    return (a > b) ? a : b;
}

template <typename T>
inline T my_max_template(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {

    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    int i = 3;

    int provjera_MAX = MAX(++i, 2);
    int provjera_my_max = my_max(++i, 2);

    cout << "Provjera i: " << endl;
    cout << provjera_MAX << endl;
    cout << provjera_my_max << endl;
    cout << "Vrijednost nakon poziva: " << i << endl;

    int x = 4, y = 6;
    double x1 = 4.0, y1 = 6.0;

    int test1 = my_max_template(x, y);
    double test2 = my_max_template(x1, y1);
    char test3 = my_max_template('a', 'b');

    string s1 = "Test1";
    string s2 = "Test2";

    string test4 = my_max_template(s1, s2);

    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;

    return 0;
}