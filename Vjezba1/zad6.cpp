#include <iostream>
#include <numeric>
using namespace std;

struct Fraction {
    int numerator{};
    int denominator{};

    void reduce() {
        int nzd = gcd(numerator, denominator);

        numerator /= nzd;
        denominator /= nzd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double value() {
        return static_cast<double>(numerator) / denominator;
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {

    Fraction result{
        a.numerator * b.denominator + b.numerator * a.denominator,
        a.denominator * b.denominator
    };

    result.reduce();

    return result;
}

int main() {

    Fraction a{2, 4};
    Fraction b{1, 3};

    cout << "Prvi razlomak: ";
    a.print();

    cout << "Drugi razlomak: ";
    b.print();

    a.reduce();

    cout << "Skraceni prvi razlomak: ";
    a.print();

    cout << "Decimalna vrijednost: " << a.value() << endl;

    Fraction c = sum(a, b);

    cout << "Zbroj razlomaka: ";
    c.print();

    return 0;
}