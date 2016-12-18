#include "tree.h"
#include <iostream>

using namespace std;

struct TreeElement
{
	int value;
	TreeElement *leftChild;
	TreeElement *rightChild;
};

void add(TreeElement *&root, int value)
{
	if (root == nullptr)
	{
		root = new TreeElement;
		root->value = value;
		root->leftChild = nullptr;
		root->rightChild = nullptr;
	}
	else
	{
		if (root->value > value)
		{
			add(root->leftChild, value);
		}
		if (root->value < value)
		{
			add(root->rightChild, value);
		}
	}
}

TreeElement *theLeftMostElement(TreeElement *&root)
{
	while (root->leftChild != nullptr)
	{
		root = root->leftChild;
	}

	return root;
}

void deleteElement(TreeElement *&root, int value)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->value != value)
	{
		if (root->value > value)
		{
			deleteElement(root->leftChild, value);
		}
		else
		{
			deleteElement(root->rightChild, value);
		}
	}
	else
	{
		if (root->leftChild == nullptr && root->rightChild == nullptr)
		{
			root = nullptr;
			delete root;
			return;
		}

		if (root->leftChild != nullptr && root->rightChild == nullptr)
		{
			auto oldRoot = root;
			root = root->leftChild;
			delete oldRoot;
			return;
		}

		if (root->leftChild == nullptr && root->rightChild != nullptr)
		{
			auto oldRoot = root;
			root = root->rightChild;
			delete oldRoot;
			return;
		}

		if (root->leftChild != nullptr && root->rightChild != nullptr)
		{
			auto mostLeftEl = theLeftMostElement(root->rightChild);
			root->value = mostLeftEl->value;
			deleteElement(root->rightChild, mostLeftEl->value);
			return;
		}
	}
}

void deleteTree(TreeElement *&root)
{
	while (root != nullptr)
	{
		deleteElement(root, root->value);
	}
}

void printInAscendingOrder(TreeElement *root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->leftChild != nullptr)
	{
		printInAscendingOrder(root->leftChild);
	}

	cout << root->value << " ";

	if (root->rightChild != nullptr)
	{
		printInAscendingOrder(root->rightChild);
	}
}

void printInDescendingOrder(TreeElement *root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->rightChild != nullptr)
	{
		printInDescendingOrder(root->rightChild);
	}

	cout << root->value << " ";

	if (root->leftChild != nullptr)
	{
		printInDescendingOrder(root->leftChild);
	}
}

bool containsInTree(TreeElement *root, int searchingNumber)
{
	if (root == nullptr)
	{
		return false;
	}

	if (root->value == searchingNumber)
	{
		return true;
	}
	if (root->value > searchingNumber)
	{
		return containsInTree(root->leftChild, searchingNumber);
	}
	if (root->value < searchingNumber)
	{
		return containsInTree(root->rightChild, searchingNumber);
	}
}

bool additionTest()
{
	TreeElement *root1 = nullptr;

	add(root1, 2);
	add(root1, 1);
	add(root1, 3);

	return (root1->value == 2 && root1->leftChild->value == 1 && root1->rightChild->value == 3);
}

bool deletionTest()
{
	TreeElement *root1 = nullptr;

	add(root1, 5);
	add(root1, 2);
	add(root1, 0);
	add(root1, 3);
	add(root1, 6);
	add(root1, 9);

	deleteElement(root1, 0);
	deleteElement(root1, 2);
	deleteElement(root1, 5);

	return (root1->value == 6 && root1->leftChild->value == 3 && root1->rightChild->value == 9);
}

bool containsInTreeTest()
{
	TreeElement *root1 = nullptr;

	add(root1, 1);
	add(root1, 2);
	add(root1, 3);

	return (containsInTree(root1, 1) && containsInTree(root1, 2) && !containsInTree(root1, 7));
}

bool tests()
{
	return (additionTest() && deletionTest() && containsInTreeTest());
}