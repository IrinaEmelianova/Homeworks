#include <iostream>
#include "stack.h"

using namespace std;

void push(StackElement *&head, char newValue)
{
	auto newStackElement = new StackElement;
	newStackElement -> value = newValue;
	newStackElement -> next = head;
	head = newStackElement;
}

void pop(StackElement *&head)
{
	StackElement *oldHead = head;
	head = head -> next;
	delete oldHead;
}

void print(StackElement *head)
{
	while (head != nullptr)
	{
		cout << head -> value << endl;
		head = head -> next;
	}
}

bool isEmpty(StackElement *head)
{
	if (head == nullptr) return true;
	else return false;
}

void deleteStack(StackElement *&head)
{
	while (!isEmpty(head))
	{
		pop(head);
	}
}

