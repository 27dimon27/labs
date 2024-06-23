#include "fraction.h"

class fraction;

void fraction::settotal(int x) {
    total = x;
}
void fraction::setch(int x) {
    ch = x;
}
void fraction::setzn(int x) {
    zn = x;
}

int fraction::getTotal() {
    return total;
}
int fraction::getCh() {
    return ch;
}
int fraction::getZn() {
    return zn;
}


fraction fraction::setfraction(const char* fr, fraction& x) {
        bool f = false;
        if (fr[0] == '-') { f = true; }
        int i_s = f;
        int i_e = i_s;
        while (i_e < strlen(fr)) {
            char temp[100];
            if (fr[i_e] != ' ' ) {
                if (fr[i_e] != '/') { ++i_e; }
                else { strncpy(temp, fr + i_s, i_e); x.ch = std::atoi(temp); strncpy(temp, fr + i_e + 1, strlen(fr) - i_e); x.zn = atoi(temp); break; }
            } else {
                strncpy(temp, fr + i_s, i_e + 1); x.total = atoi(temp); i_s = i_e + 1; i_e = i_s;
            }
            if (i_e + 1 >= strlen(fr)) {
                strncpy(temp, fr, strlen(fr));
                x.total = std::atoi(temp);
                break;
            }
        }

        fraction::made_cor(x);

        if (f == true) {
            if (x.total == 0) { x.ch -= x.ch * 2; }
            else { x.total -= x.total * 2; }
        }
        return x;
}

void fraction::made_cor(fraction& x) {
    fraction::made_incor(x);
    while (abs(x.ch) >= x.zn) {
        x.total = x.total + pow(-1, (x.ch < 0)); x.ch = x.ch - x.zn * pow(-1, (x.ch < 0));
    }
    if (x.total != 0) { x.ch = abs(x.ch); }
    bool f1;
    while (true) {
        f1 = true;
        for (int i = 2; i <= abs(x.ch); ++i) {
            if ((abs(x.ch) % i == 0) && (x.zn % i == 0)) {
                x.ch /= i; x.zn /= i;
                f1 = false;
                break;
            }
        }
        if (f1 == true) { break; }
    }
}

void fraction::made_incor(fraction& x) {
    if (x.getTotal() != 0) {
        x.setch(x.getZn() * x.getTotal() + pow(-1, (x.getTotal() < 0)) * x.getCh());
        x.settotal(0);
    }
}

fraction fraction::convert(double x, int p) {
        fraction f;
        while (abs(x) >= 1) { x = x + pow(-1, (x > 0)); f.total = f.total + pow(-1, (x < 0)); }
        if (x < 0 && f.total != 0) {
            x -= x * 2;
            f.ch = x * pow(10, p) + (bool)(p <= 2);
        } else { f.ch = x * pow(10, p) + (bool)(p <= 2); }
        f.zn = pow(10, p) + (bool) (p % 2 == 0);
        return f;
}

int fraction::count_after_comma(double x) {
        int t;
        for (int i = 0; i < 10; ++i) {
            t = round(x);
            if (fabs(x - t) <= 0.00000000001) { return i; }
            x *= 10;
        }
    return 10;
}


std::ostream& operator<<(std::ostream& out, fraction& f) {
    if (f.getCh() == 0) {
        out << f.getTotal() << std::endl;
    } else if (f.getTotal() == 0) {
        out << f.getCh() << '/' << f.getZn() << std::endl;
    } else {
        out << f.getTotal() << ' ' << f.getCh() << '/' << f.getZn() << std::endl;
    }
    return out;
}

fraction& operator>>(std::istream& in, fraction& f) {
    char s[100];
    std::fgets(s, 100, stdin);
    f = fraction(s, f);
    return f;
}

fraction operator+(fraction x, fraction y) {
    fraction res;
    fraction::made_incor(x), fraction::made_incor(y);
    if (x.getZn() == y.getZn()) {
        res.setch(x.getCh() + y.getCh());
        res.setzn(x.getZn());
    } else {
        res.setzn(x.getZn() * y.getZn());
        res.setch(x.getCh() * y.getZn() + y.getCh() * x.getZn());
    }
    fraction::made_cor(res);
    return res;
}

fraction operator+(fraction x, double y) {
    fraction res;
    int exp;
    exp = fraction::count_after_comma(y);
    fraction x1 = fraction::convert(y, exp);
    fraction::made_incor(x); 
    fraction::made_incor(x1);
    if (x.getZn() == x1.getZn()) {
        res.setch(x.getCh() + x1.getCh());
        res.setzn(x.getZn());
    } else {
        res.setzn(x.getZn() * x1.getZn());
        res.setch(x.getCh() * x1.getZn() + x1.getCh() * x.getZn());
    }
    fraction::made_cor(res);
    return res;
}

fraction operator+(double y, fraction x) {
    fraction res = x + y;
    return res;
}

fraction operator+(fraction x, int i) {
    fraction x1(i);
    fraction res = x + x1;
    return res;
}

fraction operator+(int i, fraction x) {
    fraction x1(i);
    fraction res = x + x1;
    return res;
}

double operator+=(double& y, fraction x) {
    double a, b;
    a = x.getTotal();
    double b1 = static_cast<double>(x.getCh()), b2 = static_cast<double>(x.getZn());
    b = b1 / b2;
    double y1 = a + b;
    y += y1;
    return 0;
}