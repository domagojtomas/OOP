// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.

#include <fstream>
#include <iostream>
#include <string>

// ovdje napisite klasu Money i operatore
class Money {
    int total_cents;
public:
    Money(int euros = 0, int cents = 0) : total_cents(euros * 100 + cents) {}
    Money& operator+=(const Money& other) { total_cents += other.total_cents; return *this; }
    friend bool operator<(const Money& a, const Money& b) { return a.total_cents < b.total_cents; }
    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        int value = m.total_cents;
        if (value < 0) { os << '-'; value = -value; }
        os << value / 100 << '.';
        if (value % 100 < 10) os << '0';
        return os << value % 100 << " EUR";
    }
    friend std::istream& operator>>(std::istream& in, Money& m) {
        int euros, cents;
        char dot;
        if (in >> euros >> dot >> cents) {
            if (dot != '.' || cents < 0 || cents > 99) in.setstate(std::ios::failbit);
            else m = Money(euros, cents);
        }
        return in;
    }
};
Money operator+(Money a, const Money& b) { return a += b; }


int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1.05 EUR + 0.95 EUR = 2.00 EUR
    Neispravan zapis: Sok
    Stavki: 5
    Ukupno: 17.23 EUR
    Najskuplje: Kava 7.99 EUR
*/
