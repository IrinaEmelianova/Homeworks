#include <iostream>
#include "mergesort.h"

using namespace std;

bool test1()
{
	Record *phonebook1 = nullptr;
	readFromFile(phonebook1, "test.txt");
	mergeSort(phonebook1, false);

	while (recordsNext(phonebook1) != nullptr)
	{
		if (recordsName(phonebook1) > recordsName(recordsNext(phonebook1)))
		{
			deletePhonebook(phonebook1);
			return false;
		}
		phonebook1 = recordsNext(phonebook1);
	}

	deletePhonebook(phonebook1);
	return true;
}

bool test2()
{
	Record *phonebook2 = nullptr;
	readFromFile(phonebook2, "test.txt");
	mergeSort(phonebook2, true);

	while (recordsNext(phonebook2) != nullptr)
	{
		if (recordsPhone(phonebook2) > recordsPhone(recordsNext(phonebook2)))
		{
			deletePhonebook(phonebook2);
			return false;
		}
		phonebook2 = recordsNext(phonebook2);
	}

	deletePhonebook(phonebook2);
	return true;
}

bool tests()
{
	return (test1() && test2());
}

int main()
{
	if (!tests())
	{
		cout << "Program error";
		return 0;
	}

	Record *phonebook = nullptr;
	readFromFile(phonebook, "phonebook.txt");

	cout << "Type 0 for sorting by name, type 1 for sorting by phone: ";
	bool command = false;
	cin >> command;

	mergeSort(phonebook, command);
	print(phonebook);

	deletePhonebook(phonebook);

	return 0;
}