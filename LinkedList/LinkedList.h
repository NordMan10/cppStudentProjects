#pragma once

class LinkedList
{
public:
	int Count;
	LinkedList()
	{
		Count = 0;
		Head = nullptr;
	}

	int operator[] (const int value)
	{
		Node* result = this->Head;
		for (auto i = 0; i < value; i++)
			if (result != nullptr)
				result = result->NextNode;
		return result->Data;
	}

	void Add(int data)
	{
		if (Head == nullptr)
		{
			this->Head = new Node(data);
			this->Head->NextNode = nullptr;
		}
		else
		{
			Node* current = this->Head;
			while (current->NextNode != nullptr)
				current = current->NextNode;
			current->NextNode = new Node(data);
		}
		this->Count++;
	}
	void RemoveDuplicates()
	{
		Node* temp;
		Node* previous;
		Node* current;
		Node* tempPrev;
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
	int SearchFromEnd(int k)
	{
		Node* result = this->Head;
		for (auto i = 0; i < this->Count - k; i++)
			result = result->NextNode;
		return result->Data;
	}

private:
	class Node
	{
	public:
		Node* NextNode;
		int Data;
		Node(int data)
		{
			this->Data = data;
			this->NextNode = nullptr;
		}
	};
	
	Node* Head;

};
