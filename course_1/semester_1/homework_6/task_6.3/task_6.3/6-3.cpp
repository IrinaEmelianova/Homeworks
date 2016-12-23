#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isDigit(char symbol)
{
	return (int(symbol) >= '0' && int(symbol) <= '9');
}

bool isOperator(char symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool biggerPriority(char operator1, char operator2)
{
	return ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-'));
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
			while (headValue(head) != '(')
			{
				char a = headValue(head);
				postfixForm = postfixForm + a + ' ';
				pop(head);
			}

			pop(head);
		}

		if (isOperator(infixForm[i]))
		{
			while (head != nullptr && isOperator(headValue(head)))
			{
				if (!biggerPriority(infixForm[i], headValue(head)))
				{
					char a = headValue(head);
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
		char a = headValue(head);
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

	return (postfixForm(str1) == "1 1 + 2 * " && postfixForm(str2) == "2 7 5 * - " && postfixForm(str3) == "1 7 4 - * 3 + ");
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