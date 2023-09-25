#pragma once
#include <iostream>
#include "Node.h"

class StackList
{
private:
    Node* m_root;
public:
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void print();
};

