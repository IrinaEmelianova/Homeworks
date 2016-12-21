#pragma once
#include <string>

struct TreeElement;

// read expression from file
void readFromFile(std::string &expression);

// build the tree based on the expression
void buildTree(TreeElement *&root, const std::string &expression, int &i);

// delete the tree
void deleteTree(TreeElement *&root);

// print the tree
void print(TreeElement *root);

// count the value of the parse tree
int countResult(TreeElement *root);