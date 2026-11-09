#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"

class Player {
    // data memberi
    std::string name;
    const Level& level;

public:
    // konstruktor
    Player(const std::string& name, const Level& level);
    void print() const;      // ime i stanje levela u kojem je igrac
};
