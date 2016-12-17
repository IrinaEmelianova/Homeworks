#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void addRecord(Record phonebook[], int &numberOfRecords)
{
	if (numberOfRecords == 100)
	{
		cout << "�������� ������ ����, ������ �� ����� ���� ���������" << endl << endl;
	}
	else
	{
		cout << "������� ���: ";
		cin >> phonebook[numberOfRecords].name;

		cout << "������� ���������� �����: ";
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
	cout << "������� ��� ��� ������: ";
	string name;
	cin >> name;

	for (int j = 0; j < numberOfRecords; j++)
	{
		if (name == phonebook[j].name)
		{
			cout << "���������� ����� " << name << ": " << phonebook[j].phone << endl << endl;
			break;
		}
	}
}

void searchName(Record phonebook[], int numberOfRecords)
{
	cout << "������� ����� �������� ��� ������: ";
	string phone;
	cin >> phone;

	for (int k = 0; k < numberOfRecords; k++)
	{
		if (phone == phonebook[k].phone)
		{
			cout << "�������� ������ " << phone << ": " << phonebook[k].name << endl << endl;
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