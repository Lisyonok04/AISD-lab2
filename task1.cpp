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
    int size;
public:
    LinkedList() : size(0), head(nullptr), tail(nullptr) {}


    void addStudent(Student* student) {

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

    void swap(LinkedList& _list) {
        std::swap(head, _list.head);
        std::swap(size, _list.size);
    }

    void push_tail(Student* t) {
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

    void push_tail(const LinkedList* _list) {
        if (_list->tail == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else if (tail == NULL) {
            head = _list->head;
            tail = _list->tail;
        }
        else {
            _list->tail->next = head;
            head->prev = _list->tail;
            _list->head->prev = tail;
            tail->next = _list->head;
            tail = _list->tail;
        }
    }

    void push_head(Student* h) {
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

    void push_head(const LinkedList* _list) {
        if (_list->head == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else if (head == NULL) {
            head = _list->head;
            tail = _list->tail;
        }
        else {
            _list->tail->next = head;
            head->prev = _list->tail;
            _list->head->prev = tail;
            tail->next = _list->head;
            head = _list->head;
        }
    }
    void pop_head() {
        if (head == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Student* cur = head;
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
            Student* cur = tail;
            tail = tail->prev;
            head->prev = tail;
            tail->next = head;
            delete cur;
        }
        size--;
    }

    
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