#include <iostream>

using namespace std;

int main()
{
	cout << "type 2 numbers:";
	int dividend;
	int divider;
	cin >> dividend >> divider;

	int quotient = 0;

	while (abs(dividend) >= abs(divider * quotient))
	{
		if (dividend * divider > 0)
		{
			quotient++;
		}
		else
		{
			quotient--;
		}
	}

	cout << "quotient: ";
	if (dividend < 0)
	{
		cout << quotient;
	}
	else
	{
		if (divider > 0)
		{
			cout << quotient - 1;
		}
		else
		{
			cout << quotient + 1;
		}
	}

	return 0;
}