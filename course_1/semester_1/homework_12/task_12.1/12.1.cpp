#include <iostream>
#include <string>

using namespace std;

void prefixFunction(string string, int m, int prefixFunctionsArray[])
{
	int k = prefixFunctionsArray[m - 1];
	while (k > 0)
	{
		if (string[k] == string[m])
		{
			prefixFunctionsArray[m] = k + 1;
			break;
		}
		else
		{
			if (k == 0)
			{
				prefixFunctionsArray[m] = 0;
				break;
			}
			else
			{
				k = prefixFunctionsArray[k - 1];
			}
		}
	}
}

int kmp(string text, string string)
{
	int i = 0;
	int j = 0;

	int prefixFunctionsArray[100000];
	prefixFunctionsArray[0] = 0;
	for (int m = 0; m < string.length(); m++)
	{
		prefixFunction(string, m, prefixFunctionsArray);
	}

	while (i < text.length() && j < string.length())
	{
		if (text[i] == string[j])
		{
			++i;
			++j;
		} 
		else if (j == 0)
		{
			++i; 
		}
		else
		{
			j = prefixFunctionsArray[j - 1];
		}
	}

	if (j == string.length())
	{
		return (i - j);
	}
	return -1;
}

bool tests()
{
	FILE *fin = fopen("test.txt", "r");

	string text;
	while (!feof(fin))
	{
		char a = fgetc(fin);
		text = text + a;
	}

	fclose(fin);

	return (kmp(text, "you") == 10 && kmp(text, "line") == 34 && kmp(text, "till") == 14 && kmp(text, "me") == -1);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!tests())
	{
		cout << "ќшибка" << endl;
		return 0;
	}

	FILE *fin = fopen("file.txt", "r");
	if (fin == nullptr)
	{
		cout << "ќшибка при открытии файла" << endl;
		return 1;
	}

	string text;
	while (!feof(fin))
	{
		char a = fgetc(fin);
		text = text + a;
	}

	fclose(fin);

	cout << "¬ведите строку дл€ поиска: ";
	string string;
	getline(cin, string); 

	if (kmp(text, string) == -1)
	{
		cout << "¬хождений нет" << endl;
	}
	else
	{
		cout << kmp(text, string);
	}

	return 0;
}