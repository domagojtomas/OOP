#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int godina;
    string imePrezime;

    cout << "Unesi godinu rodenja: ";
    cin >> godina;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Unesi ime i prezime: ";
    getline(cin, imePrezime);

    cout << "Inicijali: ";
    cout << imePrezime[0] << ".";

    for (int i = 0; i < imePrezime.length(); i++) {
        if (imePrezime[i] == ' ') {
            cout << imePrezime[i + 1] << ".";
            break;
        }
    }
        int brojZnakova = 0;
    for (char znak : imePrezime) {
        if (znak != ' ') {
            brojZnakova++;
        }
    }

    cout << "Broj znakova bez razmaka: " << brojZnakova << endl;
    int trenutnaGodina = 2026;
    int godine = trenutnaGodina - godina;

    cout << "Broj godina koje osoba navrsava ove godine: " << godine << endl;

    return 0;
}