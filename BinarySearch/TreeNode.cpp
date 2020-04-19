#include "TreeNode.h"

TreeNode::TreeNode()
{
	value_ = 0;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
}

TreeNode::TreeNode(int value)
{
	assert(value >= 0);
	value_ = value;
}

int TreeNode::getValue()
{
	return value_;
}

void TreeNode::setValue(int value)
{
	assert(value >= 0);
	value_ = value;
}

TreeNode* TreeNode::getLeftChild()
{
	return leftChild_;
}

void TreeNode::setLeftChild(TreeNode* node)
{
	assert(node);
	leftChild_ = node;
}

TreeNode* TreeNode::getRightChild()
{
	return rightChild_;
}

void TreeNode::setRightChild(TreeNode* node)
{
	assert(node);
	rightChild_ = node;
}
