#include "Level.h"

// definicije konstruktora i metoda
Level::Level() : enemies{Enemy()}, weapons{} {}
int Level::enemy_count() const { return static_cast<int>(enemies.size()); }
int Level::weapon_count() const { return static_cast<int>(weapons.size()); }
