#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

char reversedSymbol(char symbol)
{
	if (symbol == ')')
	{
		return '(';
	}
	if (symbol == ']')
	{
		return '[';
	}
	if (symbol == '}')
	{
		return '{';
	}
}

bool balanceIsRight(string string)
{
	StackElement *head = nullptr;

	for (int i = 0; i < string.length(); i++)
	{
		if (string[i] == '(' || string[i] == '[' || string[i] == '{')
		{
			push(head, string[i]);
		}
		if (string[i] == ')' || string[i] == ']' || string[i] == '}')
		{
			if (head != nullptr && head -> value == reversedSymbol(string[i]))
			{
				pop(head);
			}
			else
			{
				push(head, '1');
				break;
			}
		}
	}

	return (head == nullptr);
}

bool tests()
{
	string str1 = "aaaa[b(c)]g";
	string str2 = "aaaa[bbb(cc]nn)";
	string str3 = "aaa]bb[ccc";

	if (balanceIsRight(str1) == true && balanceIsRight(str2) == false && balanceIsRight(str3) == false)
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

	cout << "Введите строку для проверки баланса скобок: ";
	string string;
	getline(cin, string);
	
	if (balanceIsRight(string))
	{
		cout << "Баланс в порядке";
	}
	else
	{
		cout << "Скобки не сбалансированы";
	}

	return 0;
}