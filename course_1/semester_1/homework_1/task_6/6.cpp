#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "type the first string: ";
	string str1;
	getline (cin, str1);
	cout << "type the second string: ";
	string str2;
	getline(cin, str2);

	int result = 0;

	for (int i = 0; i <= str1.length() - str2.length(); i++)
	{
		int k = 0;
		while (k < str2.length())
		{
			if (str1[i+k] == str2[k])
			{
				k++;
			}
			else
			{
				break;
			}
		}
		if (k == str2.length())
		{
			result++;
		}
	}

	cout << "the second string appeared in the first string " << result << " times" << endl;

	return 0;
}