#include "LinkedList.h"

LinkedList::LinkedList() {}

int LinkedList::Count() { return count; }

int LinkedList::operator[] (const int value) 
{
	Node* result = Head;
	for (auto i = 0; i < value; i++)
	{
		result = result->getNextNode();
	}
	return result->getData();
}

void LinkedList::Add(int data)
{
	if (Head == nullptr)
	{
		this->Head = new Node(data);
		this->Head->setNextNode(nullptr); // надо ли?
	}
	else
	{
		Node* current = Head;
		while (current->getNextNode() != nullptr)
			current = current->getNextNode();
		current->setNextNode(new Node(data));
	}
	count++;
}

void LinkedList::RemoveDuplicates()
{
	Node* temp = new Node();
	Node* base = new Node();
	Node* current = new Node();
	Node* previous = new Node();
	for (base = Head; base != nullptr; base = base->getNextNode())
	{
		previous = base;
		for (current = base->getNextNode(); current != nullptr;)
		{
			if (current->getData() == base->getData())
			{
				temp = current;
				current = current->getNextNode();
				previous->setNextNode(current);
				delete temp;
				count--;

			}
			else
			{
				previous = current;
				current = current->getNextNode();
			}
		}
	}
}

int LinkedList::SearchFromEnd(int k)
{
	Node* result = Head;
	for (auto i = 0; i < count - k; i++)
		result = result->getNextNode();
	return result->getData();
}
