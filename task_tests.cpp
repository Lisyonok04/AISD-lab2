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
}

TEST(Tests, list2) {
    LinkedList list;
    Student student1("Smith", "John", 3, 4.5);
    list.push_tail(&student1);
    Student student2("Johnson", "Anna", 4, 3.7);
    list.push_tail(&student2);
    Student student3("Williams", "David", 2, 3.2);
    list.push_tail(&student3);
    Student student4("Brown", "Emily", 1, 5);
    list.push_tail(&student4);
    cout << "Students before deletion: " << endl;
    list.displayStudents();
    list.deleteLowGrades();
    cout << endl << "Students after deletion: " << endl;
    list.displayStudents();
}
