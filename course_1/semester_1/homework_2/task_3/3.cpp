#include <iostream>

using namespace std;

void bubbleSort(int numberOfElements, int array[100000])
{
	for (int k = 0; k < numberOfElements - 1; k++)
	{
		for (int m = k + 1; m < numberOfElements; m++)
		{
			if (array[k] > array[m])
			{
				swap (array[k], array[m]);
			}
		}
	}
}

void countingSort(int number, int minimal, int maximal, int array[100000])
{
	int additionalArray[100000];
	for (int i = minimal; i <= maximal; i++)
	{
		additionalArray[i] = 0;
	}

	for (int i = 0; i < number; i++)
	{
		additionalArray[array[i]] ++;
	}

	int j = 0;
	for (int i = minimal; i <= maximal; i++)
	{
		for (int k = 0; k < additionalArray[i]; k++)
		{
			array[j] = i;
			j++;
		}
	}
}

int main()
{
	cout << "type the number of elements: ";
	int numberOfElements = 0;
	cin >> numberOfElements;
	cout << "type an array: " << endl;
	int array[100000];
	for (int i = 0; i < numberOfElements; i++)
	{
		cin >> array[i];
	}

	bubbleSort(numberOfElements, array);

	for (int i = 0; i < numberOfElements; i++)
	{
		cout << array[i] <<" ";
	}

	cout << endl;

	cout << "type a number of elements: ";
	int number = 0;
	cin >> number;
	cout << "type a minimal and a maximal element: ";
	int minimal = 0;
	int maximal = 0;
	cin >> minimal >> maximal;

	cout << "type an array: ";
	for (int i = 0; i < number; i++)
	{
		cin >> array[i];
	}

	countingSort(number, minimal, maximal, array);

	for (int i = 0; i < number; i++)
	{
		cout << array[i] << " ";
	}

	return 0;
}