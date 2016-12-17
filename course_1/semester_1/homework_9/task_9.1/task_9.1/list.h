#include <string>

using std::string;

struct ListElement
{
	string value;
	int numberOfRepetitions;
	ListElement *next;
};

// add element to the head of the list
void addToHead(ListElement *&head, string value);

// delete all elements from list
void deleteList(ListElement *&head);

// print all elements
void printList(ListElement *head);

// search element in the list and return it's position
ListElement *searchListElement(ListElement *head, string value);

// count number of elements in the list
int numberOfListElements(ListElement *head);