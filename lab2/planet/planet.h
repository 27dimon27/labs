#ifndef PLANET_H
#define PLANET_H

#include <iostream>
//#include <algorithm>
#include <fstream>
#include <cstring>

class planet {
public:
    planet() { name = new char[100]; diam = 0, life = 0, sate = 0; }
    planet(const planet& obj) { 
        delete[] name; name = new char[strlen(obj.name) + 1]; 
        std::strcpy(name, obj.name);
        diam = obj.diam;
        life = obj.life;
        sate = obj.sate;
    }
    ~planet() { delete[] name; }

    friend std::ostream &operator<<(std::ostream &in, planet& x);
    friend std::ifstream &operator>>(std::ifstream &in, planet& x);
    friend std::istream &operator>>(std::istream &in, planet& x);

    planet &operator=(planet &other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            std::strcpy(name, other.name);
            diam = other.diam;
            life = other.life;
            sate = other.sate;
        }
        return *this;
    }

    static int read_db(planet* p, int& c, std::ifstream& file);
    static int write_db(planet* p, int c);
    static void getsort(planet* p, int c);
    static void add(planet* p, int& c);
    static void remove(planet* p, int& c);
    static void getall(planet* p, int c);
    static void change(planet* p);

    void setname(char*);
    void setdiam(int);
    void setlife(bool);
    void setsate(int);

    char* getname();
    int getdiam();
    bool getlife();
    int getsate();


private:
    char* name;
    int diam;
    bool life;
    int sate;
};


#endif