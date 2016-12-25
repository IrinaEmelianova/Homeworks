#include "graph.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Graph
{
	int numberOfCities;
	int **graphArray;
};

Graph *readGraphFromFile(ifstream &file, int numberOfCities, int numberOfRoads)
{
	Graph *graph = new Graph;

	graph->graphArray = new int *[numberOfCities];
	for (int i = 0; i < numberOfCities; i++)
	{
		graph->graphArray[i] = new int [numberOfCities];
		for (int j = 0; j < numberOfCities; j++)
		{
			graph->graphArray[i][j] = 0;
		}
	}

	int i = 0;
	int j = 0;
	int roadLength = 0;
	for (int l = 0; l < numberOfRoads; l++)
	{
		file >> i >> j >> roadLength;
		graph->graphArray[i][j] = roadLength;
		graph->graphArray[j][i] = roadLength;
	}

	graph->numberOfCities = numberOfCities;

	return graph;
}

void deleteGraph(Graph *&graph)
{
	for (int i = 0; i < graph->numberOfCities; i++)
	{
		delete[] graph->graphArray[i];
	}
}

int *readCapitalsFromFile(ifstream &file, int numberOfCapitals)
{
	int *capitals = new int[numberOfCapitals];
	for (int l = 0; l < numberOfCapitals; l++)
	{
		file >> capitals[l];
	}

	return capitals;
}

int graphNumberOfCities(Graph *graph)
{
	return graph->numberOfCities;
}

int **graphsArray(Graph *graph)
{
	return graph->graphArray;
}