#include "Node.h"

#pragma once

class LinkedList
{
public:
	LinkedList();
	int operator[] (const int value);
	int Count();
	void Add(int data);
	void RemoveDuplicates();
	int SearchFromEnd(int k);

private:
	Node* Head = nullptr;
	int count = 0;
};
