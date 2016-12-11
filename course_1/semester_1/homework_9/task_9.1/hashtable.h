#include <string>
#include "list.h"

using namespace std;

const int sizeOfHashTable = 10;

struct HashTable
{
	ListElement *head[sizeOfHashTable];
};

HashTable *createHashTable();
void deleteHashTable(HashTable *hashTable);

int createHash(const string &key);

void addElement(HashTable *hashTable, const string &value);
ListElement *searchElement(HashTable *hashTable, const string &value);
void addWord(HashTable *hashTable, string word);

double loadFactor(HashTable *hashTable);
int maxLength(HashTable *hashTable);
int mediumLength(HashTable *hashTable);