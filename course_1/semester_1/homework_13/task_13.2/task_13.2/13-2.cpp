#include <iostream>
#include <string>

using namespace std;

void readStateTableFromFile(int stateTable[3][4])
{
	FILE *table = fopen("table.txt", "r");
	char readingSymbol = 0;

	int i = 0;
	int j = 0;
	while (i < 3 && j < 4)
	{
		readingSymbol = fgetc(table);

		if (readingSymbol >= '0' && readingSymbol <= '9')
		{
			stateTable[i][j] = readingSymbol - '0';
			++j;
			if (j == 4)
			{
				++i;
				j = 0;
			}
		}
	}

	fclose(table);
}

void searchComments(FILE *textFile, int stateTable[3][4], string &comments)
{
	char symbol = 's';
	int state = 0;

	while (!feof(textFile))
	{
		symbol = fgetc(textFile);

		switch (symbol)
		{
			case '*':
			{
				state = stateTable[0][state];
				break;
			}

			case '/':
			{
				state = stateTable[1][state];
				break;
			}

			default:
			{
				state = stateTable[2][state];
			}
		}

		switch (state)
		{
			case 0:
			{
				if (symbol == '/')
				{
					comments += symbol;
				}
				break;
			}

			case 1:
			{
				break;
			}

			case 2:
			{
				if (symbol == '*')
				{
					comments += "/*";
				}
				else
				{
					comments += symbol;
				}

				break;
			}

			case 3:
			{
				comments += symbol;
				break;
			}
		}
	}
}

bool tests()
{
	int stateTable1[3][4];
	readStateTableFromFile(stateTable1);

	FILE *testFile = fopen("test.txt", "r");

	string comments;
	searchComments(testFile, stateTable1, comments);

	fclose(testFile);

	return comments == "/*we could*//*time***/";
}

int main()
{
	if (!tests())
	{
		cout << "Program error";
		return 0;
	}

	int stateTable[3][4];
	readStateTableFromFile(stateTable);

	FILE *textFile = fopen("text.txt", "r");
	if (textFile == nullptr)
	{
		cout << "File opening error";
		return 0;
	}

	string comments;
	searchComments(textFile, stateTable, comments);

	fclose(textFile);

	cout << comments << endl;

	return 0;
}