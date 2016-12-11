#include <iostream>
#include <string>
#include "hashtable.h"
#include <fstream>
#include <stdio.h>

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

	return (hashTable -> head[9] -> value == "down" && hashTable -> head[0] -> value == "you" && loadFactor(hashTable) == 0.7 && maxLength(hashTable) == 2 && mediumLength(hashTable) == 1);
}

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "������" << endl;
		return 0;
	}

	ifstream fin("file.txt");
	if (fin == nullptr)
	{
		cout << "������ ��� �������� �����" << endl;
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

	for (int i = 0; i < sizeOfHashTable; i++)
	{
		printList(hashTable -> head[i]);
	}

	double x = loadFactor(hashTable);
	cout << "����������� ���������� ���-�������: ";
	printf("%.4f", x);
	cout << endl;

	cout << "������������ ����� ������ � �������� �������: " << maxLength(hashTable) << endl;
	cout << "������� ����� ������: " << mediumLength(hashTable) << endl;
	
	return 0;
}