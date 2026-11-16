#include <iostream>
#include <string>

class Ticket {
    std::string concert;
    int id;
    static int count;
public:
    Ticket(const std::string& name) : concert(name), id(++count) {}
    Ticket(const Ticket&) = delete;
    Ticket& operator=(const Ticket&) = delete;
    int get_id() const { return id; }
    static int issued() { return count; }
};

int Ticket::count = 0;

void print(const Ticket& t) { std::cout << t.get_id() << '\n'; }

int main() {
    Ticket t1("Shame, Zagreb");
    Ticket t2("Viagra Boys, Ljubljana");
    print(t1);
    std::cout << t2.get_id() << '\n';
    // Ticket t4 = t1; // kopiranje je zabranjeno
    return 0;
}
