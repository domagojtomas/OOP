#include <iostream>
using namespace std;

inline bool ascending(int a,int b){
    return a > b;
};

inline bool descending(int a,int b){
    return a < b;
};
void my_sort(int niz[], int n, bool (*provjera)(int, int)){
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            if (provjera(niz[j], niz[j + 1])) {

                int temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;

            }
        }
    }

};
int main(){
    const int n = 5;
    int niz[n] = {4,2,5,3,1};
    cout << "Niz:" << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
    int provjera = descending(3,5);
    my_sort(niz,n,ascending);
    cout << "Niz asc:" << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
    my_sort(niz,n,descending);
    cout << "Niz desc:" << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
}

