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

    LinkedList(const LinkedList<T>& _list) {
        head = nullptr;
        tail = nullptr;
        Node<T>* cur = _list.head;
        do {
            Node<T>* node = new Node(cur->value);
            push_tail(node);
            cur = cur->next;
        } while (cur != _list.head);
    }
    LinkedList(int size, T from_data, T to_data) {
        if (size < 0)
            throw std::invalid_argument("LinkedList::Incorrect size.");
        else {
            head = nullptr;
            tail = nullptr;
            for (int i = 0; i < size; i++) {
                T _data = T(0);
                do {
                    _data = random_value(from_data, to_data);
                } while (_data == T(0));
                T _degree = random_value(from_degree, to_degree);
                Node<T>* node = new Node(_data, _degree);
                push_tail(node);
            }
        }
    }

    ~LinkedList() {
        while (head != tail) {
            Node<T>* cur = head;
            head = head->prev;
            delete cur;
        }
        delete tail;
    }

    void swap(LinkedList<T>& _list) {
        std::swap(head, _list.head);
    }

    void push_tail(Node<T>* t) {
        if (tail != NULL) {
            tail->next = t;
            head->prev = t;
        }
        else if (tail == NULL) {
            head = t;
        }
        t->next = head;
        t->prev = tail;
        tail = t;
    }
    void push_tail(const LinkedList& _list) {
        if (_list.tail == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else if (tail == NULL) {
            head = _list.head;
            tail = _list.tail;
        }
        else {
            _list.tail->next = head;
            head->prev = _list.tail;
            _list.head->prev = tail;
            tail->next = _list.head;
            tail = _list.tail;
        }
    }

    void push_head(Node<T>* h) {
        if (head != NULL) {
            tail->next = h;
            head->prev = h;
        }
        else if (head == NULL) {
            tail = h;
        }
        h->next = head;
        h->prev = tail;
        head = h;
    }

    void push_head(const LinkedList<T>& _list) {
        if (_list.head == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else if (head == NULL) {
            head = _list.head;
            tail = _list.tail;
        }
        else {
            _list.tail->next = head;
            head->prev = _list.tail;
            _list.head->prev = tail;
            tail->next = _list.head;
            head = _list.head;
        }
    }
    void pop_head() {
        if (head == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Node<T>* cur = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete cur;
        }
    }

    void pop_tail() {
        if (tail == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Node<T>* cur = tail;
            tail = tail->prev;
            head->prev = tail;
            tail->next = head;
            delete cur;
        }
    }

    void delete_node(T _data, const int _degree) {
        if (head == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Node<T>* cur = head;
            do {
                if (_data == cur->data && _degree == cur->degree) {
                    if (cur == head) {
                        cur = cur->next;
                        this->pop_head();
                    }
                    else if (cur == tail) {
                        cur = cur->next;
                        this->pop_tail();
                    }
                    else {
                        Node<T>* ptr = cur;
                        cur = cur->next;
                        cur->prev = ptr->prev;
                        ptr->prev->next = cur;
                        delete ptr;
                    }
                }
                else {
                    cur = cur->next;
                }
            } while (cur != head);
        }
    }
    Node<T>* operator[](int _index) const {
        if (_index < 0 || _index >= count_elem(head))
            throw std::out_of_range("LinkedList::Incorrect index.");
        else {
            Node<T>* cur = head;
            for (int i = 0; i < _index; i++)
                cur = cur->next;
            return cur;
        }
    }

    Node<T>* set_node(const T _data, const T _degree, int _index) {
        if (_index < 0 || _index >= count_elem(head))
            throw std::out_of_range("LinkedList::Incorrect index.");
        else {
            Node<T>* cur = head;
            for (int i = 0; i < _index; i++)
                cur = cur->next;
            cur->data = _data;
            cur->degree = _degree;
            return cur;
        }
    }

 };

template<typename T>
ostream& operator<<(ostream& os, LinkedList<T>& _list) {
     Node<T>* cur = _list.get_head();
     do {
         os << cur->data << endl;
         cur = cur->next;
     } while (cur != _list.get_head());
     return os;
 }
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
            t.push_head(r + l + of - 10);
            of = 1;
        }
        else {
            t.push_head(r + l + of);
            of = 0;
        }
        rt = rt->get_prev();
        lt = lt->get_prev();
    }
    while (rt != nullptr) {
        int r = *(rt->get_val());
        if (r + of > 9) {
            t.push_head(r + of - 10);
            of = 1;
        }
        else {
            t.push_head(r + of);
            of = 0;
        }
        rt = rt->get_prev();
    }
    while (lt != nullptr) {
        int l = *(lt->get_val());
        if (l + of > 9) {
            t.push_head(l + of - 10);
            of = 1;
        }
        else {
            t.push_head(l + of);
            of = 0;
        }
        lt = lt->get_prev();
    }
    if (of == 1) {
        t.push_head(1);
    }
    return t;
}

template <typename T>
void mul_num(LinkedList<T>* lhs, LinkedList<T>* rhs) {
    LinkedList<int> res;
    res.push_head(0);
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
            t.push_ead(of);
        }
        for (int i = 0; i < count; i++) {
            t.push tail(0);
        }
        res = sum_num(&res, &t);
        count++;
        rt = rt->get_prev();
    }
    return res;
}
