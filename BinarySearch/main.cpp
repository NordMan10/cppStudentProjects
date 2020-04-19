#include <iostream>
#include "main.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree binaryTree;
	int myArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int length = sizeof(myArray) / sizeof(myArray[0]);
	binaryTree.CreateMinimalBST(myArray, 0, length - 1);
	binaryTree.Insert(10);
	cout << "Search result: " << binaryTree.Search(10)->getValue() << endl;
	return 0;
}