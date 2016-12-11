#include <iostream>
#include <string>
#include "phonebook.h"

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");

	Record phonebook[100];
	int numberOfRecords = 0;

	readFromFile(phonebook, numberOfRecords, "phonebook.txt");

	cout << "����������� ������: " << endl;
	cout << "0 - �����" << endl;
	cout << "1 - �������� ������ (��� � �������)" << endl;
	cout << "2 - ����������� ��� ��������� ������" << endl;
	cout << "3 - ����� ������� �� �����" << endl;
	cout << "4 - ����� ��� �� ��������" << endl;
	cout << "5 - ��������� ������� ������ � ����" << endl << endl;

	int command = 1;
	while (command != 0)
	{
		cout << "������� �������: ";
		cin >> command;

		if (command == 1)
		{
			addRecord(phonebook, numberOfRecords);
		}

		if (command == 2)
		{
			printAllRecords(phonebook, numberOfRecords);
		}
	
		if (command == 3)
		{
			searchPhone(phonebook, numberOfRecords);
		}

		if (command == 4)
		{
			searchName(phonebook, numberOfRecords);
		}

		if (command == 5)
		{
			saveInFile(phonebook, numberOfRecords);
		}
	}

	return 0;
}