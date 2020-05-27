#include "TreeNode.h"

TreeNode::TreeNode()
{
	value_ = 0;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
}

TreeNode::TreeNode(int value)
{
	value_ = value;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
}

int TreeNode::getValue()
{
	return value_;
}

void TreeNode::setValue(int value)
{
	value_ = value;
}

TreeNode* TreeNode::getLeftChild()
{
	return leftChild_;
}

void TreeNode::setLeftChild(TreeNode* node)
{
	leftChild_ = node;
}

TreeNode* TreeNode::getRightChild()
{
	return rightChild_;
}

void TreeNode::setRightChild(TreeNode* node)
{
	rightChild_ = node;
}
