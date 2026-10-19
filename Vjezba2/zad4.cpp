#include <iostream>
using namespace std;

int twice(int a) {
    return a * 2;
}
auto lambda = [](int a) {
    if (a % 2 == 0) {
        return a/2;
    } else {
        return a*2;
    }
};

void my_transform(int niz[], int n, int (*f)(int)) {

    for (int i = 0; i < n; i++) {
        niz[i] = f(niz[i]);
    }
}

int main() {

    const int n = 5;
    int niz[n] = {3, 2, 4, 5, 1};

    my_transform(niz, n, twice);
    
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;

    my_transform(niz,n,lambda);

        for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
        cout << endl;
    auto suma = [&]{
        int rezultat = 0;
        for (int i = 0; i < n; i++)
        {
            rezultat = rezultat+niz[i];
        }
            
        return rezultat;
        };
    cout << suma();
    cout << endl;
    auto produkt = [&]{
        int rezultat = 1;
        for (int i = 0; i < n; i++)
        {
            rezultat = rezultat*niz[i];
        }
            
        return rezultat;
        };
    cout << produkt();
    cout << endl;
    int prag = 3;
    int s = 0;
    auto suma_s_pragom = [prag, &s](int a) {
        if (a > prag) {
            s = s + a;
        }
    };

    for (int i = 0; i < n; i++) {
        suma_s_pragom(niz[i]);
    }

    cout << s;
    return 0;
}