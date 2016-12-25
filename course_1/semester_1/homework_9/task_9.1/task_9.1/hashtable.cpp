#include "hashtable.h"
#include "list.h"
#include <string>

using namespace std;

struct HashTable
{
	ListElement *head[sizeOfHashTable];
};

HashTable *createHashTable()
{
	auto hashTable = new HashTable;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		hashTable->head[i] = nullptr;
	}

	return hashTable;
}

void deleteHashTable(HashTable *hashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		deleteList(hashTable->head[i]);
	}

	delete hashTable;
}

int createHash(const string &key)
{
	int result = 0;
	result = (int(key[0]) + int(key[1]) * 29) % sizeOfHashTable;
	return result;
}

void addElement(HashTable *hashTable, const string &value)
{
	int hash = createHash(value);
	addToHead(hashTable->head[hash], value);
}

ListElement *searchElement(HashTable *hashTable, const string &value)
{
	int hash = createHash(value);

	ListElement *searchedElement = searchListElement(hashTable->head[hash], value);

	return searchedElement;
}

void addWord(HashTable *hashTable, const string &word)
{
	if (searchElement(hashTable, word) != nullptr)
	{
		auto searchedElement = searchElement(hashTable, word);
		increaseElementsNumberOfRepetitions(searchedElement);
	}
	else
	{
		addElement(hashTable, word);
	}
}

void printHashTable(HashTable *hashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		printList(hashTable->head[i]);
	}
}

double loadFactor(HashTable *hashTable)
{
	double numberOfElements = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		numberOfElements += numberOfListElements(hashTable->head[i]);
	}

	double loadFactor = numberOfElements / sizeOfHashTable;
	return loadFactor;
}

int mediumLength(HashTable *hashTable)
{
	int numberOfFilledBuckets = 0;
	int numberOfElements = 0;

	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable->head[i] != nullptr)
		{
			++numberOfFilledBuckets;
		}

		numberOfElements += numberOfListElements(hashTable->head[i]);
	}

	int mediumLength = numberOfElements / numberOfFilledBuckets;
	return mediumLength;
}

int maxLength(HashTable *hashTable)
{
	int maxLength = 0;

	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (numberOfListElements(hashTable->head[i]) > maxLength)
		{
			maxLength = numberOfListElements(hashTable->head[i]);
		}
	}

	return maxLength;
}