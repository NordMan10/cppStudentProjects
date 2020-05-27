#pragma once
#include "TreeNode.h"



class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int value);
	~BinaryTree();
	void Insert(int value);
	TreeNode* Search(int value);
	TreeNode* CreateMinimalBST(int* startArray, int begin, int end);
	void SetRoot(TreeNode* root);
private:
	TreeNode* root_ = nullptr;
	void Insert(TreeNode* node, int value);
	TreeNode* Search(TreeNode* node, int value);
	void removeNodes(TreeNode* node);
};

