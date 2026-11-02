#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const string& password) {
    PasswordInfo p{};

    p.length = password.size();

    for (unsigned char c : password) {
        if (isdigit(c)) {
            p.digits++;
        }
        else if (isupper(c)) {
            p.uppercase++;
        }
        else if (ispunct(c)) {
            p.special++;
        }
    }

    return p;
}
bool if_strong(const PasswordInfo& info){
    if(info.digits >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1){
        return true;
    }else return false;
}
int main(){
    string password = "Lozinka123";
    PasswordInfo rezultat = analyze(password);
    
    cout << rezultat.length << endl;
    cout << rezultat.digits << endl;
    cout << rezultat.uppercase << endl;
    cout << rezultat.special << endl;

    bool provjera = if_strong(rezultat);
    if (provjera == true)
    {
        cout << "jaka";
    }else cout << "slaba";
    
    return 0;

}

