#include <iostream>
using namespace std;

struct Student {
    string lastName;
    string firstName;
    int course;
    float averageGrade;
    Student* next;
    Student* prev;
    Student() : lastName(), firstName(), course(0), averageGrade(0), next(nullptr), prev(nullptr) {}
    Student(string last_Name, string first_Name, int _course, float average_Grade) :
        lastName(last_Name), firstName(first_Name), course(_course), averageGrade(average_Grade), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Student* head;
    Student* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}


    void addStudent(Student* student) {
        /*Student* newStudent = new Student;
        newStudent->lastName = lastName;
        newStudent->firstName = firstName;
        newStudent->course = course;
        newStudent->averageGrade = averageGrade;*/

        if (head == nullptr) {
            head = student;
            tail = student;
            student->next = head;
            student->prev = tail;
        }
        else {
            tail->next = student;
            student->prev = tail;
            student->next = head;
            head->prev = student;
            tail = student;
        }
    }

    /*~LinkedList() {
        while (head != tail) {
            Student* cur = head;
            head = head->prev;
            delete cur;
        }
        delete tail;
    }*/

    void deleteLowGrades() {
        if (head == nullptr) {
            return;
        }

        Student* current = head;
        do {
            if (current->averageGrade < 3.0) {
                if (current == head) {
                    head = current->next;
                }
                if (current == tail) {
                    tail = current->prev;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            current = current->next;
        } while (current != head);
    }

    void displayStudents() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Student* current = head;
        do {
            cout << "Last name: " << current->lastName << ", First name: " << current->firstName << ", Course: " << current->course << ", Average grade: " << current->averageGrade << endl;
            current = current->next;
        } while (current != head);
    }
};

/*int main() {
    LinkedList list;

    list.addStudent("Smith", "John", 3, 4.5);
    list.addStudent("Johnson", "Anna", 4, 2.8);
    list.addStudent("Williams", "David", 2, 3.2);
    list.addStudent("Brown", "Emily", 1, 2.9);

    cout << "Students before deletion: " << endl;
    list.displayStudents();

    list.deleteLowGrades();

    cout << endl << "Students after deletion: " << endl;
    list.displayStudents();

    return 0;
}*/