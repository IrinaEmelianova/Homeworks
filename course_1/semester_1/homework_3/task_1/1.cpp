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

void insertionSort(int array[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int k = i - 1;
		while (array[i] < array[k] && k >= left)
		{
			k--;
		}

		int a = array[i];
		for(int j = i-1; j > k; j--)
		{
			array[j+1] = array[j];
		}
		array[k+1] = a;
	}

}

void qsort(int array[], int left, int right)
{
	if (right - left + 1 < 10)
	{
		insertionSort(array, left, right);
	}
	else
	{
		if (left < right)
		{
			int partitionEdge = partition(array, left, right, supportElement(array, left, right));
			
			qsort(array, left, partitionEdge);
			qsort(array, partitionEdge + 1, right);
		}
	}
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

bool tests()
{
	const int m = 10;
	int array1[m] = { 8, 3, 9, 2, 0, 1, 3, 7, 4, 2 };
	int array2[m] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int array3[m] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	return testQsort(array1, m) && testQsort(array2, m) && testQsort(array3, m);
}

int main()
{
	const int length = 15;
	int array[length];
	cout << "type an array (" << length << " elements): ";
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}

	if (!tests())
	{
		cout << "error" << endl;
		return 1;
	}
		
	qsort(array, 0, length - 1);
		
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	
	return 0;
}