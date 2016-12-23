#include "stack.h"
#include <iostream>

using namespace std;

struct StackElement
{
	int value;
	StackElement *next;
};

void push(StackElement *&head, int newValue)
{
	auto newStackElement = new StackElement;
	newStackElement->value = newValue;
	newStackElement->next = head;
	head = newStackElement;
}

void pop(StackElement *&head)
{
	StackElement *oldHead = head;
	head = head->next;
	delete oldHead;
}

void print(StackElement *head)
{
	while (head != nullptr)
	{
		cout << head->value << endl;
		head = head->next;
	}
}

bool isEmpty(StackElement *head)
{
	return head == nullptr;
}

void deleteStack(StackElement *&head)
{
	while (!isEmpty(head))
	{
		pop(head);
	}
}

int headValue(StackElement *head)
{
	if (head != nullptr)
	{
		return head->value;
	}
}