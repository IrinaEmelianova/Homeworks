#include <iostream>
#include <string>

using namespace std;

struct ListElement
{
	string value;
	int numberOfRepetitions;
	ListElement *next;
};

void addToHead(ListElement *&head, string value);
void deleteFromHead(ListElement *&head);
void deleteList(ListElement *&head);

void printList(ListElement *head);

ListElement *searchListElement(ListElement *head, string value);
int numberOfListElements(ListElement *head);