#pragma once
class Node
{
public:
	Node();
	Node(int data);
	Node* getNextNode();
	void setNextNode(Node* node);
	int getData();
	void setData(int data);

private:
	int Data = 0;
	Node* NextNode = nullptr;
};