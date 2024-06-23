#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <cstring>

class person {
public:
    person() { surname = new char[1]; surname[0] = '\0'; name = new char[1]; name[0] = '\0'; age = 0, sal = 0; }
    person(const person& obj) { 
        delete[] surname; delete[] name; surname = new char[strlen(obj.surname) + 1]; name = new char[strlen(obj.name) + 1];
        std::strcpy(surname, obj.surname);
        std::strcpy(name, obj.name);
        age = obj.age;
        sal = obj.sal;
    }
    ~person() { delete[] surname; delete[] name; }

    friend std::ostream &operator<<(std::ostream &in, person& x);
    friend std::ifstream &operator>>(std::ifstream &in, person& x);
    friend std::istream &operator>>(std::istream &in, person& x);

    person &operator=(person &other) {
        if (this != &other) {
            std::strcpy(surname, other.surname);
            std::strcpy(name, other.name);
            age = other.age;
            sal = other.sal;
        }
        return *this;
    }

    static int read_db(person* p, int& c);
    static int write_db(person* p, int c);
    static void getsort(person* p, int c);
    static void add(person* p, int& c);
    static void remove(person* p, int& c);
    static void getall(person* p, int c);
    static void change(person* p);

    void setsurname(char*);
    void setname(char*);
    void setage(int);
    void setsal(int);

    char* getsurname();
    char* getname();
    int getage();
    int getsal();


private:
    char* surname;
    char* name;
    int age;
    int sal;
};


#endif