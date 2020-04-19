#include "TreeNode.h"

TreeNode::TreeNode()
{
	value_ = 0;
	firstChild_ = nullptr;
	secondChild_ = nullptr;
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

TreeNode* TreeNode::getFirstChild()
{
	return firstChild_;
}

void TreeNode::setFirstChild(TreeNode* node)
{
	assert(node);
	firstChild_ = node;
}

TreeNode* TreeNode::getSecondChild()
{
	return secondChild_;
}

void TreeNode::setSecondChild(TreeNode* node)
{
	assert(node);
	secondChild_ = node;
}
