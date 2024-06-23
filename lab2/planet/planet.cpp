#include "planet.h"

class planet;

int planet::read_db(planet* p, int& c, std::ifstream& file) {
    if (!file) { std::cout << "Failed to open the file." << std::endl; return 1; }
    for (int i = 0; i < c; ++i) {
        file >> p[i];
    }
    file.close();
    return 0;
}

int planet::write_db(planet* p, int c) {
    std::ofstream file("outplanets.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return 1; }
    for (int i = 0; i < c; ++i) {
        file << p[i];
    }
    file.close();
    return 0;
}

void planet::getsort(planet* p, int c) {
    planet temp;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c - i - 1; ++j) {
            if (strcmp(p[j].getname(), p[j + 1].getname()) > 0) {
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }
}

void planet::add(planet* p, int& c) {
    std::cin >> p[c];
    ++c;
}

void planet::remove(planet* p, int& c) {
    int number;
    planet temp;
    std::cout << "Input number of planet: ";
    std::cin >> number;
    for (int i = number - 1; i < c - 1; ++i) {
        temp = p[i]; p[i] = p[i + 1]; p[i + 1] = temp;
    }
    --c;
}

void planet::getall(planet* p, int c) {
    for (int i = 0; i < c; ++i) {
        std::cout << "Planet #" << i + 1 << ": " << p[i];
    }
}

void planet::change(planet* p) {
    int number;
    std::cout << "Input number of planet: ";
    std::cin >> number;
    std::cin >> p[number - 1];
}

void planet::setname(char* x) {
    delete[] name;
    name = new char[strlen(x) + 1];
    std::strcpy(name, x);
}
void planet::setdiam(int x) {
    diam = x;
}
void planet::setlife(bool x) {
    life = x;
}
void planet::setsate(int x) {
    sate = x;
}

char* planet::getname() {
    return name;
}
int planet::getdiam() {
    return diam;
}
bool planet::getlife() {
    return life;
}
int planet::getsate() {
    return sate;
}

std::ostream &operator<<(std::ostream& out, planet& x) {
    out << x.name << ' ' << x.diam << ' ' << std::boolalpha << x.life << ' ' << x.sate << std::endl;
    return out;
}
std::ifstream &operator>>(std::ifstream& in, planet& x) {
    char Name[100];
    int Diam, Sate;
    bool Life;
    in >> Name >> Diam >> Life >> Sate;
    if (in) {
        x.setname(Name); x.setdiam(Diam); x.setlife(Life); x.setsate(Sate);
    }
    return in;
}
std::istream &operator>>(std::istream& in, planet& x) {
    std::cout << "Name: "; in >> x.name;
    std::cout << "Diameter: "; in >> x.diam;
    std::cout << "Livable: "; in >> x.life;
    std::cout << "Count of satellites: "; in >> x.sate;
    return in;
}