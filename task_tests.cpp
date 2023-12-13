#include "task.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

TEST(TaskTests, pushingpopingcheck1) {
    LinkedList<int> a = LinkedList<int>(3, 5);
    PrintList(a);
    Node b = Node(2);
    a.PushTail(b);
    PrintList(a);
    a.PushHead(b);
    PrintList(a);
    a.PopHead();
    PrintList(a);
    a.PopTail();
    PrintList(a);
    LinkedList<int> c = LinkedList<int>(3);
    a.PushTail(c);
    PrintList(a);
}