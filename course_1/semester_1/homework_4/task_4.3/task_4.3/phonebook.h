#pragma once
#include <string>

const std::string fileName;

struct Record
{
	string name;
	string phone;
};

// add new record in the phonebook
void addRecord(Record phonebook[], int &numberOfRecords);

// print all records from the phonebook
void printAllRecords(Record phonebook[], int numberOfRecords);

// search phone number by the name of owner
void searchPhone(Record phonebook[], int numberOfRecords);

// search name of owner by phone number
void searchName(Record phonebook[], int numberOfRecords);

// save current phonebook in file
void saveInFile(Record phonebook[], int numberOfRecords);

// read records from file
void readFromFile(Record phonebook[], int &numberOfRecords, const string &fileName);
