#pragma once
#define MAX 1000

#include <iostream>

class Stack
{
public:
	char m_items[MAX];
	Stack() : m_top(-1){}
	bool push(char x);
	char pop();
	char peek();
	bool is_full();
	bool is_empty();
private:
	int m_top;
};

