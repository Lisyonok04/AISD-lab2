#pragma once
#include <iostream>
#include <random>
#include <complex>

using namespace std;

template <typename T>
class Node {
private:
    Node* _next;
    Node* _prev;
    T* _val;
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
    Node* get_prev() const
    {
        return this->_prev;
    }
    Node* get_next() const
    {
        return this->_next;
    }
    void set_prev(Node* prev)
    {
        this->_prev = prev;
    }
    void set_next(Node* next)
    {
        this->_next = next;
    }
    void set_val(Node* val)
    {
        this->_val = val;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head_;
    int size_;
public:

}