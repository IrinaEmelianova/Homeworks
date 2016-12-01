#include <iostream>

using namespace std;

int linearVersion(int base, int exponent)
{
	int exponentiation = base;

	if (exponent == 0)
	{
		exponentiation = 1;
	}
	else
	{
		for (int i = 1; i < exponent; i++)
		{
			exponentiation = exponentiation * base;
		}
	}

	return exponentiation;
}

int logarithmicVersion(int base, int exponent)
{
	bool array[100000] = {0};
	int arrayLength = 0;

	while (exponent > 1)
	{
		if (exponent % 2 != 0)
		{
			exponent--;
			arrayLength++;
		}

		exponent = exponent / 2;
		array[arrayLength] = true;
		arrayLength++;
	}

	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		int exponentiation = 1;
		for (int i = arrayLength; i >= 0; i--)
		{
			if (!array[i])
			{
				exponentiation = exponentiation * base;
			}
			else
			{
				exponentiation = exponentiation * exponentiation;
			}
		}
		return exponentiation;
	}
}

int main()
{
	cout << "type 2 numbers: ";
	int base = 0;
	int exponent = 0;
	cin >> base >> exponent;

	cout << "exponentiation: " << linearVersion(base, exponent) << endl;
	
	cout << "type 2 numbers: ";
	int base2 = 0;
	int exponent2 = 0;
	cin >> base2 >> exponent2;

	cout << "exponentiation: " << logarithmicVersion(base2, exponent2) << endl;

	return 0;
}