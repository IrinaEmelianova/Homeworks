#pragma once
#include <string>

struct Record;

// read phonebook from file
void readFromFile(Record *&phonebook, const std::string &fileName);

// count number of records in phonebook
int phonebookLength(Record *phonebook);

// add new record in the end of phonebook list
void addInEnd(Record *&phonebook, const std::string &phone, const std::string &name);

// delete the first record from phonebook list
void deleteRecord(Record *&phonebook);

// delete the phonebook
void deletePhonebook(Record *&phonebook);

// print all records
void print(Record *phonebook);

// return name from record
std::string recordsName(Record *record);

// return phone from record
std::string recordsPhone(Record *record);

// return next record
Record *&recordsNext(Record *record);