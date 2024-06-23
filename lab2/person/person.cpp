#include "person.h"

class person;

int person::read_db(person* p, int& c) {
    std::ifstream file("var19.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return 1; }
    file >> c;
    for (int i = 0; i < c; ++i) {
        file >> p[i];
    }
    file.close();
    return 0;
}

int person::write_db(person* p, int c) {
    std::ofstream file("var19.txt");
    if (!file) { std::cout << "Failed to open the file." << std::endl; return 1; }
    for (int i = 0; i < c; ++i) {
        file << p[i];
    }
    file.close();
    return 0;
}

void person::getsort(person* p, int c) {
    person temp;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c - i - 1; ++j) {
            if (strcmp(p[j].getsurname(), p[j + 1].getsurname()) > 0) {
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }
}

void person::add(person* p, int& c) {
    std::cin >> p[c];
    ++c;
}

void person::remove(person* p, int& c) {
    int number;
    person temp;
    std::cout << "Input number of person: ";
    std::cin >> number;
    for (int i = number - 1; i < c - 1; ++i) {
        temp = p[i]; p[i] = p[i + 1]; p[i + 1] = temp;
    }
    --c;
}

void person::getall(person* p, int c) {
    for (int i = 0; i < c; ++i) {
        std::cout << "Person #" << i + 1 << ": " << p[i];
    }
}

void person::change(person* p) {
    int number;
    std::cout << "Input number of person: ";
    std::cin >> number;
    std::cin >> p[number - 1];
}

void person::setsurname(char* x) {
    delete[] surname;
    surname = new char[strlen(x) + 1];
    std::strcpy(surname, x);
}
void person::setname(char* x) {
    delete[] name;
    name = new char[strlen(x) + 1];
    std::strcpy(name, x);
}
void person::setage(int x) {
    age = x;
}
void person::setsal(int x) {
    sal = x;
}

char* person::getsurname() {
    return surname;
}
char* person::getname() {
    return name;
}
int person::getage() {
    return age;
}
int person::getsal() {
    return sal;
}

std::ostream &operator<<(std::ostream& out, person& x) {
    out << x.surname << ' ' << x.name << ' ' << x.age << ' ' << x.sal << std::endl;
    return out;
}
std::ifstream &operator>>(std::ifstream& in, person& x) {
    char Surname[100], Name[100];
    int Age, Sal;
    in >> Surname >> Name >> Age >> Sal;
    if (in) {
        x.setsurname(Surname); x.setname(Name); x.setage(Age); x.setsal(Sal);
    }
    return in;
}
std::istream &operator>>(std::istream& in, person& x) {
    std::cout << "Surname: "; in >> x.surname;
    std::cout << "Name: "; in >> x.name;
    std::cout << "Age: "; in >> x.age;
    std::cout << "Salary: "; in >> x.sal;
    return in;
}