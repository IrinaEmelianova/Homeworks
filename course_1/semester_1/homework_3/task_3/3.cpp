#include <iostream>

using namespace std;

int supportElement(int array[], int left, int right)
{
	int elem = array[0];
	int i = left;
	while (array[i] == elem && i <= right)
	{
		i++;
	}
	if (array[i] > elem)
	{
		elem = array[i];
	}
	return elem;
}

int partition(int array[], int left, int right, int element)
{
	while (left < right)
	{
		if (array[left] >= element)
		{
			if (array[right] < element)
			{
				swap (array[left], array[right]);
				left++;
				right--;
			}
			else
			{
				right--;
			}
		}
		else
		{
			left++;
		}
	}
	return right;
}

void qsort(int array[], int left, int right)
{
	if (left < right)
	{
		int partitionEdge = partition(array, left, right, supportElement(array, left, right));
			
		if (partitionEdge != right)
		{
			qsort(array, left, partitionEdge);
		}
		qsort(array, partitionEdge + 1, right);
	}
}

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
		if (array[i] > array[i+1])
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

	cout << "type the number of elements: ";
	int length = 0;
	cin >> length;

	cout << "type an array: ";
	int array[100000];
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}

	qsort(array, 0, length - 1);

	cout << theMostCommonElement(array, length) << endl;

	return 0;
}