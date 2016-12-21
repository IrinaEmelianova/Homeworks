#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

bool tests()
{
	string str1 = "(* (+ 1 1) 2)";
	string str2 = "+ 3 (/ (+ 2 4) 3)";

	TreeElement *root1 = nullptr;
	TreeElement *root2 = nullptr;
	int i = 0;
	int j = 0;

	buildTree(root1, str1, i);
	buildTree(root2, str2, j);

	bool returning = (countResult(root1) == 4 && countResult(root2) == 5);

	deleteTree(root1);
	deleteTree(root2);

	return returning;
}

int main()
{
	if (!tests())
	{
		cout << "Program error";
		return 0;
	}

	string expression;
	readFromFile(expression);

	TreeElement *root = nullptr;
	int i = 0;
	buildTree(root, expression, i);

	cout << "Expression: ";
	print(root);

	cout << endl << "Expression value: " << countResult(root) << endl;

	deleteTree(root);

	return 0;
}