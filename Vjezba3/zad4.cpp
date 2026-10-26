#include <iostream>
#include <string>
using namespace std;

bool split_email(const string& email, string& user, string& domain) {

    int poz = email.find('@');

    if (poz == string::npos) {
        return false;
    }

    if (email.find('@', poz + 1) != string::npos) {
        return false;
    }

    if (poz == 0 || poz == email.size() - 1) {
        return false;
    }

    user = email.substr(0, poz);
    domain = email.substr(poz + 1);

    if (domain.find('.') == string::npos) {
        return false;
    }

    return true;
}

int main() {
    string email, user, domain;

    getline(cin, email);

    if (split_email(email, user, domain)) {
        cout << "Korisnik: " << user << endl;
        cout << "Domena: " << domain << endl;
    }
    else {
        cout << "Neispravna adresa" << endl;
    }

    return 0;
}