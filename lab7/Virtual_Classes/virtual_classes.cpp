#include "virtual_classes.h"

using namespace std;

Product::Product(){
    cout << "Product()" << endl;
}

Product::~Product() {
    cout << "~Product()" << endl;
}

Detail::Detail(int num, char* name)
    : DetailNumber_(num) {
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    std::cout << "Detail()" << std::endl;
}

Detail::Detail(const Detail& other){
    DetailNumber_ = other.DetailNumber_;
    name_ = new char[strlen(other.name_) + 1];
    strcpy(name_, other.name_);
}

Detail& Detail::operator=(const Detail& other) {
    if (this != &other) {
        delete[] name_;
        name_ = new char[strlen(other.name_) + 1];
        strcpy(name_, other.name_);
        DetailNumber_ = other.DetailNumber_;
    }
    return *this;
}

Detail::~Detail() {
    delete[] name_;
    cout << "~Detail()" << endl;
}

void Detail::show(){
    cout << "Detail Number: " << DetailNumber_ << endl;
    cout << "Name: " << name_ << endl;
}

Mechanism::Mechanism(int num, char* type)
    : MechanismNumber_(num){
    type_ = new char[strlen(type) + 1];
    strcpy(type_, type);
    std::cout << "Mechanism()" << std::endl;
}

Mechanism::Mechanism(const Mechanism& other){
    MechanismNumber_ = other.MechanismNumber_;
    type_ = new char[strlen(other.type_) + 1];
    strcpy(type_, other.type_);
}

Mechanism& Mechanism::operator=(const Mechanism& other) {
    if (this != &other) {
        delete[] type_;
        MechanismNumber_ = other.MechanismNumber_;
        type_ = new char[strlen(other.type_) + 1];
        strcpy(type_, other.type_);
    }
    return *this;
}

Mechanism::~Mechanism() {
    delete[] type_;
    std::cout << "~Mechanism()" << std::endl;
}

void Mechanism::show(){
    std::cout << "Mechanism Number: " << MechanismNumber_ << std::endl;
    std::cout << "Type: " << type_ << std::endl;
}


Knot::Knot(int num, char* condition)
    : KnotNumber_(num) {
    condition_ = new char[strlen(condition) + 1];
    strcpy(condition_, condition);
    std::cout << "Knot()" << std::endl;
}

Knot::Knot(const Knot& other){
    KnotNumber_ = other.KnotNumber_;
    condition_ = new char[strlen(other.condition_) + 1];
    strcpy(condition_, other.condition_);
}

Knot& Knot::operator=(const Knot& other) {
    if (this != &other) {
        delete[] condition_;
        KnotNumber_ = other.KnotNumber_;
        condition_ = new char[strlen(other.condition_) + 1];
        strcpy(condition_, other.condition_);
    }
    return *this;
}


Knot::~Knot() {
    delete[] condition_;
    std::cout << "~Knot()" << std::endl;
}

void Knot::show(){
    std::cout << "Knot Number: " << KnotNumber_ << std::endl;
    std::cout << "Condition: " << condition_ << std::endl;
}