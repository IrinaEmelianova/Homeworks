#include <string>

using namespace std;

struct Record
{
	string name;
	string phone;
};

void addRecord(Record phonebook[], int &numberOfRecords);
void printAllRecords(Record phonebook[], int numberOfRecords);
bool stringsAreEqual(string firstString, string secondString);
void searchPhone(Record phonebook[], int numberOfRecords);
void searchName(Record phonebook[], int numberOfRecords);
void saveInFile(Record phonebook[], int numberOfRecords);
void readFromFile(Record phonebook[], int &numberOfRecords, string name);