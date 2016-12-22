#include "mergesort.h"

using namespace std;

void divide(Record *&phonebook, Record *&leftHalf, Record *&rightHalf)
{
	int length = phonebookLength(phonebook) / 2;

	Record *position = phonebook;

	for (int i = 0; i < length - 1; i++)
	{
		position = position->next;
	}

	rightHalf = position->next;
	position->next = nullptr;

	leftHalf = phonebook;
	phonebook = nullptr;
}

void merge(Record *&phonebook1, Record *&phonebook2, Record *&phonebook, bool command)
{
	while (phonebook1 != nullptr && phonebook2 != nullptr)
	{
		if (!command && (phonebook1->name < phonebook2->name) || command && (phonebook1->phone < phonebook2->phone))
		{
			addInEnd(phonebook, phonebook1->phone, phonebook1->name);
			deleteRecord(phonebook1);
		}
		else
		{
			addInEnd(phonebook, phonebook2->phone, phonebook2->name);
			deleteRecord(phonebook2);
		}
	}

	while (phonebook1 == nullptr && phonebook2 != nullptr)
	{
		addInEnd(phonebook, phonebook2->phone, phonebook2->name);
		deleteRecord(phonebook2);
	}

	while (phonebook1 != nullptr && phonebook2 == nullptr)
	{
		addInEnd(phonebook, phonebook1->phone, phonebook1->name);
		deleteRecord(phonebook1);
	}
}

void mergeSort(Record *&phonebook, bool command)
{
	Record *leftHalf = nullptr;
	Record *rightHalf = nullptr;

	divide(phonebook, leftHalf, rightHalf);

	if (phonebookLength(leftHalf) > 1)
	{
		mergeSort(leftHalf, command);
	}
	if  (phonebookLength(rightHalf) > 1)
	{
		mergeSort(rightHalf, command);
	}
	
	merge(leftHalf, rightHalf, phonebook, command);
}