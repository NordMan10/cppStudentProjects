#include "Node.h"
#include <iostream>

Node::Node() {}

Node::Node(int data)
{
	Data = data;
}

Node* Node::getNextNode() const { return NextNode; }

int Node::getData() const { return Data; }

void Node::setNextNode(Node* node) { NextNode = node; }
void Node::setData(int data) { Data = data; }
