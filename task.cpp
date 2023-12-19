#pragma once
#include <iostream>
#include <random>
#include <complex>

using namespace std;

template<typename T>
struct Node {
    T _value;
    Node<T>* next;
    Node<T>* prev;

    Node() : value(0), next(nullptr), prev(nullptr) {}
    Node(T value) : _value(value), next(nullptr), prev(nullptr) {}
    Node<T>* get_prev() { return prev; }
    Node<T>* get_next() { return next; }
    T* get_val() { return value; }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    Node<T>* get_head() { return head; }
    Node<T>* get_tail() { return tail; }

template <class T>
void sum_num(LinkedList<T>* lhs, LinkedList<T>* rhs) {
    LinkedList<int> t;
    int of = 0;
    Node<int>* rt = rhs->get_tail();
    Node<int>* lt = lhs->get_tail();
    while (rt != nullptr && lt != nullptr) {
        int r = *(rt->get_val());
        int l = *(lt->get_val());
        if (r + l + of > 9) {
            t.PushHead(r + l + of - 10);
            of = 1;
        }
        else {
            t.PushHead(r + l + of);
            of = 0;
        }
        rt = rt->get_prev();
        lt = lt->get_prev();
    }
    while (rt != nullptr) {
        int r = *(rt->get_val());
        if (r + of > 9) {
            t.PushHead(r + of - 10);
            of = 1;
        }
        else {
            t.PushHead(r + of);
            of = 0;
        }
        rt = rt->get_prev();
    }
    while (lt != nullptr) {
        int l = *(lt->get_val());
        if (l + of > 9) {
            t.PushHead(l + of - 10);
            of = 1;
        }
        else {
            t.PushHead(l + of);
            of = 0;
        }
        lt = lt->get_prev();
    }
    if (of == 1) {
        t.PushHead(1);
    }
    return t;
}

template <typename T>
void mul_num(LinkedList<T>* lhs, LinkedList<T>* rhs) {
    LinkedList<int> res;
    res.PushHead(0);
    Node<int>* rt = rhs->get_tail();
    int count = 0;
    while (rt != nullptr) {
        int r = *(rt->get_val());
        LinkedList<int> t;

        int of = 0;
        Node<int>* lt = lhs->get_tail();
        while (lt != nullptr) {
            int l = *(lt->get_val());
            t.PushHead((l * r + of) % 10);
            of = (l * r + of) / 10;
            lt = lt->get_prev();
        }
        if (of != 0) {
            t.PushHead(of);
        }
        for (int i = 0; i < count; i++) {
            t.PushTail(0);
        }
        res = sum_num(&res, &t);
        count++;
        rt = rt->get_prev();
    }
    return res;
}
