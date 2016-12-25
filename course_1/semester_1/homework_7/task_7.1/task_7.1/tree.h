#pragma once

struct TreeElement;

// add new element in the tree
void add(TreeElement *&root, int value);

// delete element from the tree
void deleteElement(TreeElement *&root, int value);

// delete the tree
void deleteTree(TreeElement *&root);

// print all elements in ascending order
void printInAscendingOrder(TreeElement *root);

// print all elements in descending order
void printInDescendingOrder(TreeElement *root);

// check whether element contains in the tree or not
bool containsInTree(TreeElement *root, int searchingNumber);

// testing if program is working correctly
bool tests();