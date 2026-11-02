#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Song{
    string title;
    string artist;
    int year;
    int plays;
};

void print_song(const Song& s){
    
        cout << s.title <<' ';
        cout << s.artist <<' ';
        cout << s.year <<' ';
        cout << s.plays << endl;
    
}


int main(){
vector<Song> v = {{"Naslov1","Izvodjac1",2025,15},
                  {"Naslov2","Izvodjac1",2023,5},
                  {"Naslov3","Izvodjac1",2015,25},
                  {"Naslov4","Izvodjac1",2025,30},
                  {"Naslov5","Izvodjac1",2026,35}

};

sort(v.begin(),v.end(),
[](const Song& a, const Song& b){
    if (a.year == b.year){
        return a.title < b.title;
    }else return a.year < b.year;

    
});
for (const Song& s : v)
{
    print_song(s);
}

string izvodac;
cin >> izvodac;

int broj = count_if(v.begin(),v.end(),
[izvodac](const Song& a){
    return a.artist == izvodac;

});
auto najstarija = min_element(v.begin(), v.end(),
    [izvodac](const Song& a, const Song& b) {
        if (a.artist != izvodac)
            return false;

        if (b.artist != izvodac)
            return true;

        return a.year < b.year;
    });
if (najstarija != v.end() && najstarija->artist == izvodac) {
    print_song(*najstarija);
}
else {
    cout << "Izvodac nije pronaden";
}
cout << broj;

auto najslusanija = max_element(v.begin(), v.end(),
    [](const Song& a, const Song& b) {
        return a.plays < b.plays;
    });

if (najslusanija != v.end()) {
    print_song(*najslusanija);
}
return 0;   
}