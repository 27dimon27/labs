#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <cstring>

template<class INF, class FRIEND>
class ListNode
{
private:
    INF d;
    ListNode *next;
    ListNode(void) { next = nullptr; }
    friend FRIEND;
};

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    
    MyStack(void) { top = nullptr; }
    MyStack(const MyStack &obj) {
        MyStack<INF> temp_s;
        Node *temp_n = obj.top;
        while (temp_n) {
            temp_s.push(temp_n->d);
            temp_n = temp_n->next;
        }
        top = nullptr;
        while (!temp_s.empty()) {
            push(temp_s.top_inf());
            temp_s.pop();
        }
    }
    ~MyStack() { while (!empty()) { pop(); } }

    MyStack &operator=(const MyStack &obj) {
        MyStack<INF> temp_s;
        Node *temp_n = obj.top;
        while (temp_n) {
            temp_s.push(temp_n->d);
            temp_n = temp_n->next;
        }
        top = nullptr;
        while (!temp_s.empty()) {
            push(temp_s.top_inf());
            temp_s.pop();
        }
        return *this;
    }

    bool empty(void) {
        if (top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push(INF n) {
        Node *temp = new Node;
        temp->d = n;
        temp->next = top;
        top = temp;
    }

    void pop(void) {
        if (!empty()) {
            Node *temp = new Node;
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    INF top_inf(void) {
        if (empty() == true) {
            return -1;
        }
        return top->d;
    }

    friend std::ostream& operator<<(std::ostream& out, MyStack<INF> &obj) {
        MyStack<INF> a = obj;
        MyStack<INF> b;
        while (!a.empty()) {
            b.push(a.top_inf());
            a.pop();
        }
        while (!b.empty()) {
            out << b.top_inf() << ' ';
            b.pop();
        }
        out << '\n';
        
        return out;
    }

};

#endif