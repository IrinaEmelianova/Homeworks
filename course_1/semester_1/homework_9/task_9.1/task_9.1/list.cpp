#include "list.h"
#include <iostream>
#include <string>

using namespace std;

struct ListElement
{
	string value;
	int numberOfRepetitions;
	ListElement *next;
};

void addToHead(ListElement *&head, const string &value)
{
	auto newListElement = new ListElement;
	newListElement->value = value;
	newListElement->numberOfRepetitions = 1;
	newListElement->next = head;
	head = newListElement;
}

void deleteFromHead(ListElement *&head)
{
	ListElement *oldHead = head;
	head = head->next;
	delete oldHead;
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		deleteFromHead(head);
	}
}

void printList(ListElement *head)
{
	while (head != nullptr)
	{
		cout << head->value << " " << head->numberOfRepetitions << endl;
		head = head->next;
	}
}

ListElement *searchListElement(ListElement *head, const string &value)
{
	while (head != nullptr && head->value != value)
	{
		head = head->next;
	}

	return head;
}

int numberOfListElements(ListElement *head)
{
	int numberOfListElements = 0;

	while (head != nullptr)
	{
		++numberOfListElements;
		head = head->next;
	}

	return numberOfListElements;
}

void increaseElementsNumberOfRepetitions(ListElement *element)
{
	++element->numberOfRepetitions;
}