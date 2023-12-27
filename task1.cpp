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
    Student(Student& other) : 
        lastName(other.lastName), firstName(other.firstName), course(other.course), averageGrade(other.averageGrade), next(nullptr), prev(nullptr) {}
public:
    void set_prev(Student* student) {
        prev = student;
    }
    void set_next(Student* student) {
        next = student;
    }
    float get_averageGrade() {
        return averageGrade;
    }
    string get_lastName() {
        return lastName;
    }
    string get_firstName() {
        return firstName;
    }
    Student* get_prev() {
        return prev;
    }
    Student* get_next() {
        return next;
    }
    int get_course() {
        return course;
    }
    friend std::ostream& operator<<(std::ostream& stream, const Student& current) {
        cout << "Last name: " << current.lastName << ", First name: " << current.firstName << ", Course: " << current.course << ", Average grade: " << current.averageGrade << endl;
        return stream;
    }
};


class LinkedList {
private:
    Student* head;
    Student* tail;
    int size;
public:
    int get_size() {
        return size;
    }

    Student* get_head() {
        return head;
    }

    Student* get_tail() {
        return tail;
    }

    LinkedList() : size(0), head(nullptr), tail(nullptr) {}
    LinkedList(const LinkedList& _list) {
        head = nullptr;
        tail = nullptr;
        Student* cur = _list.head;
        do {
            Student* node = new Student(cur->lastName, cur->firstName, cur->course, cur->averageGrade);
            push_tail(node);
            cur = cur->next;
        } while (cur != _list.head);
    }

    ~LinkedList() = default;

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
            tail = cur;
            tail->next = cur;
            head->prev = cur;
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
            head = cur;
            tail = cur;
            tail->next = cur;
            head->prev = cur;
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

    void delete_node(string last_Name, string first_Name, int _course, float average_Grade) {
        if (head == NULL)
            throw std::invalid_argument("LinkedList::The list is empty");
        else {
            Student* cur = head;
            do {
                if (last_Name == cur->lastName && first_Name == cur->firstName && _course == cur->course && average_Grade == cur->averageGrade) {
                    if (cur == head) {
                        cur = cur->next;
                        this->pop_head();
                    }
                    else if (cur == tail) {
                        cur = cur->next;
                        this->pop_tail();
                    }
                    else {
                        Student* ptr = cur;
                        cur = cur->next;
                        cur->prev = ptr->prev;
                        ptr->prev->next = cur;
                        delete ptr;
                    }
                }
                else {
                    cur = cur->next;
                }
            } while (cur != head);
        }
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
void deleteLowGrades(LinkedList& student) {
    if (student.get_head() == nullptr) {
        return;
    }
    int cur_size = student.get_size();
    int size = student.get_size();
    Student* current = student.get_head();
    Student* head = student.get_head();
    do {
        if ((*current).get_averageGrade() < 3.0) {
            Student* del = current;
            current->get_prev()->set_next(current->get_next());
            current->get_next()->set_prev(current->get_prev());
            if (del == head) {
                head = del->get_next();
            }
            current = current->get_next();
            delete del;
            size--;
        }
        else {
            current = current->get_next();
        }
        cur_size--;
    } while (cur_size != 0);
}