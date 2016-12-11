#include <string>
#include "hashtable.h"

using namespace std;

HashTable *createHashTable()
{
	auto hashTable = new HashTable;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		hashTable -> head[i] = nullptr;
	}

	return hashTable;
}

void deleteHashTable(HashTable *hashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		deleteList(hashTable -> head[i]);
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
	addToHead(hashTable -> head[hash], value);
}

ListElement *searchElement(HashTable *hashTable, const string &value)
{
	int hash = createHash(value);

	ListElement *searchedElement = searchListElement(hashTable -> head[hash], value);

	return searchedElement;
}

void addWord(HashTable *hashTable, string word)
{
	if (searchElement(hashTable, word) != nullptr)
	{
		auto searchedElement = searchElement(hashTable, word);
		++searchedElement -> numberOfRepetitions;
	}
	else
	{
		addElement(hashTable, word);
	}
}

double loadFactor(HashTable *hashTable)
{
	double numberOfElements = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		numberOfElements = numberOfElements + numberOfListElements(hashTable -> head[i]);
	}

	double loadFactor = numberOfElements/sizeOfHashTable;
	return loadFactor;
}

int mediumLength(HashTable *hashTable)
{
	int numberOfFilledBuckets = 0;
	int numberOfElements = 0;

	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable -> head[i] != nullptr)
		{
			++numberOfFilledBuckets;
		}

		numberOfElements = numberOfElements + numberOfListElements(hashTable -> head[i]);
	}

	int mediumLength = numberOfElements/numberOfFilledBuckets;

	return mediumLength;
}

int maxLength(HashTable *hashTable)
{
	int maxLength = 0;

	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (numberOfListElements(hashTable -> head[i]) > maxLength)
		{
			maxLength = numberOfListElements(hashTable -> head[i]);
		}
	}

	return maxLength;
}