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

    Node() : _value(0), next(nullptr), prev(nullptr) {}
    Node(T value) : _value(value), next(nullptr), prev(nullptr) {}
    Node<T>* get_prev() { return prev; }
    Node<T>* get_next() { return next; }
    T* get_val() { return _value; }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    Node<T>* get_head() { return head; }
    Node<T>* get_tail() { return tail; }
    int get_size() { return size; }

    LinkedList(const LinkedList<T>& _list) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node<T>* cur = _list.head;
        do {
            Node<T>* node = new Node(cur->_value);
            push_tail(node);
            cur = cur->next;
            size++;
        } while (cur != _list.head);
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
        std::swap(size, _list.size);
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

    void push_tail(const LinkedList<T>* _list) {
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
        size++;
    }

    void push_head(const LinkedList<T>* _list) {
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
        size--;
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
        size--;
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
        size--;
    }
    T operator[](int index) const
    {
        int count = 0;
        Node<T>* tmp = head;
        while (tmp != nullptr)
        {
            if (count == index)
            {
                return tmp->_value;
            }
            count++;
            tmp = tmp->next;
        }
        throw out_of_range("wrong index of list");
    }

    Node<T>* set_node(const T _data, int _index) {
        if (_index < 0 || _index >= count_elem(head))
            throw std::out_of_range("LinkedList::Incorrect index.");
        else {
            Node<T>* cur = head;
            for (int i = 0; i < _index; i++)
                cur = cur->next;
            cur->data = _data;
            return cur;
        }
    }

 };

template<typename T>
ostream& operator<<(ostream& os, LinkedList<T>& _list) {
     Node<T>* cur = _list.get_head();
     do {
         os << cur->_value << endl;
         cur = cur->next;
     } while (cur != _list.get_head());
     return os;
 }

template <typename T>
LinkedList<T> sum_num(LinkedList<T> a, LinkedList<T> b) {
    LinkedList<int> result;
    int carry = 0;
    int i = a.get_size() - 1;
    int j = b.get_size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = i >= 0 ? a[i] : 0;
        int digit2 = j >= 0 ? b[j] : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        Node<int>* x = new Node(sum % 10);
        result.push_head(x);
        if (i >= 0) --i;
        if (j >= 0) --j;


    }
    return result;
}
