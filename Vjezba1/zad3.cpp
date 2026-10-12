#include <iostream>
using namespace std;

int& find_max(int arr[], int n) {
    int maxIndex{0};

    for (int i{1}; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    return arr[maxIndex];
}

int main() {
    int numbers[] = {4, -7, 12, 0, 9, -3};

    // Ispis početnog niza
    cout << "Pocetni niz: ";
    for (int x : numbers) {
        cout << x << " ";
    }

    // Zamjena negativnih brojeva apsolutnim vrijednostima
    for (int& x : numbers) {
        if (x < 0) {
            x = -x;
        }
    }

    cout << "\nNiz nakon zamjene: ";
    for (int x : numbers) {
        cout << x << " ";
    }

    // Postavljanje najvećeg elementa na 0
    find_max(numbers, 6) = 0;

    cout << "\nNiz nakon postavljanja maksimuma na 0: ";
    for (int x : numbers) {
        cout << x << " ";
    }

    return 0;
}