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
    Node* _head;
    Node* _tail;
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
    void Swap(LinkedList<T>& other)
    {
        std::swap(this->_head, other._head);
        std::swap(this->_size, other._size);
    }
    LinkedList<T>& operator=(LinkedList<T> const& other);
    ~LinkedList();
    void PushTail(Node<T> const& node);
    void PushTail(LinkedList<T> const& other);
    void PushHead(Node<T> const& node);
    void PushHead(LinkedList<T> const& other);
    void PopHead();
    void PopTail();
    void DeleteNode(T const& value);
    Node<T>& operator[](int index);
    Node<T> operator[](int index) const;
}