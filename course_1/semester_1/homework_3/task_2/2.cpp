#include <iostream>
#include <ctime>

using namespace std;

int supportElement(long array[], int left, int right)
{
	long elem = array[0];
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

int partition(long array[], int left, int right, long element)
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

void qsort(long array[], int left, int right)
{
	if (left < right)
	{
		long partitionEdge = partition(array, left, right, supportElement(array, left, right));
			
		if (partitionEdge != right)
		{
			qsort(array, left, partitionEdge);
		}
		qsort(array, partitionEdge + 1, right);
	}
}

bool binSearch(long array[], int left, int right, long searchedElement)
{
	if (left <= right)
	{
		if (array[(left + right) / 2] == searchedElement)
		{
			return true;
		}
		else
		{
			if (array[(left + right) / 2] > searchedElement)
			{
				return binSearch(array, left, (left + right) / 2 - 1, searchedElement);
			}
			else
			{
				return binSearch(array, (left + right) / 2 + 1, right, searchedElement);
			}
		}
	}

	return false;
}

bool testQsort(long array[], int arrayLength)
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

bool testBinSearch()
{
	const int l = 10;
	long array1[l] = { 1, 4, 6, 7, 9, 14, 57, 79, 100, 207 };

	return binSearch(array1, 0, l - 1, 1) && binSearch(array1, 0, l - 1, 14) && !binSearch(array1, 0, l - 1, 40);
}

bool tests()
{
	const int m = 10;
	long array1[m] = { 8, 3, 9, 2, 0, 1, 3, 7, 4, 2 };
	long array2[m] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	long array3[m] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	return testQsort(array1, m) && testQsort(array2, m) && testQsort(array3, m) && testBinSearch();
}

int main()
{
	if (!tests())
	{
		cout << "error" << endl;
		return 1;
	}

	cout << "type 2 numbers: ";
	int n = 0;
	int k = 0;
	cin >> n >> k;
	cout << endl;

	long array[5000];
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 1000000000;
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	qsort(array, 0, n - 1);

	for (int i = 0; i < k; i++)
	{
		long number = rand() % 1000000000;
		cout << number << " ";

		if (!binSearch(array, 0, n - 1, number))
		{
			cout << "array does not include this number" << endl;
		}
		else
		{
			cout << "array includes this number" << endl;
		}
	}

	return 0;
}