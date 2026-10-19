
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    int JMBAG;
    int godina;
    int ispiti;
    int ects;
    double prosjek;
};

void filter_students(Student s[], int n,void (*action)(Student&), bool (*cond)(const Student&)) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

void ispisi(Student& s) {
    cout << s.ime << " " << s.JMBAG
         << " " << s.godina << " "
         << s.ispiti << " " << s.ects
         << " " << s.prosjek << endl;
}

int main() {
    Student s[] = {
        {"Ana", 123, 1, 2, 50, 4.0},
        {"Ivan", 456, 2, 0, 30, 3.0},
        {"Marko", 789, 1, 3, 60, 3.8},
        {"Petra", 111, 3, 4, 40, 4.5}
    };

    int n = 4;

    cout << "Studenti prve godine s polozenim ispitom:" << endl;

    filter_students(s, n, ispisi,
        [](const Student& s) {
            return s.godina == 1 && s.ispiti >= 1;
        });

    cout << "\nStudenti s prosjekom vecim od 3.5:" << endl;

    filter_students(s, n, ispisi,
        [](const Student& s) {
            return s.prosjek > 3.5;
        });

    filter_students(s, n,
        [](Student& s) {
            s.godina++;
        },
        [](const Student& s) {
            return s.ects >= 45;
        });

    cout << "\nStudenti nakon povecanja godine:" << endl;

    for (int i = 0; i < n; i++) {
        ispisi(s[i]);
    }

    return 0;
}