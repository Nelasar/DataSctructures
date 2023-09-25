#pragma once
#include "Node.h"
#include <iostream>

class List
{
public:
	List() : m_head(nullptr) {}
	~List() { clear(); }
	void push_back(int data);
	void push_front(int data);
	void insert(int data, int position);
	void delete_node(int data);
	void delete_node_pos(int position);
	void clear();
	void show();

	bool find(int data);

	friend std::ostream& operator<<(std::ostream& os, const List& list);
private:
	Node* m_head;
};

