#include <iostream>

using namespace std;

struct StackElement
{
	int value;
	StackElement *next;
};

void push(StackElement *&head, int newValue);
void pop(StackElement *&head);
void print(StackElement *head);
bool isEmpty(StackElement *head);
void deleteStack(StackElement *&head);
