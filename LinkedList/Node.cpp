#include "Node.h"

Node::Node() {}

Node::Node(int data)
{
	Data = data;
}

Node* Node::getNextNode() { return NextNode; }

int Node::getData() { return Data; }

void Node::setNextNode(Node* node) { NextNode = node; }
void Node::setData(int data) { Data = data; }