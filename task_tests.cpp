#include "task1.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

TEST(Tests, list1) {
    LinkedList list;
    Student student1("Smith", "John", 3, 4.5);
    list.push_tail(&student1);
    Student student2("Johnson", "Anna", 4, 2.8);
    list.push_tail(&student2);
    Student student3("Williams", "David", 2, 3.2);
    list.push_tail(&student3);
    Student student4("Brown", "Emily", 1, 2.9);
    list.push_tail(&student4);
    cout << "Students before deletion: " << endl;
    list.displayStudents();
    list.deleteLowGrades();
    cout << endl << "Students after deletion: " << endl;
    list.displayStudents();
    /*LinkedList<int>num1;
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
    cout << res << endl;*/
}

TEST(Tests, list2) {
    /*LinkedList<int>num1;
    Node<int>* a = new Node(1);
    Node<int>* b = new Node(9);
    num1.push_tail(a);
    num1.push_tail(b);
    cout << num1 << endl;
    Node<int>* d = new Node(8);
    LinkedList<int>num2;
    num2.push_tail(d);
    num2.push_tail(d);
    cout << num2 << endl;
    LinkedList<int>res = multiply(num1, num2);
    //cout << res << endl;*/
}
