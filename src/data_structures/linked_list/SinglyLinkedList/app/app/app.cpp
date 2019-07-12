#include <iostream>
#include "SinglyLinkedList.h"

int main() {
	std::cout << "Singly Linked List" << std::endl;

	SinglyLinkedList<int> list;
	list.insertNode(10);
	list.insertNode(12);
	list.insertNode(3);
	list.insertNode(5);
	list.insertNode(13);

	list.print();

	list.printReverse();

	list.reverse();

	list.print();

	list.insertNode(50, 0);
	list.print();

	list.insertNode(4, 40);
	list.print();
}