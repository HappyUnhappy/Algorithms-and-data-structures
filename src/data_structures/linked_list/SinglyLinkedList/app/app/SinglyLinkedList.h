#pragma once

template <typename T>
struct Node {
	int m_data;
	Node *next;
};

template <typename T>
class SinglyLinkedList {

	Node<T> *m_head;
	void printReverse(Node<T> *node);

public:
	SinglyLinkedList();
	~SinglyLinkedList();

	void insertNode(T value);
	void insertNode(T value, int position);

	void deleteNode(T value);
	
	void print();
	void printReverse();
	
	void reverse();

	bool compare(Node<T> *head);
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : m_head(nullptr) { }

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { 
	if (m_head) {
		Node<T> *current = m_head->next;
		Node<T> *prev = m_head;

		std::cout << "Delete singly linked list ";

		do {
			std::cout << prev->m_data << " ";
			delete prev;
			prev = current;
			current = current->next;

		} while (current);

		std::cout << prev->m_data << " ";
		delete prev;
	}
}

template<typename T>
void SinglyLinkedList<T>::insertNode(T value) {
	Node<T> *node = new Node<T>;
	node->m_data = value;
	node->next = nullptr;

	if (!m_head) {
		m_head = node;
		return;
	}

	Node<T> *current = m_head;
	while (current->next)
		current = current->next;

	current->next = node;
}

template<typename T>
void SinglyLinkedList<T>::insertNode(T value, int position) {

	Node<T> *node = new Node<T>;
	node->m_data = value;
	node->next = nullptr;

	if (position == 0) {
		node->next = m_head;
		m_head = node;
		return;
	}

	Node<T> *current = m_head;

	for (int i = 0; i < position - 1; ++i) {
		if (!current)
			return;
		current = current->next;
	}

	node->next = current->next;
	current->next = node;
}

template<typename T>
void SinglyLinkedList<T>::deleteNode(T value)
{
}

template<typename T>
void SinglyLinkedList<T>::print() {
	if (m_head) {
		Node<T> *current = m_head->next;
		Node<T> *prev = m_head;

		std::cout << "Print singly linked list ";

		do {
			std::cout << prev->m_data << " ";
			prev = current;
			current = current->next;

		} while (current);

		std::cout << prev->m_data << std::endl;
	}
}

template<typename T>
void SinglyLinkedList<T>::printReverse() {
	std::cout << "Print reverse ";
	printReverse(m_head);
	std::cout << std::endl;
}

template<typename T>
void SinglyLinkedList<T>::reverse() {
	if (!m_head)
		return;

	std::cout << "Reverse" << std::endl;

	Node<T> *current = m_head;
	Node<T> *prev = nullptr;
	Node<T> *next = current->next;

	while (next) {
		current->next = prev;
		prev = current;
		current = next;
		next = current->next;
	}

	current->next = prev;
	m_head = current;
}

template<typename T>
bool SinglyLinkedList<T>::compare(Node<T>* head) {



	return false;
}

template<typename T>
void SinglyLinkedList<T>::printReverse(Node<T> *node) {
	if (!node)
		return;

	printReverse(node->next);
	std::cout << node->m_data << " ";
}
