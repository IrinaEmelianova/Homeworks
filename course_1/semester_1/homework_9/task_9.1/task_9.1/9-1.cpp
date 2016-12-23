#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "hashtable.h"

using namespace std;

bool tests()
{
	ifstream fin("test.txt");
	auto hashTable = createHashTable();

	string word;
	while (!fin.eof())
	{
		fin >> word;
		addWord(hashTable, word);
	}

	fin.close();

	return (loadFactor(hashTable) == 0.7 && maxLength(hashTable) == 2 && mediumLength(hashTable) == 1);
}

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "Ошибка" << endl;
		return 0;
	}

	ifstream fin("file.txt");
	if (fin == nullptr)
	{
		cout << "Ошибка при открытии файла" << endl;
		return 0;
	}

	auto hashTable = createHashTable();

	string word;
	while (!fin.eof())
	{
		fin >> word;
		addWord(hashTable, word);
	}

	fin.close();

	printHashTable(hashTable);

	double x = loadFactor(hashTable);
	cout << "Коэффициент заполнения хеш-таблицы: ";
	printf("%.4f", x);
	cout << endl;

	cout << "Максимальная длина списка в сегменте таблицы: " << maxLength(hashTable) << endl;
	cout << "Средняя длина списка: " << mediumLength(hashTable) << endl;

	deleteHashTable(hashTable);
	
	return 0;
}