#pragma once
#include <cassert>  

template<typename T>
class LinkedList
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* NextNode;
		T Data;
		Node(T data)
		{
			this->Data = data;
			this->NextNode = nullptr;
		}
	};
	
	Node<T>* Head;
public:
	int Count;
	LinkedList()
	{
		Count = 0;
		Head = nullptr;
	}
	
	T operator[] (const int value)
	{
		assert(value >= 0 && value < this->Count);
		Node<T>* result = this->Head;
		for (auto i = 0; i < value; i++)
			if (result != nullptr)
				result = result->NextNode;
		return result->Data;
	}

	void Add(T data)
	{
		if (Head == nullptr)
		{
			this->Head = new Node<T>(data);
			this->Head->NextNode = nullptr;
		}
		else
		{
			Node<T>* current = this->Head;
			while (current->NextNode != nullptr)
				current = current->NextNode;
			current->NextNode = new Node<T>(data);
		}
		this->Count++;
	}
	void RemoveDuplicates()
	{
		Node<T>* temp;
		Node<T>* previous;
		Node<T>* current;
		Node<T>* tempPrev;
		for (previous = this->Head; previous != nullptr; previous = previous->NextNode)
		{
			tempPrev = previous;
			for (current = previous->NextNode; current != nullptr;)
			{
				if (current->Data == previous->Data)
				{
					temp = tempPrev->NextNode = current->NextNode;
					free(current);
					current = temp;
					this->Count--;
				}
				else
				{
					tempPrev = current;
					current = current->NextNode;
				}
			}
		}
	}
	T SearchFromEnd(int k)
	{
		Node<T>* result = this->Head;
		for (auto i = 0; i < this->Count - k; i++)
			result = result->NextNode;
		return result->Data;
	}
};

