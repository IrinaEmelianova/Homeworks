#include <iostream>
#include "qsort.h"

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