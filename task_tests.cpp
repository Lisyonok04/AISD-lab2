#include "task1.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

TEST(Tests, check1) {
    LinkedList list;
    Student student1("Smith", "John", 3, 4.5);
    list.push_head(&student1);
    Student student2("Johnson", "Anna", 4, 2.8);
    list.push_head(&student2);
    Student student3("Williams", "David", 2, 3.2);
    list.push_tail(&student3);
    Student student4("Brown", "Emily", 1, 2.9);
    list.push_tail(&student4);
    list.displayStudents();
}

TEST(Tests, check2) {
    LinkedList list;
    Student student1("Smith", "John", 3, 4.5);
    list.push_head(&student1);
    Student student2("Johnson", "Anna", 4, 2.8);
    list.push_head(&student2);
    Student student3("Williams", "David", 2, 3.2);
    list.push_tail(&student3);
    Student student4("Brown", "Emily", 1, 2.9);
    list.push_tail(&student4);
    list.pop_tail();
    list.pop_head();
    list.displayStudents();
}

TEST(Tests, check3) {
    LinkedList list;
    Student student1("Smith", "John", 3, 4.5);
    list.push_head(&student1);
    Student student2("Johnson", "Anna", 4, 2.8);
    list.push_head(&student2);
    Student student3("Williams", "David", 2, 3.2);
    list.push_tail(&student3);
    Student student4("Brown", "Emily", 1, 2.9);
    list.push_tail(&student4);
    list.delete_node("Brown", "Emily", 1, 2.9);
    list.displayStudents();
}


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
    deleteLowGrades(list);
    cout << endl << "Students after deletion: " << endl;
}
TEST(Tests, list2) {
    LinkedList list;
    Student student1("Stevenson", "Jane", 2, 5);
    list.push_tail(&student1);
    Student student2("Hopeless", "Karl", 4, 1.3);
    list.push_tail(&student2);
    Student student3("Gordon", "Cloe", 1, 3.9);
    list.push_tail(&student3);
    Student student4("Toy", "Emma", 5, 4.5);
    list.push_tail(&student4);
    Student student5("Dorh", "Zarina", 1, 2.9);
    list.push_tail(&student5);
    cout << "Students before deletion: " << endl;
    list.displayStudents();
    deleteLowGrades(list);
    cout << endl << "Students after deletion: " << endl;
    list.displayStudents();
}

TEST(Tests, list3) {
    LinkedList list;
    Student student1("Petrova", "Ksenya", 1, 4.5);
    list.push_tail(&student1);
    Student student2("Bespalov", "Kirill", 5, 3);
    list.push_tail(&student2);
    Student student3("Gluhov", "Svyatopolk", 3, 2.9);
    list.push_tail(&student3);
    Student student4("Zayzeva", "Igor", 4, 1.5);
    list.push_tail(&student4);
    Student student5("Ishtarova", "Gulphia", 5, 3.5);
    list.push_tail(&student5);
    cout << "Students before deletion: " << endl;
    list.displayStudents();
    LinkedList list2;
    list2.push_tail(&list);
    Student student6("Ishtarov", "Zurbagan", 5, 4.5);
    list2.push_tail(&student6);
    deleteLowGrades(list2);
    cout << endl << "Students after deletion: " << endl;
    list2.displayStudents();
}