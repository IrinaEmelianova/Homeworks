#pragma once
#include <string>

struct Graph;

// read graph matrix from file
Graph *createGraphFromFile(const std::string &fileName);

// find minimum spanning tree
int **findMinimumSpanningTree(Graph *graph);

// print minimum spanning tree
void printTree(int **minimumSpanningTree, Graph *graph);

// delete graph
void deleteGraph(Graph *&graph);