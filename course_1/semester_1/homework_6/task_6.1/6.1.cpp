#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int resultOfOperation(StackElement *head, char operation)
{
	if (operation == '+')
	{
		return (head -> value + head -> next -> value);
	}
	if (operation == '-')
	{
		return (head -> next -> value - head -> value);
	}
	if (operation == '*')
	{
		return (head -> value * head -> next -> value);
	}
	if (operation == '/')
	{
		return (head -> next -> value / head -> value);
	}
}

int resultOfCalculation(string postfixExpression)
{
	StackElement *head = nullptr;
	
	for (int i = 0; i < postfixExpression.length(); i++)
	{
		if (int(postfixExpression[i]) >= 48 && int(postfixExpression[i]) <= 57)
		{
			push(head, int(postfixExpression[i]) - 48);
		}

		if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/')
		{
			int result = resultOfOperation(head, postfixExpression[i]);
			pop(head);
			pop(head);
			push(head, result);
		}
	}

	return head -> value;
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