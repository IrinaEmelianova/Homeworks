#include <iostream>
#include <string>

using namespace std;

bool isRealNumber(const string &string)
{
	int state = 0;
	char symbol = '0';

	if (string.length() == 0)
	{
		return false;
	}

	for (int i = 0; i < string.length(); i++)
	{
		symbol = string[i];

		switch (state)
		{
			case 0:
			{
				if (symbol >= '0' && symbol <= '9')
				{
					state = 1;
				}
				else
				{
					return false;
				}

				break;
			}

			case 1:
			{
				if (symbol >= '0' && symbol <= '9')
				{
					state = 1;
				}
				else
				{
					if (symbol == '.')
					{
						state = 2;
					}
					else
					{
						return false;
					}
				}

				break;
			}

			case 2:
			{
				if (symbol >= '0' && symbol <= '9')
				{
					state = 3;
				}
				else
				{
					return false;
				}

				break;
			}

			case 3:
			{
				if (symbol >= '0' && symbol <= '9')
				{
					state = 3;
				}
				else
				{
					if (symbol == 'E')
					{
						state = 4;
					}
					else
					{
						return false;
					}
				}

				break;
			}

			case 4:
			{
				if (symbol == '+' || symbol == '-')
				{
					state = 5;
				}
				else
				{
					if (symbol >= '0' && symbol <= '9')
					{
						state = 6;
					}
					else
					{
						return false;
					}
				}

				break;
			}

			case 5:
			{
				if (symbol >= '0' && symbol <= '9')
				{
					state = 6;
				}
				else
				{
					return false;
				}

				break;
			}

			case 6:
			{
				if (symbol >= '0' && symbol <= '9')
				{
					state = 6;
				}
				else
				{
					return false;
				}

				break;
			}
		}
	}

	return state != 2 && state != 4 && state != 5;
}

bool tests()
{
	string s1 = "123.67";
	string s2 = "123.";
	string s3 = "12f3.gh";
	string s4 = "123.E78";
	string s5 = "123.45E+";
	string s6 = "123.45E-09";

	return isRealNumber(s1) && !isRealNumber(s2) && !isRealNumber(s3) && !isRealNumber(s4) && !isRealNumber(s5) && isRealNumber(s6);
}

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "������" << endl;
		return 0;
	}

	cout << "������� ��������� ��� �������: ";
	string string;
	getline(cin, string);
	
	if (isRealNumber(string))
	{
		cout << "��������� �������� ������������ ������" << endl;
	}
	else
	{
		cout << "��������� �� �������� ������������ ������" << endl;
	}

	return 0;
}