#include "LinkedList.h"

LinkedList::LinkedList() {}

LinkedList::~LinkedList() { delete head; }

int LinkedList::Count() const { return count; }

int LinkedList::operator[] (const int value) const
{
	Node* result = head;
	if (value < count)
	{
		for (auto i = 0; i < value; i++)
		{
			result = result->getNextNode();
		}
	}
	return result->getData();
}

void LinkedList::Add(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		head->setNextNode(nullptr); // надо ли?
	}
	else
	{
		Node* current = head;
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
	for (base = head; base != nullptr; base = base->getNextNode())
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

int LinkedList::SearchFromEnd(int k) const
{
	Node* result = head;
	for (auto i = 0; i < count - k; i++)
		result = result->getNextNode();
	return result->getData();
}
