#include "List.h"


void List::push_back(int data) {
	Node* node = new Node(data);

	if (m_head == nullptr) {
		m_head = node;

		return;
	}

	Node* last = m_head;
	while (last->m_next != nullptr) {
		last = last->m_next;
	}

	last->m_next = node;

	return;
}
void List::push_front(int data) {
	Node* node = new Node(data);
	if (m_head == nullptr) {
		m_head = node;

		return;
	}
	node->m_next = m_head;
	m_head = node;

}
void List::insert(int data, int position) {
	Node* node = new Node(data);

	if (m_head == nullptr) {
		m_head = node;

		return;
	}
	if (position == 0) {
		push_front(data);

		return;
	}

	int cur_pos = 0;

	Node* current_node = m_head;

	while (cur_pos < position - 1 && current_node->m_next != nullptr) {
		current_node = current_node->m_next;
		cur_pos++;
	}

	Node* next = current_node->m_next;
	current_node->m_next = node;
	node->m_next = next;
}

void List::delete_node(int data) {
	Node* temp = m_head;
	Node* prev = nullptr;

	if (temp && temp->m_data == data) {
		m_head = m_head->m_next;
		delete temp;
		return;
	}

	while (temp && temp->m_data != data) {
		prev = temp;
		temp = temp->m_next;
	}

	if (!temp) {
		return;
	}

	prev->m_next = temp->m_next;
	delete temp;
}
void List::delete_node_pos(int position) {
	Node* temp = m_head;
	Node* prev = nullptr;

	if (temp && temp->m_next && (position == 0 || position == 1)) {
		m_head = m_head->m_next;
		delete temp;
		return;
	}
	if (temp == nullptr) {
		return;
	}

	int current_pos = 0;

	while (temp->m_next != nullptr && current_pos != position) {
		prev = temp;
		temp = temp->m_next;

		current_pos++;
	}
	if (current_pos == position) {
		prev->m_next = temp->m_next;
		delete temp;

		return;
	}
	else {
		return;
	}
}
void List::clear() {
	if (m_head == nullptr) {
		return;
	}
	
	Node* temp = m_head;

	while (temp) {
		m_head = temp->m_next;
		delete temp;
		temp = m_head;
	}
	m_head = nullptr;
}

void List::show() {
	Node* temp = m_head;

	while (temp) {
		std::cout << temp->m_data;
		temp = temp->m_next;
	}
}

bool List::find(int data) {
	if (m_head == nullptr) {
		return false;
	}
	
	Node* node = m_head;

	while (node) {
		if (node->m_data == data) {
			return true;
		}
		node = node->m_next;
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
	Node* node = list.m_head;

	while (node != nullptr) {
		os << node->m_data << ' ';

		node = node->m_next;
	}

	delete node;

	return os;
}
