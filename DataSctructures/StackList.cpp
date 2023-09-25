#include "StackList.h"

bool StackList::push(int x) {
	Node* node = new Node(x);

	if (m_root == nullptr) {
		m_root = node;

		return true;
	}

	node->m_next = m_root;
	m_root = node;

	return true;
}
int StackList::pop() {
	if (isEmpty()) {
		return 0;
	}
	Node* node = m_root;
	int x = m_root->m_data;

	m_root = m_root->m_next;
	delete node;

	return x;
}
int StackList::peek() {
	if (isEmpty())
		return 0;

	return m_root->m_data;
}
bool StackList::isEmpty() {
	if (m_root == nullptr) {
		return true;
	}
	else return false;
}

void StackList::print() {
	Node* temp = m_root;

	while (temp) {
		std::cout << temp->m_data << " ";
		temp = temp->m_next;
	}
	return;
}