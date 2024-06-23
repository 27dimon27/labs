#include "Stack/Stack.h"

template<class DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    bool flag = true;
    int temp = n;
    while (flag == true) {
        for (int i = 2; i < n / 2 + 1; ++i) {
            if (temp % i == 0) {
                stack.push(i);
                temp /= i;
                flag = false;
                break;
            }
        }
        if (flag == true) {
            break;
        };
        flag = true;
    }
}

int main() {
    
    int n = 3960;
    MyStack<int> s;
    MyStack<int> rs;
    Multipliers(n, s);
    std::cout << n << " = ";
    while (!s.empty()) {
        std::cout << s.top_inf();
        rs.push(s.top_inf());
        s.pop();
        if (!s.empty()) { std::cout << " * "; }
    }
    std::cout << std::endl << n << " = ";
    while (!rs.empty()) {
        std::cout << rs.top_inf();
        rs.pop();
        if (!rs.empty()) { std::cout << " * "; }
    }

    MyStack<int> a;
    MyStack<int> b;
    a.push(5);
    a.push(3);
    a.push(-6);
    b = a;
    std::cout << a;
    std::cout << b;

    return 0;
}
