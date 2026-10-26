#include <iostream>
#include <vector>
using namespace std;


int main(){

int n;
cout << "Unesite broj dana:" << endl;
cin >> n;
vector<double> temperature(n);
for (int i = 0; i < n; i++) {
    cin >> temperature[i];
}



vector<double> promjena;
promjena.reserve(n - 1);

for (auto it = temperature.begin() + 1; it != temperature.end(); it++) {
    promjena.push_back(*it - *(it - 1));
}
cout << "Tempetarture:";
for (double t : temperature) {
    cout << t << " ";
}
cout << endl;
cout << "Promjene:";
for (double x : promjena) {
    cout << x << " ";
}
cout << endl;
temperature.resize(7, temperature.back());
cout << "Izvjestaj:";
for (double t : temperature) {
    cout << t << " ";
}
return 0;
}


