#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool starts_with(const string& s, const string& prefix ){
    if(prefix.size() > s.size()){
        return false;
    }
    return equal(prefix.begin(),prefix.end(),s.begin());
}

bool ends_with(const string& s, const string& suffix){
    if(suffix.size()>s.size()){
        return false;
    }
    return equal(suffix.rbegin(),suffix.rend(),s.rbegin());
}


int main(){
    vector<string> v = {"vjezba04.cpp","slajdovi.pdf",
                      "main.cpp","README.md","vjezba04.h",
                      "notes.txt","vjezba03.cpp"};
    int brojac = 0;
    for(const string& s : v){
        if(ends_with(s,"cpp")){
            brojac++;
        }
    }
    cout << "Broj cpp:" << " " << brojac << endl;
for (auto it = v.begin(); it != v.end();) {
    if (starts_with(*it, "vjezba")) {
        it = v.erase(it);
    } else {
        ++it;
    }
}
    for (auto s : v)
    {
        cout << s << " ";
    }
    
    return 0;
}