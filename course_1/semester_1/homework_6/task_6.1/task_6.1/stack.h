#pragma once

struct StackElement;

// add new element in stack
void push(StackElement *&head, int newValue);

// remove element from stack
void pop(StackElement *&head);

// print all elements
void print(StackElement *head);

// checking whether stack is empty or not
bool isEmpty(StackElement *head);

// delete all elements
void deleteStack(StackElement *&head);

// get value of the stack head
int headValue(StackElement *head);
