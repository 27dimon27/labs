#include <iostream>
#include "mymath/mymath.h"
#include "abc/mymath2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << mymath::sum(5, 7) << std::endl;
    std::cout << mymath2::diff(14, 5) << std::endl;

    return 0;
}