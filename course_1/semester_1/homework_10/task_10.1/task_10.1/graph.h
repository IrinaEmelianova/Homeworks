#pragma once
#include <fstream>

struct Graph;

// read cities and roads from file
Graph *readGraphFromFile(std::ifstream &file, int numberOfCities, int numberOfRoads);

// read capitals from file
int *readCapitalsFromFile(std::ifstream &file, int numberOfCapitals);

// return graph's number of cities
int graphNumberOfCities(Graph *graph);

// return graph's array of roads
int **graphsArray(Graph *graph);

// delete graph
void deleteGraph(Graph *&graph);