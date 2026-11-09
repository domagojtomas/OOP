// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>
#include <algorithm>

// ovdje napisite klasu Volume

class Volume {
    int level;
    int before_mute;
    bool muted;

    bool valid() const { return level >= 0 && level <= 100; }

public:
    static int clamp(int value) {
        if (value < 0) return 0;
        if (value > 100) return 100;
        return value;
    }

    Volume(int l) : level(clamp(l)), before_mute(level), muted(false) {
        assert(valid());
    }
    Volume() : Volume(50) {}

    int get() const { return level; }
    void up(int step = 10) {
        level = clamp(static_cast<int>(std::max(0LL, std::min(100LL, static_cast<long long>(level) + step))));
        assert(valid());
    }
    void down(int step = 10) {
        level = clamp(static_cast<int>(std::max(0LL, std::min(100LL, static_cast<long long>(level) - step))));
        assert(valid());
    }
    void mute() {
        if (!muted) before_mute = level;
        level = 0;
        muted = true;
        assert(valid());
    }
    void unmute() {
        if (muted) level = before_mute;
        muted = false;
        assert(valid());
    }
};

int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    50
    100
    0
    100
    0
*/
