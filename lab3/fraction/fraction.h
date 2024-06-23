#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

class fraction {

public:

    fraction() { total = 0; ch = 0; zn = 1; }
    fraction(int a) { total = a; ch = 0; zn = 1; }
    fraction(int a, int b) { total = 0; ch = a; zn = b; fraction::made_cor(*this); }
    fraction(int a, int b, int c) { total = a; ch = b; zn = c; fraction::made_cor(*this); }
    fraction(const char* c) {
        fraction x;
        x = fraction::setfraction(c, x);
        this->total = x.total;
        this->ch = x.ch;
        this->zn = x.zn;
    }
    fraction(double x) {
        int y = fraction::count_after_comma(x);
        *this = fraction::convert(x, y);
        fraction::made_cor(*this);
    }
    fraction(char fr[], fraction x) {
        x = fraction::setfraction(fr, x);
        this->total = x.total;
        this->ch = x.ch;
        this->zn = x.zn;
    }
    ~fraction() {}

    friend std::ostream& operator<<(std::ostream& out, fraction& f);
    friend fraction& operator>>(std::istream& in, fraction& f);
    friend fraction operator+(fraction x, fraction y);
    friend fraction operator+(fraction x, double y);
    friend fraction operator+(double y, fraction x);
    friend double operator+=(double& y, fraction x);
    friend fraction operator+(fraction x, int i);
    friend fraction operator+(int i, fraction x);

    static fraction setfraction(const char* fr, fraction& x);

    static void made_cor(fraction& x);

    static void made_incor(fraction& x);

    static fraction convert(double x, int p);

    static int count_after_comma(double x);

    fraction operator+=(fraction other) {
        int a, b;
        fraction::made_incor(*this), fraction::made_incor(other);
        a = this->ch * other.zn + this->zn * other.ch;
        b = this->zn * other.zn;
        this->ch = a;
        this->zn = b;
        fraction::made_cor(*this);
        return *this;
    }

    fraction operator+=(double y) {
        int a, b;
        int exp;
        exp = count_after_comma(y);
        fraction x1 = fraction::convert(y, exp);
        fraction::made_incor(*this);
        fraction::made_incor(x1);
        a = this->ch * x1.zn + this->zn * x1.ch;
        b = this->zn * x1.zn;
        this->ch = a;
        this->zn = b;
        fraction::made_cor(*this);
        return *this;
    }

    fraction operator+=(int i) {
        fraction x1(i);
        *this += x1;
        return *this;
    }

    void settotal(int);
    void setch(int);
    void setzn(int);

    int getTotal();
    int getCh();
    int getZn();

private:

    int total;
    int ch;
    int zn;

};

#endif