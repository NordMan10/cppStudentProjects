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
	if (node->getFirstChild() == nullptr && node->getSecondChild() == nullptr)
		return;
	if (node->getFirstChild() != nullptr)
	{
		removeNodes(node->getFirstChild());
		delete(node->getFirstChild());
	}
	if (node->getSecondChild() != nullptr)
	{
		removeNodes(node->getSecondChild());
		delete(node->getSecondChild());
	}
	if (node->getValue() == root_->getValue()) delete(node);
}

BinaryTree::~BinaryTree()
{
	removeNodes(root_);
}

void BinaryTree::Insert(int value)
{
	
}

//TreeNode* BinaryTree::Search(int value)
//{
//
//}

void BinaryTree::addNode(TreeNode* node, int* startArray, int begin, int end)
{
	if (begin > end)
	{
		cout << "empty" << endl;
		return;
	}
	int middleIndex = (end - begin) / 2;
	node->setValue(*(startArray + begin + middleIndex));
	cout << "node->getValue():" << node->getValue() << endl;
	node->setFirstChild(new TreeNode());
	node->setSecondChild(new TreeNode());
	cout << "left: ";
	addNode(node->getFirstChild(), startArray, begin, begin + middleIndex - 1);
	if (begin != begin + middleIndex + 1)
		cout << "right: ";
		addNode(node->getFirstChild(), startArray, begin + middleIndex + 1, end);
}

void BinaryTree::CreateMinimalBST(int* startArray, int begin, int end)
{
	addNode(root_, startArray, begin, end);

}