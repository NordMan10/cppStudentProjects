#pragma once
#include <cassert>

class TreeNode
{
public:
	TreeNode();
	TreeNode(int value);
	int getValue();
	void setValue(int value);
	TreeNode* getLeftChild();
	void setLeftChild(TreeNode* node);
	TreeNode* getRightChild();
	void setRightChild(TreeNode* node);
private:
	int value_;
	TreeNode* leftChild_;
	TreeNode* rightChild_;
};

