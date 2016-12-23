#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

struct TreeElement
{
	char operation;
	int value;
	TreeElement *leftChild;
	TreeElement *rightChild;
};

void readFromFile(string &expression)
{
	FILE *fin = fopen("file.txt", "r");
	if (fin == nullptr)
	{
		cout << "File opening error";
		return;
	}

	char symbol = '0';
	while (!feof(fin))
	{
		symbol = fgetc(fin);
		expression += symbol;
	}

	fclose(fin);
}

void addValueToRoot(TreeElement *&root, int value)
{
	TreeElement *newElement = new TreeElement;
	newElement->value = value;
	newElement->operation = '0';
	newElement->leftChild = nullptr;
	newElement->rightChild = nullptr;
	root = newElement;
}

void addOperatorToRoot(TreeElement *&root, char operation)
{
	TreeElement *newElement = new TreeElement;
	newElement->value = 0;
	newElement->operation = operation;
	newElement->leftChild = nullptr;
	newElement->rightChild = nullptr;
	root = newElement;
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

void buildTree(TreeElement *&root, const string &expression, int &counter)
{
	if (counter >= expression.length())
	{
		return;
	}
	
	if (expression[counter] == ' ')
	{
		++counter;
	}

	if (isOperator(expression[counter]))
	{
		addOperatorToRoot(root, expression[counter]);

		if (root->leftChild == nullptr)
		{
			++counter;
			buildTree(root->leftChild, expression, counter);
		}
		
		++counter;
		buildTree(root->rightChild, expression, counter);
		
		return;
	}

	if (expression[counter] == '(' || expression[counter] == ')')
	{
		++counter;
		buildTree(root, expression, counter);
		return;
	}
	
	if (isDigit(expression[counter]))
	{
		int number = 0;
		while (counter < expression.length() && isDigit(expression[counter]))
		{
			number = number * 10 + expression[counter] - '0';
			++counter;
		}
		--counter;
		addValueToRoot(root, number);
		return;
	}
}

void deleteTree(TreeElement *&root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->leftChild == nullptr && root->rightChild == nullptr)
	{
		delete root;
		root = nullptr;
		return;
	}
	else
	{
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
	}
}

void print(TreeElement *root)
{
	if (root == nullptr)
	{
		return;
	}

	if (isOperator(root->operation))
	{
		cout << "(";
		cout << root->operation << " ";
		print(root->leftChild);
		print(root->rightChild);
		cout << ") ";
	}
	else
	{
		cout << root->value << " ";
	}
}

int countResult(TreeElement *root)
{
	int result = 0;
	int a = 0;
	int b = 0;

	if (isOperator(root->operation))
	{
		a = countResult(root->leftChild);
		b = countResult(root->rightChild);

		if (root->operation == '+')
		{
			result = a + b;
		}
		if (root->operation == '-')
		{
			result = a - b;
		}
		if (root->operation == '*')
		{
			result = a * b;
		}
		if (root->operation == '/')
		{
			result = a / b;
		}
	}
	else
	{
		result = root->value;
	}

	return result;
}
