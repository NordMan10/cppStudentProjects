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

	void Push(int data)
	{
		if (Head == nullptr)
		{
			this->Head = new Node(data);
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

	int Pop()
	{
		Node* current = this->Head;
		Node* previous= this->Head;
		while (current->NextNode != nullptr)
		{
			previous = current;
			current = current->NextNode;
		}
		Count--;
		previous->NextNode = nullptr;
		return current->Data;
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

