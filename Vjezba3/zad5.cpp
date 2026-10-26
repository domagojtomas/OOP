#include <iostream>
#include <string>
using namespace std;

string with_separators(string digits) {

    int pocetak = 0;

    if (digits[0] == '-') {
        pocetak = 1;
    }

    for (int i = digits.size() - 3; i > pocetak; i -= 3) {
        digits.insert(i, ".");
    }

    return digits;
}

string without_separators(string text) {

    size_t poz = text.find('.');

    while (poz != string::npos) {
        text.erase(poz, 1);
        poz = text.find('.');
    }

    return text;
}

int main() {

    string broj;
    cin >> broj;

    cout << with_separators(broj) << endl;

    cout << without_separators(with_separators(broj)) << endl;

    return 0;
}