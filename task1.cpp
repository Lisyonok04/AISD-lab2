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
    Student(Student& other) : lastName(other.lastName), firstName(other.firstName), course(other.course), averageGrade(other.averageGrade), next(nullptr), prev(nullptr) {}
};

ostream& operator<<(ostream& stream, Student& current) {
    cout << "Last name: " << current.lastName << ", First name: " << current.firstName << ", Course: " << current.course << ", Average grade: " << current.averageGrade << endl;
    return stream;
}

class LinkedList {
private:
    Student* head;
    Student* tail;
    int size;
public:
    int get_size() {
        return size;
    }

    LinkedList() : size(0), head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != tail) {
            Student* cur = head;
            head = head->prev;
            delete cur;
        }
        delete tail;
    }

    void swap(LinkedList& _list) {
        std::swap(head, _list.head);
        std::swap(tail, _list.tail);
        std::swap(size, _list.size);
    }

    void push_tail(Student* t) {
        Student* cur = new Student(*t);
        if (tail != NULL) {
            tail->next = cur;
            head->prev = cur;
        }
        else if (tail == NULL) {
            head = cur;
        }
        cur->next = head;
        cur->prev = tail;
        tail = cur;
        size++;
    }

    void push_tail(LinkedList* _list) {
        if (_list->tail == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Student* cur = _list->head;
            do {
                push_tail(cur);
                cur = cur->next;
            } while (cur != _list->head);
        }
    }

    void push_head(Student* h) {
        Student* cur = new Student(*h);
        if (head != NULL) {
            tail->next = cur;
            head->prev = cur;
        }
        else if (head == NULL) {
            tail = cur;
        }
        cur->next = head;
        cur->prev = tail;
        head = cur;
        size++;
    }

    void push_head(LinkedList* _list) {
        if (_list->tail == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Student* cur = _list->head;
            do {
                push_head(cur);
                cur = cur->next;
            } while (cur != _list->head);
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
        int cur_size = size;
        Student* current = head;
        do {
            if (current->averageGrade < 3.0) {
                Student* del = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (del == head) {
                    head = del->next;
                }
                current = current->next;
                delete del;
                size--;
            }
            else {
                current = current->next;
            }
            cur_size--;
        } while (cur_size != 0);
    }

    void displayStudents() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Student* current = head;
        do {
            cout << *current;
            current = current->next;
        } while (current != head);
    }
};