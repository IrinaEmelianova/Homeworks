#pragma once
#include <string>

struct ListElement;

// add element to the head of the list
void addToHead(ListElement *&head, const std::string &value);

// delete all elements from list
void deleteList(ListElement *&head);

// print all elements
void printList(ListElement *head);

// search element in the list and return it's position
ListElement *searchListElement(ListElement *head, const std::string &value);

// count number of elements in the list
int numberOfListElements(ListElement *head);

// increase element's numberOfRepetitions by one
void increaseElementsNumberOfRepetitions(ListElement *element);
