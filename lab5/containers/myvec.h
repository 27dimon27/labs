#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>
#include <cstring>

const int MAX_SIZE = 5;

template<class INF>
class MyVector {

protected:

    int max_size;
    int size;
    INF *pdata;
    void resize(bool f) {
        if (f == 1) {
            max_size *= 2;
            INF* temp = new INF[max_size];
            for (int i = 0; i < size; ++i) { temp[i] = pdata[i]; }
            delete[] pdata;
            pdata = temp;
        } else {
            max_size /= 2;
            INF* temp = new INF[max_size];
            for (int i = 0; i < size; ++i) { temp[i] = pdata[i]; }
            delete[] pdata;
            pdata = temp;
        }
    }

public:

    MyVector() {
        pdata = new INF[1];
        size = 0;
        max_size = 1;
    }
    template<typename T>
    MyVector(T el) {
        pdata = new T[1];
        pdata[0] = el;
        size = 1;
        max_size = 2;
    }
    MyVector(char* el) { //    проверить конструктор
        pdata = new char*[1];
        pdata[0] = new char[100];
        strcpy(pdata[0], el);
        size = 1;
        max_size = 2;
    }
    template<typename T>
    MyVector(const MyVector<T> &v) {
        size = v.size;
        max_size = v.max_size;
        pdata = new T[size];
        for (int i = 0; i < size; ++i) { pdata[i] = v.pdata[i]; }
    }
    MyVector(const MyVector<char*> &v) {
        size = v.size;
        max_size = v.max_size;
        pdata = new char*[size];
        for (int i = 0; i < size; ++i) { pdata[i] = new char[100]; strcpy(pdata[i], v.pdata[i]); }
    }
    ~MyVector() { DeleteData(pdata, size); }

    template<typename T>
    void DeleteData(T* data, int size) {
        delete[] data;
    }
    void DeleteData(char** data, int size) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void add_element(INF el) {
        if (size >= max_size) {
            resize(1);
        }
        pdata[size] = el;
        ++size;
        sort(pdata[0]);
    }
    void delete_element(int i) {
        if (size - 1 < 0) { return; }
        for (int j = i; j < size - 1; ++j) {
            std::swap(pdata[j], pdata[j + 1]);
        }
        --size;
        if (size < max_size / 4) {
            resize(0);
        }
    }
    template<typename T>
    void sort(T x) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if ((pdata[j] > pdata[j + 1])) {
                    std::swap(pdata[j], pdata[j + 1]);
                }
            }
        }
    }
    void sort(char* x) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if (strcmp(pdata[j], pdata[j + 1]) > 0) {
                    std::swap(pdata[j], pdata[j + 1]);
                }
            }
        }
    }
    int find(INF el) {
        for (int i = 0; i < size; ++i) {
            if (pdata[i] == el) {
                return i;
            }
        }
        return -1;
    }

    int get_size() const { return size; }
    int get_max_size() const { return max_size; }

    INF &operator[](int i) {
        return pdata[i];
    }

    template<typename T>
    MyVector& operator=(const MyVector<T>& v) {
        size = v.size;
        max_size = v.max_size;
        pdata = new T[size];
        for (int i = 0; i < size; ++i) { pdata[i] = v.pdata[i]; }
        return *this;
    }
    MyVector& operator=(const MyVector<char*>& v) {
        DeleteData(pdata, size);
        size = v.size;
        max_size = v.max_size;
        pdata = new char*[size];
        for (int i = 0; i < size; ++i) { pdata[i] = new char[strlen(v.pdata[i])+1]; strcpy(pdata[i], v.pdata[i]); }
        return *this;
    }
    template<typename T>
    bool operator==(MyVector<T> &v) {
        for (int i = 0; i < size; ++i) {
            if (pdata[i] != v.pdata[i]) { return false; }
        }
        return true;
    }
    bool operator==(MyVector<char*> &v) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(pdata[i], v.pdata[i]) != 0) { return false; }
        }
        return true;
    }
    friend std::ostream &operator<<(std::ostream &out, MyVector &v) {
        for (int i = 0; i < v.get_size(); ++i) {
            out << v[i] << ' ';
        }
        out << '\n';
        return out;
    }

};

#endif