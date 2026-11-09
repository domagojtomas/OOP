// Vjezba 5, zadatak 3: napisite strukturu Song i klasu Album iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite Song i Album

struct Song {
    std::string title;
    std::string artist;
    int seconds;
};

class Album {
    std::string title;
    int year;
    std::vector<Song> songs;

public:
    Album(std::string t, int y, Song first)
        : title(t), year(y), songs{first} {}

    bool add(Song s) {
        for (const Song& song : songs)
            if (song.title == s.title) return false;
        songs.push_back(s);
        return true;
    }

    int duration() const {
        int total = 0;
        for (const Song& song : songs) total += song.seconds;
        return total;
    }

    void print() const {
        int total = duration();
        std::cout << title << " (" << year << "), " << songs.size()
                  << " pjesme, " << total / 60 << ':';
        if (total % 60 < 10) std::cout << '0';
        std::cout << total % 60 << '\n';
        for (std::size_t i = 0; i < songs.size(); ++i)
            std::cout << "  " << i + 1 << ". " << songs[i].title << '\n';
    }
};

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';   // vec postoji
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/
