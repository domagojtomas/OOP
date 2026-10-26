#include <iostream>
#include <array>
using namespace std;

constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours) {
    double suma = 0;

    for (double x : hours) {
        suma += x;
    }

    return suma;
}

int best_day(const array<double, DAYS>& hours) {
    int najbolji = 0;

    for (int i = 1; i < DAYS; i++) {
        if (hours[i] > hours[najbolji]) {
            najbolji = i;
        }
    }

    return najbolji + 1;
}

int main() {
    array<double, DAYS> prvi;
    array<double, DAYS> drugi;


    for (int i = 0; i < DAYS; i++) {
        cin >> prvi[i];
    }


    drugi.fill(1.5);

    cout << "Ukupno sati: " << total(prvi) << endl;
    cout << "Najvise ucenja dan: " << best_day(prvi) << endl;

    if (prvi == drugi) {
        cout << "Tjedni su jednaki" << endl;
    }

    if (prvi < drugi) {
        cout << "Prvi tjedan je manji" << endl;
    }

    prvi.swap(drugi);

    return 0;
}