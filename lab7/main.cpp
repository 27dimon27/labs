#include "MyVector/myvector.h"
#include "Virtual_Classes/virtual_classes.h"

#include <iostream>

using namespace std;

void print(const MyVector<Product*>& vec) {
    for (int i = 0; i < vec.get_size(); i++) {
        cout << "Index " << i << ": " << endl;
        vec[i]->show();
    }
}

bool remove(MyVector<Product*>& vec, int index) {
    if (index < 0 || index >= vec.get_size()) {
        return false;
    }
    delete vec[index];
    vec.delete_element(index);
    return true;
}

void clear(MyVector<Product*>& vec) {
    while (vec.get_size() > 0) {
        delete vec[0];
        vec.delete_element(0);
    }
}

int main(){
    MyVector<Product*> docs;
    int a;
    char* b;
    std::cout << "Input number of item and its' characteristic:\n" << "1. ";
    std::cin >> a >> b;
    docs.add_element(new Detail(a, b));
    std::cout << "2. ";
    std::cin >> a >> b;
    docs.add_element(new Mechanism(a, b));
    std::cout << "3. ";
    std::cin >> a >> b;
    docs.add_element(new Knot(a, b));

    cout << "All vector: " << endl;
    print(docs);

    cout << "Delete index number 1: " << endl;
    remove(docs, 0);
    print(docs);

    cout << "Output after cleaning: " << endl;
    clear(docs);
    print(docs);
    return 0;
}