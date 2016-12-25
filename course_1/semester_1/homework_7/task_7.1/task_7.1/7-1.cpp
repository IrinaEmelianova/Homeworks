#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "Ошибка" << endl;
		return 0;
	}

	TreeElement *root = nullptr;

	cout << "Обозначения команд: " << endl;
	cout << "0 - выйти" << endl;
	cout << "1 - добавить значение целого типа в множество" << endl;
	cout << "2 - удалить значение из множества" << endl;
	cout << "3 - проверить, принадлежит ли значение множеству" << endl;
	cout << "4 - вывести элементы множества в порядке возрастания" << endl;
	cout << "5 - вывести элементы множества в порядке убывания" << endl << endl;

	int command = 1;
	while (command != 0)
	{
		cout << "Введите команду: ";
		cin >> command;

		switch (command)
		{
			case 0:
			{
				deleteTree(root);
				return 0;
			}

			case 1:
			{
				cout << "Введите значение для добавления: ";
				int newElement = 0;
				cin >> newElement;

				add(root, newElement);

				break;
			}

			case 2:
			{
				cout << "Введите значение для удаления: ";
				int element = 0;
				cin >> element;

				deleteElement(root, element);

				break;
			}

			case 3:
			{
				cout << "Введите значение для проверки: ";
				int element = 0;
				cin >> element;

				if (containsInTree(root, element))
				{
					cout << "Значение содержится в множестве" << endl;
				}
				else
				{
					cout << "Значение не содержится в множестве" << endl;
				}

				break;
			}

			case 4:
			{
				printInAscendingOrder(root);
				cout << endl;

				break;
			}

			case 5:
			{
				printInDescendingOrder(root);
				cout << endl;

				break;
			}

			default:
			{
				cout << "Некорректно введена команда" << endl;
			}
		}

		cout << endl;
	}
}