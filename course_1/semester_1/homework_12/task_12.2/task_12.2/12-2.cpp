#include <iostream>
#include "graph.h"

using namespace std;

bool test()
{
	Graph *test = createGraphFromFile("test.txt");

	int testArray[6][2] ={{0, 4}, {4, 5}, {0, 1}, {5, 3}, {3, 2}, {1, 6}};
	int **tree = findMinimumSpanningTree(test);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (tree[i][j] != testArray[i][j])
			{
				return false;
			}
		}
	}
	deleteGraph(test);
	for (int i = 0; i < 6; i++)
	{
		delete[] tree[i];
	}
	return true;
}

int main()
{
	if (!test())
	{
		cout << "Program error" << endl;
		return 0;
	}

	Graph *graph = createGraphFromFile("matrix.txt");

	printTree(findMinimumSpanningTree(graph), graph);

	deleteGraph(graph);

	return 0;
}