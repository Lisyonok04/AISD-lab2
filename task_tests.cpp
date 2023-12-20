#include "task.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

TEST(Tests, list1) {
    LinkedList<int>num1;
    Node<int>* a = new Node(1);
    Node<int>* b = new Node(9);
    Node<int>* c = new Node(7);
    num1.push_tail(a);
    num1.push_tail(b);
    num1.push_tail(c);
    cout << num1 << endl;
    Node<int>* d = new Node(8);
    Node<int>* e = new Node(0);
    Node<int>* f = new Node(3);
    LinkedList<int>num2;
    num2.push_tail(d);
    num2.push_tail(e);
    num2.push_tail(f);
    cout << num2 << endl;
    LinkedList<int>res = sum_num(num1, num2);
    cout << res << endl;
}
