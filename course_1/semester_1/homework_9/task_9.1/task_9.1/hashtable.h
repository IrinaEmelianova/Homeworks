#pragma once
#include <string>

const int sizeOfHashTable = 10;

struct HashTable;

// create new hash table
HashTable *createHashTable();

// delete hash table
void deleteHashTable(HashTable *hashTable);

// add a word to hash table
void addWord(HashTable *hashTable, const std::string &word);

// print all elements 
void printHashTable(HashTable *hashTable);

// count load factor of hash table
double loadFactor(HashTable *hashTable);

// count maximal length of list in the bucket
int maxLength(HashTable *hashTable);

// count medium length of list in the bucket
int mediumLength(HashTable *hashTable);
