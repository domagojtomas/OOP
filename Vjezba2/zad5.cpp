#include <iostream>
using namespace std;

double add(double a, double b){
    return a+b;
}
double subtract(double a, double b){
    return a-b;
}
double multiply(double a, double b){
    return a*b;
}
double divide(double a, double b){
    return a/b;
}

double (*funkcije[4])(double, double) = {add, subtract, multiply, divide};
int main(){
int redni_broj;
double broj1, broj2;
cout << "Unesite broj operacije: ";
cin >> redni_broj;
cout << endl;
cout << "Unesite broj 1: ";
cin >> broj1;

cout << "Unesite broj 2: ";
cin >> broj2;
if (redni_broj == 3 && broj2 == 0) {
    cout << "Dijeljenje s nulom nije dozvoljeno!" << endl;
    return 1;
}
cout << endl;
cout << funkcije[redni_broj](broj1, broj2);
}
