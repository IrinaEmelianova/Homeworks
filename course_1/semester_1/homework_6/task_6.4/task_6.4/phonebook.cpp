#include "phonebook.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFromFile(Record *&phonebook, const string &fileName)
{
	ifstream phonebookFile(fileName);
	if (!phonebookFile.is_open())
	{
		cout << "File opening error";
		return;
	}

	while (!phonebookFile.eof())
	{
		Record *newRecord = new Record;
		phonebookFile >> newRecord->name;
		phonebookFile >> newRecord->phone;
		newRecord->next = nullptr;

		if (phonebook != nullptr)
		{
			newRecord->next = phonebook;
		}

		phonebook = newRecord;
	}

	phonebookFile.close();
}

int phonebookLength(Record *phonebook)
{
	int length = 0;
	while (phonebook != nullptr)
	{
		++length;
		phonebook = phonebook->next;
	}

	return length;
}

void addInEnd(Record *&phonebook, const string &phone, const string &name)
{
	if (phonebook == nullptr)
	{
		auto newRecord = new Record;
		newRecord->name = name;
		newRecord->phone = phone;
		newRecord->next = nullptr;
		phonebook = newRecord;
		return;
	}

	Record *position = phonebook;
	for (int i = 0; i < phonebookLength(phonebook) - 1; i++)
	{
		position = position->next;
	}

	auto newRecord = new Record;
	newRecord->name = name;
	newRecord->phone = phone;
	newRecord->next = nullptr;
	position->next = newRecord;
}

void deleteRecord(Record *&phonebook)
{
	Record *oldRecord = phonebook;
	phonebook = phonebook -> next;
	delete oldRecord;
}

void deletePhonebook(Record *&phonebook)
{
	while (phonebook != nullptr)
	{
		deleteRecord(phonebook);
	}
}

void print(Record *phonebook)
{
	while (phonebook != nullptr)
	{
		cout << phonebook->name << " " << phonebook->phone << endl;
		phonebook = phonebook->next;
	}
}