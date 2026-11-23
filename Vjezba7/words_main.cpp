#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct WordCount {
    std::string word;
    int count;
};

std::string clean(const std::string& word) {
    std::string result;
    for (unsigned char c : word) {
        if (std::isalpha(c)) result += static_cast<char>(std::tolower(c));
    }
    return result;
}

int main() {
    std::ifstream in("tekst.txt");
    if (!in) return 1;
    std::map<std::string, int> freq;
    std::string word;
    while (in >> word) {
        std::string w = clean(word);
        if (!w.empty()) ++freq[w];
    }
    std::cout << "Razlicitih rijeci: " << freq.size() << '\n';
    std::cout << "alice: " << freq["alice"] << '\n';
    std::vector<WordCount> counts;
    for (const auto& p : freq) counts.push_back({p.first, p.second});
    std::sort(counts.begin(), counts.end(), [](const WordCount& a, const WordCount& b) {
        if (a.count != b.count) return a.count > b.count;
        return a.word < b.word;
    });
    for (std::size_t i = 0; i < counts.size() && i < 5; ++i)
        std::cout << counts[i].word << ": " << counts[i].count << '\n';
}
