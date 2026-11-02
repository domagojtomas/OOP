#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

vector<string> split_words(const string& text) {
    vector<string> rijeci;
    size_t pocetak = 0;
    size_t kraj;

    while (pocetak < text.size()) {
        if (text[pocetak] == ' ') {
            pocetak++;
            continue;
        }

        kraj = text.find(' ', pocetak);

        if (kraj == string::npos) {
            kraj = text.size();
        }

        rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        pocetak = kraj;
    }

    return rijeci;
}

int main() {

    vector<string> rjecnik = {
        "programski", "jezik", "c++", "je", "brz",
        "i", "mocan", "ali", "nije", "jednostavan",
        "za", "pocetnike"
    };

    // Sortiranje rječnika
    sort(rjecnik.begin(), rjecnik.end());

    string recenica;
    getline(cin, recenica);

    // Podjela rečenice na riječi
    vector<string> rijeci = split_words(recenica);

    vector<string> nepoznate;

    for (string& s : rijeci) {

        // Uklanjanje interpunkcije
        s.erase(remove_if(s.begin(), s.end(),
            [](unsigned char c) {
                return ispunct(c);
            }), s.end());

        // Pretvaranje u mala slova
        transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) {
                return tolower(c);
            });

        // Provjera postoji li riječ u rječniku
        if (!s.empty() &&
            !binary_search(rjecnik.begin(), rjecnik.end(), s)) {
            nepoznate.push_back(s);
        }
    }

    cout << "nepoznatih rijeci: " << nepoznate.size();

    for (const string& s : nepoznate) {
        cout << " " << s;
    }

    return 0;
}