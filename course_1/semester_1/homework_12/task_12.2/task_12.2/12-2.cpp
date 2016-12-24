#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool *createVisitedVerticesArray(int numberOfVertices)
{
	bool *visitedVertices = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
	{
		visitedVertices[i] = false;
	}
	return visitedVertices;
}

int **createMinimumSpanningTreeArray(int numberOfVertices)
{
	int **minimumSpanningTree = new int *[numberOfVertices - 1];
	for (int i = 0; i < numberOfVertices - 1; i++)
	{
		minimumSpanningTree[i] = new int [2];
		for (int j = 0; j < 2; j++)
		{
			minimumSpanningTree[i][j] = 0;
		}
	}
	return minimumSpanningTree;
}

void addInMinimumSpanningTree(int **minimumSpanningTree, int first, int second, int numberOfVertices)
{
	for (int i = 0; i < numberOfVertices - 1; i++)
	{
		if (minimumSpanningTree[i][0] == 0 && minimumSpanningTree[i][1] == 0)
		{
			minimumSpanningTree[i][0] = first;
			minimumSpanningTree[i][1] = second;
			return;
		}
	}
}

bool everyVerticeIsVisited(bool *visitedVertices, int numberOfVertices)
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (!visitedVertices[i])
		{
			return false;
		}
	}
	return true;
}

void searchMinimumSpanningTree(int vertice, int **graph, bool *visitedVertices, int **minimumSpanningTree, int numberOfVertices)
{
	visitedVertices[vertice] = true;

	int minEdgeLength = 0;
	int first = 0;
	int second = 0;

	for (int i = 0; i < numberOfVertices; i++)
	{
		for (int j = 0; j < numberOfVertices; j++)
		{
			if (visitedVertices[i] && !visitedVertices[j] && graph[i][j] != 0 && (minEdgeLength == 0 || graph[i][j] < minEdgeLength))
			{
				minEdgeLength = graph[i][j];
				first = i;
				second = j;
			}
		}
	}

	addInMinimumSpanningTree(minimumSpanningTree, first, second, numberOfVertices);

	if (!everyVerticeIsVisited(visitedVertices, numberOfVertices)) 
	{
		searchMinimumSpanningTree(second, graph, visitedVertices, minimumSpanningTree, numberOfVertices);
	}
}

void printTree(int **minimumSpanningTree, int numberOfVertices)
{
	cout<< "minimum spanning tree by pairs of edge's vertices:" << endl;

	for (int i = 0; i < numberOfVertices - 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << minimumSpanningTree[i][j] << " ";
		}
		cout << endl;
	}
}

bool test()
{
	ifstream testFile("test.txt");
	int numberOfVertices = 0;
	testFile >> numberOfVertices;

	int **graph = new int*[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
	{
		graph[i] = new int [numberOfVertices];
		for (int j = 0; j < numberOfVertices; j++)
		{
			testFile >> graph[i][j];
		}
	}

	testFile.close();

	bool *visitedVertices = createVisitedVerticesArray(numberOfVertices);
	int **minimumSpanningTree = createMinimumSpanningTreeArray(numberOfVertices);

	searchMinimumSpanningTree(0, graph, visitedVertices, minimumSpanningTree, numberOfVertices);

	int testArray[6][2] ={{0, 4}, {4, 5}, {0, 1}, {5, 3}, {3, 2}, {1, 6}};
	
	bool returning = true;
	for (int i = 0; i < numberOfVertices - 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (minimumSpanningTree[i][j] != testArray[i][j])
			{
				returning = false;
			}
		}
	}

	delete graph;
	delete visitedVertices;
	delete minimumSpanningTree;

	return returning;
}

int main()
{
	if (!test())
	{
		cout << "Program error" << endl;
		return 0;
	}

	ifstream file("matrix.txt");
	if (!file.is_open())
	{
		cout << "File opening error" << endl;
		return 0;
	}

	int numberOfVertices = 0;
	file >> numberOfVertices;

	int **graph = new int*[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
	{
		graph[i] = new int [numberOfVertices];
		for (int j = 0; j < numberOfVertices; j++)
		{
			file >> graph[i][j];
		}
	}

	file.close();

	bool *visitedVertices = createVisitedVerticesArray(numberOfVertices);
	int **minimumSpanningTree = createMinimumSpanningTreeArray(numberOfVertices);

	searchMinimumSpanningTree(0, graph, visitedVertices, minimumSpanningTree, numberOfVertices);

	printTree(minimumSpanningTree, numberOfVertices);

	delete graph;
	delete visitedVertices;
	delete minimumSpanningTree;

	return 0;
}