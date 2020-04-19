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
	void CreateMinimalBST(int* startArray, int begin, int end);
private:
	TreeNode* root_;
	void insert(TreeNode* node, int value);
	TreeNode* search(TreeNode* node, int value);
	void removeNodes(TreeNode* node);
	void addNode(TreeNode* node, int* startArray, int begin, int end);
};

