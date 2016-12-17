#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void addRecord(Record phonebook[], int &numberOfRecords)
{
	if (numberOfRecords == 100)
	{
		cout << "Превышен размер базы, запись не может быть добавлена" << endl << endl;
	}
	else
	{
		cout << "Введите имя: ";
		cin >> phonebook[numberOfRecords].name;

		cout << "Введите телефонный номер: ";
		cin >> phonebook[numberOfRecords].phone;

		++numberOfRecords;

		cout << endl;
	}
}

void printAllRecords(Record phonebook[], int numberOfRecords)
{
	for (int j = 0; j < numberOfRecords; j++)
	{
		cout << phonebook[j].name << " " << phonebook[j].phone << endl;
	}
	
	cout << endl;
}

void searchPhone(Record phonebook[], int numberOfRecords)
{
	cout << "Введите имя для поиска: ";
	string name;
	cin >> name;

	for (int j = 0; j < numberOfRecords; j++)
	{
		if (name == phonebook[j].name)
		{
			cout << "Телефонный номер " << name << ": " << phonebook[j].phone << endl << endl;
			break;
		}
	}
}

void searchName(Record phonebook[], int numberOfRecords)
{
	cout << "Введите номер телефона для поиска: ";
	string phone;
	cin >> phone;

	for (int k = 0; k < numberOfRecords; k++)
	{
		if (phone == phonebook[k].phone)
		{
			cout << "Владелец номера " << phone << ": " << phonebook[k].name << endl << endl;
			break;
		}
	}
}

void saveInFile(Record phonebook[], int numberOfRecords)
{
	ofstream phonebookFile("phonebook.txt");

	for (int j = 0; j < numberOfRecords; j++)
	{
		phonebookFile << phonebook[j].name << " " << phonebook[j].phone << endl;
	}

	cout << endl;
	phonebookFile.close();
}

void readFromFile(Record phonebook[], int &numberOfRecords, const string &fileName)
{
	ifstream phonebookFile(fileName);
	if (!phonebookFile.is_open())
	{
		ofstream phonebookFile(fileName);
	}

	while (!phonebookFile.eof())
	{
		phonebookFile >> phonebook[numberOfRecords].name;
		phonebookFile >> phonebook[numberOfRecords].phone;
		++numberOfRecords;
	}

	phonebookFile.close();
}