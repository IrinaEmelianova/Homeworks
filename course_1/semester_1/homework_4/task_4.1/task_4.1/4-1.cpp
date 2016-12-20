#include <iostream>

using namespace std;

const int length = sizeof(int) * 8;

void binaryNumber(int number, bool binaryArray[])
{
	for (int i = 0; i < length; i++)
	{
		if (number & 1)
		{
			binaryArray[i] = true;
		}

		number = number >> 1;
	}
}

void binarySum(bool binaryNumber1[], bool binaryNumber2[], bool binSum[])
{
	int sum = 0;
	bool remainder = false;
	for (int i = 0; i < length; i++)
	{
		sum = binaryNumber1[i] + binaryNumber2[i] + remainder;
		if (sum == 0)
		{
			remainder = false;
		}
		if (sum == 1)
		{
			binSum[i] = true;
			remainder = false;
		}
		if (sum == 2)
		{
			remainder = true;
		}
		if (sum == 3)
		{
			binSum[i] = true;
			remainder = true;
		}
	}
}

int decimalSum(bool binSum[])
{
	int decimalSum = 0;
	int power = 1;

	for (int i = 0; i < length; i++)
	{
		if (binSum[i])
		{
			decimalSum = decimalSum + power;
		}
		power = power * 2;
	}
	
	return decimalSum;
}

void coutArray(bool array[])
{
	for (int i = 0; i < length; i++)
	{
		cout << array[length - 1 - i];
	}
	cout << endl;
}

bool test1()
{
	int num1 = 5;
	int num2 = 9;

	bool binNum1[length] = {};
	bool binNum2[length] = {};

	binaryNumber(num1, binNum1);
	binaryNumber(num2, binNum2);

	bool binSum[length] = {};

	binarySum(binNum1, binNum2, binSum);
	
	return (decimalSum(binSum) == 14);
}

bool test2()
{
	int num1 = -3;
	int num2 = 8;

	bool binNum1[length] = {};
	bool binNum2[length] = {};

	binaryNumber(num1, binNum1);
	binaryNumber(num2, binNum2);

	bool binSum[length] = {};

	binarySum(binNum1, binNum2, binSum);
	
	return (decimalSum(binSum) == 5);
}

bool test3()
{
	int num1 = -7;
	int num2 = -2;

	bool binNum1[length] = {};
	bool binNum2[length] = {};

	binaryNumber(num1, binNum1);
	binaryNumber(num2, binNum2);

	bool binSum[length] = {};

	binarySum(binNum1, binNum2, binSum);
	
	return (decimalSum(binSum) == -9);
}

bool tests()
{
	return (test1() && test2() && test3());
}

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "Ошибка";
		return 0;
	}

	cout << "Введите два числа: ";
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;

	bool binaryA[length] = {};
	bool binaryB[length] = {};

	binaryNumber(a, binaryA);
	binaryNumber(b, binaryB);

	cout << "Двоичное представление числа " << a << ": ";
	coutArray(binaryA);

	cout << "Двоичное представление числа " << b << ": ";
	coutArray(binaryB);

	bool binSum[length] = {};

	binarySum(binaryA, binaryB, binSum);

	cout << "Сумма чисел в двоичной форме: ";
	coutArray(binSum);

	cout << "Сумма чисел в десятичной форме: " << decimalSum(binSum) << endl;
	
	return 0;
}