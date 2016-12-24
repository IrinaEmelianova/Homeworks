#include "mergesort.h"

using namespace std;

void divide(Record *&phonebook, Record *&leftHalf, Record *&rightHalf)
{
	int length = phonebookLength(phonebook) / 2;

	Record *position = phonebook;

	for (int i = 0; i < length - 1; i++)
	{
		position = recordsNext(position);
	}

	rightHalf = recordsNext(position);
	recordsNext(position) = nullptr;

	leftHalf = phonebook;
	phonebook = nullptr;
}

void merge(Record *&phonebook1, Record *&phonebook2, Record *&phonebook, bool command)
{
	while (phonebook1 != nullptr && phonebook2 != nullptr)
	{
		if (!command && (recordsName(phonebook1) < recordsName(phonebook2)) || command && (recordsPhone(phonebook1) < recordsPhone(phonebook2)))
		{
			addInEnd(phonebook, recordsPhone(phonebook1), recordsName(phonebook1));
			deleteRecord(phonebook1);
		}
		else
		{
			addInEnd(phonebook, recordsPhone(phonebook2), recordsName(phonebook2));
			deleteRecord(phonebook2);
		}
	}

	while (phonebook1 == nullptr && phonebook2 != nullptr)
	{
		addInEnd(phonebook, recordsPhone(phonebook2), recordsName(phonebook2));
		deleteRecord(phonebook2);
	}

	while (phonebook1 != nullptr && phonebook2 == nullptr)
	{
		addInEnd(phonebook, recordsPhone(phonebook1), recordsName(phonebook1));
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