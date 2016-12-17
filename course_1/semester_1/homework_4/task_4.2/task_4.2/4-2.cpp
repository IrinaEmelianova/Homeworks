#include <iostream>
#include <fstream>
#include "qsort.h"

using namespace std;

int theMostCommonElement(int array[], int length)
{
	int maxNumberOfEqualElements = 0;
	int numberOfEqualElements = 1;
	int mostCommonElement = array[0];

	for (int i = 0; i < length; i++)
	{
		if (array[i] == array[i + 1])
		{
			++numberOfEqualElements;
		}
		else
		{
			if (numberOfEqualElements > maxNumberOfEqualElements)
			{
				maxNumberOfEqualElements = numberOfEqualElements;
				mostCommonElement = array[i];
			}

			numberOfEqualElements = 1;
		}
	}

	return mostCommonElement;
}

bool testQsort(int array[], int arrayLength)
{
	qsort(array, 0, arrayLength - 1);

	for (int i = 0; i < arrayLength - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}

	return true;
}

bool testTheMostCommonElement()
{
	const int l = 10;
	int array1[l] = { 1, 2, 2, 3, 4, 6, 6, 6, 8, 9 };
	int array2[l] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int array3[l] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	return theMostCommonElement(array1, l) == 6 && theMostCommonElement(array2, l) == 0 && theMostCommonElement(array3, l) == 1;
}

bool tests()
{
	const int m = 10;
	int array1[m] = { 8, 3, 9, 2, 0, 1, 3, 7, 4, 2 };
	int array2[m] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array3[m] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	return testQsort(array1, m) && testQsort(array2, m) && testQsort(array3, m) && testTheMostCommonElement();
}

int main()
{
	if (!tests())
	{
		cout << "error" << endl;
		return 1;
	}

	int array[100000];
	int length = 0;

	ifstream inputFile("input.txt");
	if (!inputFile.is_open())
	{
		cout << "opening file error" << endl;
		return 0;
	}

	while (!inputFile.eof())
	{
		int number = 0;
		inputFile >> number;
		array[length] = number;
		++length;
	}

	inputFile.close();

	qsort(array, 0, length - 1);

	cout << "the most common element is: " << theMostCommonElement(array, length) << endl;

	return 0;
}