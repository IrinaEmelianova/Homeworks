#include <iostream>

using namespace std;

int recursiveFibonacci(int numb)
{
	if (numb == 0 || numb == 1)
	{
		return 1;
	}
	else
	{
		return recursiveFibonacci(numb - 1) + recursiveFibonacci(numb - 2);
	}
}

int iterativeFibonacci(int number)
{
	int first = 1;
	int second = 1;
	int fibonacci = 0;

	for (int i = 2; i <= number; i++)
	{
		fibonacci = first + second;
		first = second;
		second = fibonacci;
	}

	if (number == 0 || number == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci;
	}
}

int main()
{
	cout << "type a number: ";
	int numb = 0;
	cin >> numb;

	cout << numb << " Fibonacci number is " << recursiveFibonacci(numb) << endl << endl;
	
	cout << "type a number: ";
	int number = 0;
	cin >> number;
	
	cout << number << " Fibonacci number is " << iterativeFibonacci(number) << endl;

	return 0;
}