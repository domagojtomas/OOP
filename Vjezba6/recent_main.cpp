// Vjezba 6, zadatak 6: napisite klasu RecentlyPlayed iznad main.

#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed {
    std::string* data;
    int cap, count, next;
public:
    RecentlyPlayed(int capacity) : cap(capacity), count(0), next(0) {
        assert(cap > 0);
        data = new std::string[cap];
    }
    ~RecentlyPlayed() { delete[] data; }
    RecentlyPlayed(const RecentlyPlayed& other) : cap(other.cap), count(other.count), next(other.next) {
        data = new std::string[cap];
        for (int i = 0; i < cap; i++) data[i] = other.data[i];
    }
    RecentlyPlayed& operator=(const RecentlyPlayed& other) {
        if (this != &other) {
            std::string* fresh = new std::string[other.cap];
            for (int i = 0; i < other.cap; i++) fresh[i] = other.data[i];
            delete[] data; data = fresh; cap = other.cap; count = other.count; next = other.next;
        }
        return *this;
    }
    void play(const std::string& title) {
        data[next] = title;
        next = (next + 1) % cap;
        if (count < cap) count++;
    }
    int size() const { return count; }
    int capacity() const { return cap; }
    std::string get(int i) const {
        if (i < 0 || i >= count) return "";
        return data[(next - 1 - i + cap) % cap];
    }
    void print() const {
        for (int i = 0; i < count; i++) {
            if (i > 0) std::cout << ", ";
            std::cout << get(i);
        }
        std::cout << '\n';
    }
};

int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");     // buffer je pun: prepisuje se najstarija
    recent.print();

    RecentlyPlayed copy = recent;             // copy konstruktor
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
