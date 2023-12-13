#pragma once
#include <iostream>
#include <random>
#include <complex>

using namespace std;

template <typename T>
class Node {
private:
    Node<T>* _next;
    Node<T>* _prev;
    T _val;
public:
    Node()
    {
        _next = nullptr;
        _prev = nullptr;
        _val = nullptr;
    }
    Node(Node<T>* prev, Node* next, T const& value)
    {
        this->_prev = prev;
        this->_next = next;
        this->_val = value;
    }
    Node(Node<T>* prev, Node* next)
    {
        this->_prev = prev;
        this->_next = next;
        this->_val = nullptr;
    }
    Node(T const& value)
    {
        this->_prev = nullptr;
        this->_next = nullptr;
        this->_val = value;
    }

    Node(Node<T> const& other)
    {
        this->_prev = other._prev;
        this->_next = other._next;
        this->_val = other._val;
    }
    ~Node() = default;
    T get_val() const
    {
        return this->_val;
    }
    Node<T>* get_prev() const
    {
        return this->_prev;
    }
    Node<T>* get_next() const
    {
        return this->_next;
    }
    void set_prev(Node<T>* prev)
    {
        this->_prev = prev;
    }
    void set_next(Node<T>* next)
    {
        this->_next = next;
    }
    void set_val(Node<T> val)
    {
        this->_val = val;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;
public:
    LinkedList() 
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_size = 0;
    }
    LinkedList(int size)
    {
        if (size <= 0) {
            throw std::runtime_error("Wrong size parameter");
        }
        this->_size = size;
        this->_head = new Node<T>;
        Node<T>* ptr = this->_head;
        for (int i = 0; i < this->_size - 1; ++i) {
            ptr->_val = 0;
            ptr->_next = new Node<T>;
            ptr->_next->_prev = ptr;
            ptr = ptr->_next;
        }
        ptr->_val = 0;
        ptr->_next = this->_head;
        this->_head->_prev = ptr;
    }
    LinkedList(LinkedList<T> const& other)
    {
        this->_size = other._size;
        Node<T>* other_ptr = other._head;
        this->_head = new Node<T>(other_ptr->_val);
        Node<T>* ptr = this->_head;
        while (other._head->_prev != other_ptr) {
            ptr->_next = new Node<T>(other_ptr->_next->_val);
            ptr->_next->_prev = ptr;
            other_ptr = other_ptr->_next;
            ptr = ptr->_next;
        }
        ptr->_next = this->_head;
        this->_head->_prev = ptr;
    }
    LinkedList(int size, T const& value)
    {
        if (size <= 0) {
            throw std::runtime_error("Wrong size parameter");
        }
        this->_size = size;
        this->_head = new Node<T>(value);
        Node<T>* ptr = this->_head;
        for (int i = 0; i < this->_size - 1; ++i) {
            ptr->_next = new Node<T>(value);
            ptr->_next->_prev = ptr;
            ptr = ptr->_next;
        }
        ptr->_next = this->_head;
        this->_head->_prev = ptr;
    }
    int GetSize() const
    {
        return this->_size;
    }
    Node<T>* GetHead() const
    {
        return this->_head;
    }
    void SetHead(Node<T>* other)
    {
        this->_head = other;
    }
    Node<T>* GetTail() const
    {
        return this->_tail;
    }
    void SetTail(Node<T>* other)
    {
        this->_tail = other;
    }
    void Swap(LinkedList<T>& other)
    {
        std::swap(this->_head, other._head);
        std::swap(this->_size, other._size);
    }
    ~LinkedList() 
    {
        if (this->_head != nullptr) {
            Node<T>* ptr = this->_head;
            for (int i = 1; i < this->_size; ++i) {
                ptr = ptr->_next;
                delete ptr->_prev;
            }
            delete ptr;
        }
    }
    void PushTail(Node<T> const& Node)
    {
        if (_tail != NULL) {
            _tail->_next = Node;
            _head->_prev = Node;
        }
        else if (_tail == NULL) {
            _head = Node;
        }
        Node->_next = _head;
        Node->_prev = _tail;
        _tail = Node;
    }
    void PushTail(LinkedList<T> const& other)
    {
        if (other._tail == NULL)
            throw std::invalid_argument("The list is empty");
        else if (_tail == NULL) {
            _head = other._head;
            _tail = other._tail;
        }
        else {
            other._tail->_next = _head;
            _head->_prev = other._tail;
            other._head->_prev = _tail;
            _tail->_next = other._head;
            _tail = other._tail;
        }
    }
    void PushHead(Node<T> const& Node)
    {
        if (_head != NULL) {
            _tail->_next = Node;
            _head->_prev = Node;
        }
        else if (_head == NULL) {
            _tail = Node;
        }
        Node->_next = _head;
        Node->_prev = _tail;
        _head = Node;
    }
    void PushHead(LinkedList<T> const& other)
    {
        if (other._head == NULL)
            throw std::invalid_argument("The list is empty");
        else if (_head == NULL) {
            _head = other._head;
            _tail = other._tail;
        }
        else {
            other._tail->_next = _head;
            _head->_prev = other._tail;
            other._head->_prev = _tail;
            _tail->_next = other._head;
            _head = other._head;
        }
    }
    void PopHead()
    {
        if (_head == NULL)
            throw std::invalid_argument("The list is empty");
        else {
            Node<T>* help = _head;
            _head = _head->_next;
            _head->_prev = _tail;
            _tail->_next = _head;
            delete help;
        }
    }
    void PopTail()
    {
        if (_tail == NULL)
            throw std::invalid_argument("The list is empty");
        else {
            Node<T>* help = _tail;
            this->_tail = _tail->_prev;
            this->_head->_prev = this->_tail;
            this->_tail->_next = this->_head;
            delete help;
        }
    }
    void DeleteNode(T const& value) 
    {
        Node<T>* ptr = this->_head;
        for (int i = 0; i < _size; ++i) {
            if (ptr->_val == value) {
                ptr->_prev->_next = ptr->_next;
                ptr->_next->_prev = ptr->_prev;
                Node<T>* next = ptr->_next;
                delete ptr;
                this->_size--;
                ptr = next;
            }
            else
                ptr = ptr->_next;
        }
    }
    Node<T>& operator[](int index)
    {
        if (index >= this->_size || index < 0) {
            throw std::runtime_error("Invalid index");
        }
        Node<T>* ptr = this->_head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->_next;
        }
        return *ptr;
    }
    LinkedList<T>& operator=(LinkedList<T> const& other)
    {
        LinkedList<T> help(other);
        this->Swap(help);
        return *this;
    }
};

template<class T>
void PrintList(LinkedList<T> const& list) {
    for (int i = 0; i < list.GetSize(); ++i) {
        cout << list[i].get_val() << " ";
    }
    cout << endl;
}

template <class T>
void sum_num(LinkedList<T>* lhs, LinkedList<T>* rhs) {
    LinkedList<int> t;
    int of = 0;
    Node<int>* rt = rhs->GetTail();
    Node<int>* lt = lhs->GetTail();
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
    Node<int>* rt = rhs->GetTail();
    int count = 0;
    while (rt != nullptr) {
        int r = *(rt->get_val());
        LinkedList<int> t;

        int of = 0;
        Node<int>* lt = lhs->GetTail();
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
