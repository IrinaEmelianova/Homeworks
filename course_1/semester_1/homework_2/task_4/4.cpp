#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

void sort(int array[10], int length)
{
	int left = 0;
	int right = length - 1;
	int firstElement = array[0];

	while (left <= right)
	{
		if (array[left] >= firstElement)
		{
			if (array[right] < firstElement)
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
}

int main()
{
	srand(time(nullptr));

	const int length = 10;
	int array[length];

	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 100 + 1;
	}
	int firstElement = array[0];
	
	sort(array, length);

	cout << firstElement << endl;
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}

	return 0;
}