#include <iostream>
using namespace std;

template<typename T>
inline bool ascending(T a,T b){
    return a > b;
};
template<typename T>
inline bool descending(T a,T b){
    return a < b;
};
template <typename T>
void my_sort(T niz[], int n, bool (*provjera)(T,T)){
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            if (provjera(niz[j], niz[j + 1])) {

                T temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;

            }
        }
    }

};
int main(){
    const int n = 5;
    int niz_int[n] = {4,2,5,3,1};
    double niz[n] = {4.4,2.6,5.4,3.2,1.6};
    char niz_char[n] = {'e','a','c','b','d'};
    cout << "Asc:" << endl;
    my_sort(niz_int,n,ascending<int>);
    for (int i = 0; i < n; i++) {
        cout << niz_int[i] << " ";
    }
    my_sort(niz,n,ascending<double>);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
    my_sort(niz_char,n,ascending<char>);
    for (int i = 0; i < n; i++) {
        cout << niz_char[i] << " ";
    }


    cout << endl;
    cout << "Desc:" << endl;
    my_sort(niz_int,n,descending<int>);
    for (int i = 0; i < n; i++) {
        cout << niz_int[i] << " ";
    }
    my_sort(niz,n,descending<double>);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
    my_sort(niz_char,n,descending<char>);
    for (int i = 0; i < n; i++) {
        cout << niz_char[i] << " ";
    }
    // my_sort(niz,n,descending<double>);
    // cout << "Niz desc:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << niz[i] << " ";
    //}
}

