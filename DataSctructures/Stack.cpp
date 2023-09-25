#include "Stack.h"


bool Stack::push(char x){
	if (is_full()) {
		std::cout << "STACK OVERFLOW . . ." << std::endl;

		return false;
	}
	else {
		++m_top;
		m_items[m_top] = x;

		return true;
	}
}
char Stack::pop(){

	if (is_empty())
	{
		std::cout << "STACK IS EMPTY . . ." << std::endl;

		return 0;
	}
	else {
		int x = m_items[m_top];
		--m_top;
		return x;
	}
}
char Stack::peek(){
	if (is_empty()) {
		std::cout << "STACK IS EMPTY . . ." << std::endl;

		return 0;
	}
	else {
		int x = m_items[m_top];
		return x;
	}
}

bool Stack::is_full() { return m_top >= MAX - 1; }
bool Stack::is_empty() { return m_top < 0; }