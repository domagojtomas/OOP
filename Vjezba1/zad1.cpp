#include <iostream>
using namespace std;

int main(){
    int a{};
    int b{};
    cout << "Unesi a:";
    cin >> a;
    cout << "Unesi b:";
    cin >> b;

    int zbroj =  a+b;
    double aritmeticka = (a+b)/ 2.0;
    bool usporedba{a>b};

    cout << "Zbroj:" << zbroj << endl;
    cout << "Aritmeticka sredina:" << aritmeticka << endl;
    cout << "A > B" << usporedba << endl;

}