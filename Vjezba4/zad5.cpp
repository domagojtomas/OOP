#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Student{
    string jmbag;
    string surname;
    int points;
};

int main(){

vector<Student> registered{
    {"0302","Kovac",78},
    {"0255","Maric",91},
    {"0410","Novak",78},
    {"0255","Maric",91},
    {"0333","Peric",30},
    {"0117","Babic",45},
    {"0117","Babic",45},
    {"0089","Juric",62},
    {"0520","Maric",55},
};

sort(registered.begin(),registered.end(),
[](const Student& a, const Student& b){
        return a.jmbag < b.jmbag;

        

});
auto it = unique(registered.begin(),registered.end(),
[](const Student& a, const Student& b){
    return (a.jmbag == b.jmbag);


});
registered.erase(it,registered.end());
sort(registered.begin(),registered.end(),
[](const Student& a, const Student& b){
    if (a.points == b.points)
    {
        return a.surname > b.surname;
    }else return a.points > b.points;
    


});
int brojac;
for (const Student& s : registered)
{
    brojac++;
}

 cout << "Prijavljenih:" << brojac << endl; 
 cout << "Unesite prag:" << endl;  
 int prag;
 int redni;
std::cin >> prag;
    for (Student& s : registered)
    {
        if (s.points > prag)
        {
        cout<< redni++ <<'.'<< s.jmbag << ' '; 
        cout << s.surname << ' '; 
        cout << s.points << endl; 
        }
        
        
       
    }
    
return 0;
};


