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

	cout << "Обозначения команд: " << endl;
	cout << "0 - выйти" << endl;
	cout << "1 - добавить запись (имя и телефон)" << endl;
	cout << "2 - распечатать все имеющиеся записи" << endl;
	cout << "3 - найти телефон по имени" << endl;
	cout << "4 - найти имя по телефону" << endl;
	cout << "5 - сохранить текущие данные в файл" << endl << endl;

	int command = 1;
	while (command != 0)
	{
		cout << "Введите команду: ";
		cin >> command;
		
		switch (command)
		{
			case 1:
			{
				addRecord(phonebook, numberOfRecords);
				break;
			}

			case 2:
			{
				printAllRecords(phonebook, numberOfRecords);
				break;
			}
	
			case 3:
			{
				searchPhone(phonebook, numberOfRecords);
				break;
			}

			case 4:
			{
				searchName(phonebook, numberOfRecords);
				break;
			}

			case 5:
			{
				saveInFile(phonebook, numberOfRecords);
				break;
			}
		}
	}

	return 0;
}