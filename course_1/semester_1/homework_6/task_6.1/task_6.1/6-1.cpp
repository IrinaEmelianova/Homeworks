#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int resultOfOperation(int first, int second, char operation)
{
	if (operation == '+')
	{
		return (first + second);
	}
	if (operation == '-')
	{
		return (second - first);
	}
	if (operation == '*')
	{
		return (first * second);
	}
	if (operation == '/')
	{
		return (second / first);
	}
}

int resultOfCalculation(string postfixExpression)
{
	StackElement *head = nullptr;
	
	for (int i = 0; i < postfixExpression.length(); i++)
	{
		if (int(postfixExpression[i]) >= '0' && int(postfixExpression[i]) <= '9')
		{
			push(head, int(postfixExpression[i]) - '0');
		}

		if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/')
		{
			int  first = headValue(head);
			pop(head);
			int second = headValue(head);
			pop(head);

			int result = resultOfOperation(first, second, postfixExpression[i]);
			push(head, result);
		}
	}

	return headValue(head);
}

bool tests()
{
	string exp1 = "9 6 - 1 2 + *";
	string exp2 = "1 2 - 5 *";
	string exp3 = "6 4 + 8 3 - *";

	if (resultOfCalculation(exp1) == 9 && resultOfCalculation(exp2) == -5 && resultOfCalculation(exp3) == 50)
	{
		return true;
	}
	return false;
}

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "Ошибка";
		return 0;
	}

	cout << "Введите выражение в постфиксной форме: ";
	string postfixExpression;
	getline(cin, postfixExpression);

	cout << "Результат выражения: " << resultOfCalculation(postfixExpression) << endl;

	return 0;
}