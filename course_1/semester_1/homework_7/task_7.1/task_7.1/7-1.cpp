#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "������" << endl;
		return 0;
	}

	TreeElement *root = nullptr;

	cout << "����������� ������: " << endl;
	cout << "0 - �����" << endl;
	cout << "1 - �������� �������� ������ ���� � ���������" << endl;
	cout << "2 - ������� �������� �� ���������" << endl;
	cout << "3 - ���������, ����������� �� �������� ���������" << endl;
	cout << "4 - ������� �������� ��������� � ������� �����������" << endl;
	cout << "5 - ������� �������� ��������� � ������� ��������" << endl << endl;

	int command = 1;
	while (command != 0)
	{
		cout << "������� �������: ";
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
				cout << "������� �������� ��� ����������: ";
				int newElement = 0;
				cin >> newElement;

				add(root, newElement);

				break;
			}

			case 2:
			{
				cout << "������� �������� ��� ��������: ";
				int element = 0;
				cin >> element;

				deleteElement(root, element);

				break;
			}

			case 3:
			{
				cout << "������� �������� ��� ��������: ";
				int element = 0;
				cin >> element;

				if (containsInTree(root, element))
				{
					cout << "�������� ���������� � ���������" << endl;
				}
				else
				{
					cout << "�������� �� ���������� � ���������" << endl;
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
				cout << "����������� ������� �������" << endl;
			}
		}

		cout << endl;
	}
}