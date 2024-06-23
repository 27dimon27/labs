#include <iostream>
#include <cstring>
#include "containers/myvec.h"
#include "containers/myset.h"

int main() {
    setlocale(LC_ALL, "Russian");


    MyVector<char*> v((char*)"Hello!");
    v.add_element((char*)"Hello!");
    v.add_element((char*)"Hello!");
    v.add_element((char*)"Hello!");
    v.add_element((char*)"Hello!");
    v.add_element((char*)"Hello!");
    std::cout << "Vector v: " << v << std::endl;
    v.add_element((char*)"Hello!");
    v.add_element((char*)"Hello!");
    v.add_element((char*)"Hello!");
    std::cout << "Vector v: " << v << std::endl;
    MyVector<char*> v1 = v;
    std::cout << "Vector v1: " << v1 << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element(0);
    std::cout << "Vector v1: " << v1 << std::endl;
    MySet<char*, MyVector<char*>> s, s1, s2;
    s.add_element((char*)"Yes");
    s.add_element((char*)"Hello!");
    s.add_element((char*)"No");
    char *str = (char*)"Hello!";
    s.add_element(str);
    std::cout << "Set s: " << s << std::endl;
    s1.add_element((char*)"Cat");
    s1.add_element((char*)"No");
    s1.add_element((char*)"Hello!");
    std::cout << "Set s1: " << s1 << std::endl;
    s2 = s1 - s;
    std::cout << "Set s2=s1-s: " << s2 << std::endl;
    std::cout << "Set s1: " << s1 << std::endl;
    std::cout << "Set s: " << s << std::endl;
    s2 = s - s1;
    std::cout << "Set s2=s-s1: " << s2 << std::endl;
    std::cout << "Set s1: " << s1 << std::endl;
    std::cout << "Set s: " << s << std::endl;
    s2 = s1 + s;
    std::cout << "Set s2=s1+s: " << s2 << std::endl;
    std::cout << "Set s1: " << s1 << std::endl;
    std::cout << "Set s: " << s << std::endl;
    s2 = s1 * s;
    std::cout << "Set s2=s1*s: " << s2 << std::endl;
    std::cout << "Set s1: " << s1 << std::endl;
    std::cout << "Set s: " << s << std::endl;
    MySet<char*, MyVector<char*>> s3 = s2;
    std::cout << "Set s3=s2: " << s3 << std::endl;
    if (s3 == s2)
        std::cout << "Set s3=s2\n";
    else
        std::cout << "Set s3!=s2\n";
    if (s3 == s1)
        std::cout << "Set s3=s1\n";
    else
        std::cout << "Set s3!=s1\n";
    if (s1 == s3)
        std::cout << "Set s1=s3\n";
    else
        std::cout << "Set s1!=s3\n";

    return 0;
}
