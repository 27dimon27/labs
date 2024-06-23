#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include "myvec.h"

template<class INF, class MyVector>
class MySet : public MyVector {

public:

    MySet() : MyVector() {};
    MySet(INF el) : MyVector(el) {};

    MySet operator+(const MySet &s) {
        MySet temp;
        for (int i = 0; i < s.MyVector::get_size(); ++i) {
            temp.add_element(s.MyVector::pdata[i]);
        }
        for (int i = 0; i < MyVector::get_size(); ++i) {
            temp.add_element(MyVector::pdata[i]);
        }
        return temp;
    }
    MySet operator*(const MySet &s) {
        MySet temp;
        bool flag;
        for (int i = 0; i < MyVector::get_size(); ++i) {
            flag = false;
            for (int j = 0; j < s.MyVector::get_size(); ++j) {
                if (MyVector::pdata[i] == s.MyVector::pdata[j]) { flag = true; break; }
            }
            if (flag == true) { temp.add_element(MyVector::pdata[i]); }
        }
        return temp;
    }
    MySet operator-(const MySet &s) {
        MySet temp;
        bool flag;
        for (int i = 0; i < MyVector::get_size(); ++i) {
            flag = true;
            for (int j = 0; j < s.MyVector::get_size(); ++j) {
                if (MyVector::pdata[i] == s.MyVector::pdata[j]) { flag = false; break; }
            }
            if (flag == true) { temp.add_element(MyVector::pdata[i]); }
        }
        return temp;
    }

    bool is_element(INF el) {
        if (MyVector::find(el) != -1) {
            return true;
        } else { return false; }
    }
    void add_element(INF el) {
        for (int i = 0; i < MyVector::get_size(); ++i) {
            if (MyVector::pdata[i] == el) {
                return;
            }
        }
        MyVector::add_element(el);
    }
    void delete_element(INF el) {
        int index = MyVector::find(el);
        if (index != -1) { MyVector::delete_element(index); }
    }

    MySet &operator+=(MySet &s) {
        bool flag;
        for (int i = 0; i < s.MyVector::get_size(); ++i) {
            flag = true;
            for (int j = 0; j < MyVector::get_size(); ++j) {
                if (s.MyVector::pdata[i] == MyVector::pdata[j]) { flag = false; break; }
            }
            if (flag == true) { MyVector::add_element(s.MyVector::pdata[i]); }
        }
    }
    MySet &operator*=(MySet &s) {
        bool flag;
        for (int i = 0; i < MyVector::get_size(); ++i) {
            flag = false;
            for (int j = 0; j < s.MyVector::get_size(); ++j) {
                if (MyVector::pdata[i] == s.MyVector::pdata[j]) { flag = true; break; }
            }
            if (flag == false) { MyVector::delete_element(i); --i; }
        }
    }
    MySet &operator-=(MySet &s) {
        bool flag;
        for (int i = 0; i < MyVector::get_size(); ++i) {
            flag = true;
            for (int j = 0; j < s.MyVector::get_size(); ++j) {
                if (MyVector::pdata[i] == s.MyVector::pdata[j]) { flag = false; break; }
            }
            if (flag == false) { MyVector::delete_element(i); --i; }
        }
    }

};

#endif