#ifndef VIRTUAL_FUNC
#define VIRTUAL_FUNC

#include <iostream>
#include <string.h>

class Product{
    public:
        Product();
        virtual ~Product();
        virtual void show() = 0;
};

class Detail: public Product{
    public:
        Detail(int DetailNumber_, char* name_);
        virtual ~Detail();
        virtual void show();
        Detail(const Detail& other);
        Detail& operator=(const Detail& other);
    protected:
        int DetailNumber_;
        char* name_;

};

class Mechanism: public Product{
    public:
        Mechanism(int MechanismNumber_, char* type_);
        virtual ~Mechanism();
        virtual void show();
        Mechanism(const Mechanism& other);
        Mechanism& operator=(const Mechanism& other);
    protected:
        int MechanismNumber_;
        char* type_;
};

class Knot: public Product{
    public:
        Knot(int KnotNumber_, char* condition_);
        virtual ~Knot();
        virtual void show();
        Knot(const Knot& other);
        Knot& operator=(const Knot& other);
    protected:
        int KnotNumber_;
        char* condition_;
};

#endif