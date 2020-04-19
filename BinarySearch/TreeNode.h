#pragma once
#include <cassert>

class TreeNode
{
public:
	TreeNode();
	TreeNode(int value);
	int getValue();
	void setValue(int value);
	TreeNode* getFirstChild();
	void setFirstChild(TreeNode* node);
	TreeNode* getSecondChild();
	void setSecondChild(TreeNode* node);
private:
	int value_;
	TreeNode* firstChild_;
	TreeNode* secondChild_;
};

