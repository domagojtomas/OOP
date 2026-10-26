#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input_vector(vector<int>& v) {
    int a;

    cout << "Unesite brojeve:" << endl;

    while (cin >> a && a > 0) {
        v.push_back(a);
    }
}

void print_vector(const vector<int>& v) {
    for (auto n : v) {
        cout << n << ' ';
    }
}

void obrnuti_print_vector(vector<int>& v) {
    reverse(v.begin(), v.end());

    for (auto n : v) {
        cout << n << ' ';
    }
}

int main() {

    vector<int> v1;

    input_vector(v1);

    print_vector(v1);

    cout << endl;
    cout << "Obrnuti: ";

    obrnuti_print_vector(v1);

    vector<int> v2;

    for (int i = 0; i < 20; ++i) {
        v2.push_back(i);

        cout << endl;
        cout << v2.size() << '-' << v2.capacity() << " ";
    }

    vector<int> v3;

    v3.reserve(100);

    for (int i = 0; i < 20; ++i) {
        v3.push_back(i);

        cout << endl;
        cout << v3.size() << '-' << v3.capacity() << " ";
    }

    v3.shrink_to_fit();

    cout << endl;
    cout << v3.capacity();

    return 0;
}