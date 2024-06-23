#include "planet/planet.h"
#include "person/person.h"

const int count_of_increasing = 2;

int main() {
    int choose, count, size;
    std::ifstream file("planets.txt");
    file >> size;
    count = size;
    std::cout << "1. Planets" << std::endl << "2. Variant 19" << std::endl;
    std::cin >> choose;
    if (choose == 1) {
        planet* planets = new planet[size];

        while (true) {
            std::cout << "1. Sort" << std::endl << "2. Add" << std::endl << "3. Remove" << 
            std::endl << "4. Get all info" << std::endl << "5. Get data TO file" << 
            std::endl << "6. Get data FROM file" << std::endl << "7. Change" << std::endl << "0. Exit" << std::endl;

            std::cin >> choose;
            std::cout << std::endl;

            switch (choose) {
                case 1:
                    planet::getsort(planets, count);
                    break;
                case 2:
                    planet::add(planets, count);
                    if (count + 1 >= size) {
                        int size1 = size;
                        size *= count_of_increasing;
                        planet* temp = new planet[size];
                        for (int i = 0; i < size1; ++i) { temp[i] = planets[i]; }
                        delete[] planets;
                        planets = temp;
                    }
                    break;
                case 3:
                    planet::remove(planets, count);
                    if (count < size / 2) {
                        size /= 2;
                        planet* temp = new planet[size];
                        for (int i = 0; i < size; ++i) { temp[i] = planets[i]; }
                        delete[] planets;
                        planets = temp;
                    }
                    break;
                case 4:
                    planet::getall(planets, count);
                    break;
                case 5:
                    planet::write_db(planets, count);
                    break;
                case 6:
                    planet::read_db(planets, count, file);
                    break;
                case 7:
                    planet::change(planets);
                    break;
                case 0:
                delete[] planets;
                    return 0;
                default:
                    std::cout << "Wrong number, try again." << std::endl;
                    break;
            }
        }
    } else if (choose == 2) {
        person* persons = new person[size];

        while (true) {
            std::cout << "1. Sort" << std::endl << "2. Add" << std::endl << "3. Remove" << 
            std::endl << "4. Get all info" << std::endl << "5. Get data TO file" << 
            std::endl << "6. Get data FROM file" << std::endl << "7. Change" << std::endl << "0. Exit" << std::endl;

            std::cin >> choose;
            std::cout << std::endl;

            switch (choose) {
                case 1:
                    person::getsort(persons, count);
                    break;
                case 2:
                    person::add(persons, count);
                    if (count + 1 >= size) {
                        int size1 = size;
                        size *= count_of_increasing;
                        person* temp = new person[size];
                        for (int i = 0; i < size1; ++i) { temp[i] = persons[i]; }
                        delete[] persons;
                        persons = temp;
                    }
                    break;
                case 3:
                    person::remove(persons, count);
                    if (count < size / 2) {
                        size /= 2;
                        person* temp = new person[size];
                        for (int i = 0; i < size; ++i) { temp[i] = persons[i]; }
                        delete[] persons;
                        persons = temp;
                    }
                    break;
                case 4:
                    person::getall(persons, count);
                    break;
                case 5:
                    person::write_db(persons, count);
                    break;
                case 6:
                    person::read_db(persons, count);
                    break;
                case 7:
                    person::change(persons);
                    break;
                case 0:
                    delete[] persons;
                    return 0;
                default:
                    std::cout << "Wrong number, try again." << std::endl;
                    break;
            }
        }
    }
}