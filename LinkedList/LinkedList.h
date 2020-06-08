#include "Node.h"

#pragma once

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	int operator[] (const int value) const;
	int Count() const;
	void Add(int data);
	void RemoveDuplicates();
	int SearchFromEnd(int k) const;

private:
	Node* head = nullptr;
	int count = 0;
};

