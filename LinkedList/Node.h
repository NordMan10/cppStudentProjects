#pragma once

class Node
{
public:
	Node();
	Node(int data);
	Node* getNextNode() const;
	void setNextNode(Node* node);
	int getData() const;
	void setData(int data);

private:
	int Data = 0;
	Node* NextNode = nullptr;
};
