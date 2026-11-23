// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>

// ovdje napisite klasu IntStack
class IntStack {
    int* data;
    int count;
    int capacity;
public:
    IntStack() : data(nullptr), count(0), capacity(0) {}
    ~IntStack() { delete[] data; }
    IntStack(const IntStack& other) : data(new int[other.capacity]), count(other.count), capacity(other.capacity) {
        for (int i = 0; i < count; ++i) data[i] = other.data[i];
        std::cout << "copy konstruktor\n";
    }
    IntStack& operator=(const IntStack& other) {
        std::cout << "copy assignment\n";
        if (this == &other) return *this;
        int* new_data = new int[other.capacity];
        for (int i = 0; i < other.count; ++i) new_data[i] = other.data[i];
        delete[] data;
        data = new_data;
        count = other.count;
        capacity = other.capacity;
        return *this;
    }
    IntStack(IntStack&& other) noexcept : data(other.data), count(other.count), capacity(other.capacity) {
        other.data = nullptr;
        other.count = 0;
        other.capacity = 0;
        std::cout << "move konstruktor\n";
    }
    IntStack& operator=(IntStack&& other) noexcept {
        std::cout << "move assignment\n";
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        count = other.count;
        capacity = other.capacity;
        other.data = nullptr;
        other.count = 0;
        other.capacity = 0;
        return *this;
    }
    void push(int value) {
        if (count == capacity) {
            int new_capacity = capacity == 0 ? 2 : capacity * 2;
            int* new_data = new int[new_capacity];
            for (int i = 0; i < count; ++i) new_data[i] = data[i];
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        data[count++] = value;
    }
    int top() const { return data[count - 1]; }
    int size() const { return count; }
};


int main()
{
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = std::move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/
