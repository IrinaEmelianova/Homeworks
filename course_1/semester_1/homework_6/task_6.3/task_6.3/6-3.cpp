#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isDigit(char symbol)
{
	if (int(symbol) >= '0' && int(symbol) <= '9')
	{
		return true;
	}
	return false;
}

bool isOperator(char symbol)
{
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
	{
		return true;
	}
	return false;
}

bool biggerPriority(char operator1, char operator2)
{
	if ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-'))
	{
		return true;
	}
	return false;
}

string postfixForm(string infixForm)
{
	StackElement *head = nullptr;
	string postfixForm;

	for (int i = 0; i < infixForm.length(); i++)
	{
		if (isDigit(infixForm[i]))
		{
			postfixForm = postfixForm + infixForm[i] + ' ';
		}

		if (infixForm[i] == '(')
		{
			push(head, infixForm[i]);
		}

		if (infixForm[i] == ')')
		{
			while (head -> value != '(')
			{
				char a = head -> value;
				postfixForm = postfixForm + a + ' ';
				pop(head);
			}

			pop(head);
		}

		if (isOperator(infixForm[i]))
		{
			while (head != nullptr && isOperator(head -> value))
			{
				if (!biggerPriority(infixForm[i], head -> value))
				{
					char a = head -> value;
					postfixForm = postfixForm + a + ' ';
					pop(head);
				}
				else
				{
					break;
				}
			}

			push(head, infixForm[i]);
		}
	}

	while (!isEmpty(head))
	{
		char a = head -> value;
		postfixForm = postfixForm + a + ' ';
		pop(head);
	}

	return postfixForm;
}

bool tests()
{
	string str1 = "(1 + 1) * 2";
	string str2 = "2 - 7 * 5";
	string str3 = "1 * (7 - 4) + 3";

	if (postfixForm(str1) == "1 1 + 2 * " && postfixForm(str2) == "2 7 5 * - " && postfixForm(str3) == "1 7 4 - * 3 + ")
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

	cout << "Введите выражение для преобразования: ";
	string infixForm;
	getline (cin, infixForm);

	cout << "Выражение в постфиксной форме: " << postfixForm(infixForm) << endl;

	return 0;
}