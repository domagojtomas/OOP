// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.

#include <iostream>

class IntStack {
    int* data;
    int count;
    int cap;
public:
    IntStack(int initial = 2) : count(0), cap(initial > 0 ? initial : 2) { data = new int[cap]; }
    ~IntStack() { delete[] data; }
    IntStack(const IntStack& other) : count(other.count), cap(other.cap) {
        data = new int[cap];
        for (int i = 0; i < count; i++) data[i] = other.data[i];
    }
    IntStack& operator=(const IntStack& other) {
        if (this != &other) {
            int* fresh = new int[other.cap];
            for (int i = 0; i < other.count; i++) fresh[i] = other.data[i];
            delete[] data;
            data = fresh; count = other.count; cap = other.cap;
        }
        return *this;
    }
    void push(int x) {
        if (count == cap) {
            int* fresh = new int[cap * 2];
            for (int i = 0; i < count; i++) fresh[i] = data[i];
            delete[] data;
            data = fresh; cap *= 2;
        }
        data[count++] = x;
    }
    void pop() { if (count > 0) count--; }
    int top() const { return count > 0 ? data[count - 1] : 0; }
    bool empty() const { return count == 0; }
    int size() const { return count; }
    int capacity() const { return cap; }
};

int main()
{
    IntStack s;
    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
    IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
    c.pop();
    c.push(99);
    std::cout << s.top() << ' ' << c.top() << '\n';
    while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
    std::cout << '\n';
    return 0;
}

/*
Ocekivani ispis:

    5 8 50
    50 99
    50 40 30 20 10
*/
