// Vjezba 6, zadatak 3: napisite klasu LogFile i funkciju log_songs iznad main.

#define _CRT_SECURE_NO_WARNINGS    // za Visual Studio: dopusta std::fopen
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

class LogFile {
    std::FILE* file;
public:
    LogFile(const std::string& name) : file(std::fopen(name.c_str(), "a")) {}
    ~LogFile() { if (file) std::fclose(file); }
    LogFile(const LogFile&) = delete;
    LogFile& operator=(const LogFile&) = delete;
    bool write(const std::string& line) {
        if (!file) return false;
        return std::fputs((line + "\n").c_str(), file) >= 0;
    }
};

int log_songs(const std::vector<std::string>& titles) {
    LogFile log("played.log");
    int count = 0;
    for (const std::string& title : titles) {
        if (title == "STOP") return count;
        if (!log.write(title)) return count;
        count++;
    }
    return count;
}

int main()
{
    std::remove("played.log");     // brise datoteku iz prethodnog pokretanja
    int n = log_songs({"Superhero", "Sports", "STOP", "Matador"});
    std::cout << n << '\n';
    std::cout << log_songs({"One Rizla"}) << '\n';

    // ispis sadrzaja datoteke
    std::FILE* f = std::fopen("played.log", "r");
    char line[100];
    while (std::fgets(line, sizeof line, f))
        std::cout << line;
    std::fclose(f);
    return 0;
}

/*
Ocekivani ispis:

    2
    1
    Superhero
    Sports
    One Rizla
*/
