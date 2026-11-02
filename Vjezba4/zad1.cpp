#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

vector<int> v;
int a;
while(cin >> a && a != 0) {
        v.push_back(a);
    }

int negativni = count_if(v.begin(),v.end(),
[](int broj){
    return broj < 0;
});
cout << "Negativni:" << negativni << endl;

auto it = find_if(v.begin(),v.end(),
[](int a){
    return a%3 == 0;
});

cout << "Broj:" << *it <<' ';
cout << "Pozicija:" << it-v.begin() << endl;

auto jt = minmax_element(v.begin(),v.end(),
[](int a,int b){
    return a < b;
});

cout << "Min" << *jt.first << ' ' << jt.first - v.begin() << ' ' << "Max:" << *jt.second << ' ' << jt.second - v.begin()<<endl; 

v.erase(remove_if(v.begin(),v.end(),
[](int a){
    return a%3==0;
}), v.end());

for (int a : v)
{
    cout << a << ' ';
}
return 0;



}