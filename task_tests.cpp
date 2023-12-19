#include "task.cpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

using namespace std;

/*TEST(Tests, list1) {
	LinkedList<int> list;
	Node<int>* a = new Node(1);
	Node<int>* b = new Node(2);
	Node<int>* c = new Node(3);

	list.push_head(b);
	list.push_tail(c);
	list.push_head(a);
	cout << list << endl;
}*/

TEST(Tests, twolist1) {
	LinkedList<int> list1;
	LinkedList<int> list2;
	Node<int>* a = new Node(1);
	Node<int>* b = new Node(3);
	Node<int>* c = new Node(5);
	Node<int>* d = new Node(2);
	Node<int>* e = new Node(4);
	Node<int>* f = new Node(6);
	list1.push_head(a);
	list1.push_tail(b);
	list1.push_head(c);
	list2.push_head(d);
	list2.push_tail(e);
	list2.push_head(f);
	cout << list2 << endl;
}
