#include <iostream>
#include "BinaryTree.h"


using namespace std;

BinaryTree::BinaryTree()
{
	root_ = new TreeNode();
}

BinaryTree::BinaryTree(int value)
{
	root_->setValue(value);
}

void BinaryTree::removeNodes(TreeNode* node)
{
	if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr)
		return;
	if (node->getLeftChild() != nullptr)
	{
		removeNodes(node->getLeftChild());
		delete(node->getLeftChild());
	}
	if (node->getRightChild() != nullptr)
	{
		removeNodes(node->getRightChild());
		delete(node->getRightChild());
	}
	if (node->getValue() == root_->getValue()) delete(node);
}

BinaryTree::~BinaryTree()
{
	removeNodes(root_);
}

void BinaryTree::Insert(TreeNode* node, int value)
{
	if (node->getValue() == value) return;
	if (value < node->getValue())
	{
		if (node->getLeftChild() == nullptr)
		{
			node->setLeftChild(new TreeNode(value));
		}
		else Insert(node->getLeftChild(), value);
	}
	else if (value > node->getValue())
	{
		if (node->getRightChild() == nullptr)
		{
			node->setRightChild(new TreeNode(value));
		}
		else Insert(node->getRightChild(), value);
	}
}

void BinaryTree::Insert(int value)
{
	if (root_ == nullptr)
	{
		root_ = new TreeNode(value);
		return;
	}
	if (root_->getValue() == value) return;
	Insert(root_, value);
}

TreeNode* BinaryTree::Search(TreeNode* node, int value)
{
	if (node->getValue() == value) return node;
	if (value < node->getValue())
	{
		if (node->getLeftChild() == nullptr)
			return nullptr;
		else Search(node->getLeftChild(), value);
	}
	else if (value > node->getValue())
	{
		if (node->getRightChild() == nullptr)
			return nullptr;
		else Search(node->getRightChild(), value);
	}
}

TreeNode* BinaryTree::Search(int value)
{
	if (root_ == nullptr) return nullptr;
	Search(root_, value);
}

void BinaryTree::SetRoot(TreeNode* root)
{
	root_ = root;
}

TreeNode* BinaryTree::CreateMinimalBST(int* startArray, int begin, int end)
{
	if (begin > end)
	{
		cout << "exit" << endl;
		return nullptr;
	}

	int middleIndex = (begin + end) / 2;
	auto treeNode = new TreeNode(startArray[middleIndex]);

	
	cout << "Left child from Node with value = : " << treeNode->getValue() << endl;
	treeNode->setLeftChild(CreateMinimalBST(startArray, begin, middleIndex - 1));
	cout << "Right child from Node with value = : " << treeNode->getValue() << endl;
	treeNode->setRightChild(CreateMinimalBST(startArray, middleIndex + 1, end));
	
	return treeNode;

}
