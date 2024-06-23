#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>
#include <map>

class Point {
public:
    double x, y;
    Point() { x = y = 0; }
    Point(double a, double b) {
        x = a;
        y = b;
    }
    void setx(double i) {
        x = i;
    }
    void sety(double i) {
        y = i;
    }
    double getx() {
        return x;
    }
    double gety() {
        return y;
    }
    friend std::ostream& operator<<(std::ostream& out, Point& p) {
        out << p.x << ' ' << p.y << std::endl;
        return out;
    }
};

class Graduate {
    std::string name;    // фамилия
    double rating;  // рейтинг
public:
    Graduate() {
        name = "";
        rating = 0;
    }
    Graduate(std::string Name, double Rating) {
        name = Name;
        rating = Rating;
    }
    void setrating(int x) {
        rating = x;
    }
    int getrating() {
        return rating;
    }
    friend std::ostream& operator<<(std::ostream& out, Graduate& x) {
        out << x.name << ' ' << x.rating << '\n';
        return out;
    }
    friend bool operator>(Graduate x, int a) {
        if (x.rating > a) {
            return true;
        } else { return false; }
    }
};

void print_vec_4(std::vector<std::string> names, std::vector<std::string> nums) {
    for (int i = 0; i < names.size(); ++i) {
        std::cout << i + 1 << ". " << names[i] << ' ' << nums[i] << std::endl;
    }
    std::cout << std::endl;
}

void print_list_4(std::list<std::string> names, std::list<std::string> nums) {
    int i = -1, i1 = -1;
    for (std::string s1 : names) {
        ++i;
        for (std::string s2 : nums) {
            ++i1;
            if (i == i1) {
                std::cout << s1 << ' ' << s2 << std::endl;
            }
        }
        i1 = -1;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int choose;
    std::cout << "Input number of task: ";
    std::cin >> choose;
    while (choose != 0) {
        switch (choose) {

            case 1:
            {
                std::string name, surname, otch, all;
                std::cout << "Input name, surname and patronymic: ";
                std::cin >> name >> surname >> otch;
                std::cout << "All: ";
                all = name + ' ' + surname + ' ' + otch;
                std::cout << all << std::endl;
            }
            break;

            case 2:
            {
                std::string text, res;
                std::cout << "Input string: ";
                std::cin.ignore();
                std::getline(std::cin, text);
                int b, e;
                for (int i = 0; i < text.length(); ++i) {
                    if (text[i] == '[') {
                        b = i;
                    } else if (text[i] == ']') {
                        e = i;
                        break;
                    }
                }
                for (int i = b; i <= e; ++i) {
                    res += text[i];
                }
                std::cout << "Result: " << res << std::endl;
            }
            break;

            case 3:
            {
                std::string str;
                std::ifstream file("test.txt");
                std::ofstream out;
                out.open("res.txt");
                if (file.is_open() && out.is_open()) {
                    while (std::getline(file, str)) {
                        if (str[str.length() - 1] == '!') {
                            out << str << '\n';
                        }
                    }
                }
                file.close();
                out.close();
            }
            break;

            case 4:
            {
                std::vector<std::string> names, numbers;
                int act;
                std::cout << "1. Add\n2. Output all\n3. Search\n";
                std::cin >> act;
                while (act != 0) {
                    switch (act) {
                        case 1:
                        {
                            std::string name, num;
                            std::cout << "Input name and number: ";
                            std::cin >> name >> num;
                            names.push_back(name), numbers.push_back(num);
                        }
                        break;

                        case 2:
                        {
                            print_vec_4(names, numbers);
                        }
                        break;

                        case 3:
                        {
                            bool f = true;
                            std::string name;
                            std::cout << "Input name: ";
                            std::cin >> name;
                            for (int i = 0; i < names.size(); ++i) {
                                if (strcmp(name.c_str(), names[i].c_str()) == 0) {
                                    std::cout << "Number: " << numbers[i] << std::endl;
                                    f = false;
                                    std::string s;
                                    std::cout << "Do u want to delete it? (y/n)\n";
                                    std::cin >> s;
                                    if (s == "y") {
                                        names.erase(names.begin() + i);
                                        numbers.erase(numbers.begin() + i);
                                    }
                                    break;
                                }
                            }
                            if (f) std::cout << "Nothing find!\n\n";
                        }
                        break;
                    }
                    std::cout << "1. Add\n2. Output all\n3. Search\n";
                    std::cin >> act;
                }
            }
            break;

            case 5:
            {
                std::vector<Graduate> students = { {"Ivanov", 99}, {"Petrov", 430}, {"Semenov", 70}, {"Kotov", 540},
                {"Belih", 230}, {"Chernih", 350} };
                for (int i = 0; i < students.size(); ++i) {
                    std::cout << i + 1 << ". " << students[i];
                }
                std::cout << std::endl;
                int m = 0, max_rate = 0;
                for (int i = 0; i < students.size(); ++i) {
                    if (students[i].getrating() > max_rate) {
                        m = i;
                        max_rate = students[i].getrating();
                    }
                }
                std::cout << students[m] << std::endl;
                int up;
                std::cout << "Input increase number: ";
                std::cin >> up;
                for (int i = 0; i < students.size(); ++i) {
                    students[i].setrating(students[i].getrating() + up);
                }
                for (int i = 0; i < students.size(); ++i) {
                    std::cout << students[i];
                }
                std::cout << std::endl;
            }
            break;

            case 6:
            {
                std::list<std::string> names, numbers;
                int act;
                std::cout << "1. Add\n2. Output all\n3. Search\n";
                std::cin >> act;
                while (act != 0) {
                    switch (act) {
                        case 1:
                        {
                            std::string name, num;
                            std::cout << "Input name and number: ";
                            std::cin >> name >> num;
                            names.push_back(name), numbers.push_back(num);
                        }
                        break;

                        case 2:
                        {
                            print_list_4(names, numbers);
                        }
                        break;

                        case 3:
                        {
                            bool f = true;
                            int i = -1;
                            std::list<std::string>::iterator it = numbers.begin();
                            std::list<std::string>::iterator it1 = names.begin();
                            std::string name;
                            std::cout << "Input name: ";
                            std::cin >> name;
                            for (std::string s : names) {
                                ++i;
                                std::cout << name.c_str() << ' ' << s.c_str() << std::endl;
                                if (strcmp(name.c_str(), s.c_str()) == 0) {
                                    std::advance(it, i);
                                    std::advance(it1, i);
                                    std::cout << "Number: " << *it << std::endl;
                                    f = false;
                                    std::string s;
                                    std::cout << "Do u want to delete it? (y/n)\n";
                                    std::cin >> s;
                                    if (s == "y") {
                                        names.erase(it1);
                                        numbers.erase(it);
                                    }
                                    break;
                                }
                            }
                            if (f) std::cout << "Nothing find!\n\n";
                        }
                        break;
                    }
                    std::cout << "1. Add\n2. Output all\n3. Search\n";
                    std::cin >> act;
                }
            }
            break;

            case 7:
            {
                std::list<Point> points = { {1.2, 6.3}, {4.0, 0.7}, {7.2, 0.8}, {5.3, 3.0}, {4.9, 6.6}, {9.3, 0.2} };
                for (Point n : points) {
                    std::cout << n;
                }
                std::cout << std::endl;
                double d = 0;
                double cords[2] = {0, 0};
                for (Point n : points) {
                    if (sqrt((n.getx()*n.getx()) + (n.gety()*n.gety())) > d) {
                        d = sqrt((n.getx()*n.getx()) + (n.gety()*n.gety()));
                        cords[0] = n.getx(), cords[1] = n.gety();
                    }
                }
                std::cout << cords[0] << ' ' << cords[1] << std::endl << std::endl;
                double sd;
                std::cin >> sd;
                for (Point n : points) {
                    double temp = n.getx() - sd;
                    n.setx(temp);
                    std::cout << n;
                }
            }
            break;

            case 8:
            {
                std::map<int, double> s;
                s[1] = 100.0; s[2] = 200.0; s[3] = 300.0;
                s[4] = 400.0; s[5] = 500.0; s[6] = 600.0;
                s[7] = 700.0; s[8] = 800.0; s[9] = 900.0;
                for (int i = 0; i < 10; ++i) {
                    std::cout << i << ' ' << s[i] << std::endl;
                }
                std::cout << std::endl;
                double sum = 0;
                for (int i = 0; i < 10; ++i) {
                    sum += s[i];
                }
                std::cout << "Sum: " << sum << std::endl << std::endl;
                for (int i = 0; i < 10; ++i) {
                    s[i] = s[i] / sum;
                    std::cout << i << ' ' << s[i] << std::endl;
                }
                std::cout << std::endl;
            }
            break;

            case 9:
            {
                std::map<std::string, int> all = { {"1a", 21}, {"1b", 20}, {"2", 25}, {"3a", 20}, {"3b", 23}, {"4a", 25}, {"4b", 25}, {"5a", 26}, {"5b", 25}, {"6a", 19}, {"6b", 18}, {"7a", 26}, {"7b", 25}, {"8", 25}, {"9", 17}, {"10", 15}, {"11", 14} };
                int Class;
                std::cin >> Class;
                int sum = 0;
                for (const auto& el : all) {
                    if (std::stoi(el.first) == Class) {
                        sum += el.second;
                    }
                }
                std::cout << "Class: " << Class << std::endl << "Count: " << sum << std::endl << std::endl;
            }
            break;

        }
        std::cout << "Input number of task: ";
        std::cin >> choose;
    }
    return 0;
}