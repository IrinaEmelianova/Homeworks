#include <iostream>
#include <fstream>
#include "graph.h"
#include "apportion.h"

using namespace std;

bool test()
{
	ifstream file("test.txt");

	int numberOfCities = 0;
	int numberOfRoads = 0;
	file >> numberOfCities >> numberOfRoads;
	Graph *graph = readGraphFromFile(file, numberOfCities, numberOfRoads);

	int numberOfCapitals = 0;
	file >> numberOfCapitals;
	int *capitals = readCapitalsFromFile(file, numberOfCapitals);

	file.close();

	vector <int> *countries = apportionToCountries(graph, capitals, numberOfCapitals);

	deleteGraph(graph);
	delete[] capitals;

	int testArray1[6] = {2, 5, 1, 8, 9, 7};
	int testArray2[2] = {4, 3};
	int testArray3[2] = {6, 0};

	for (int i = 0; i < countries[0].size(); i++)
	{
		if (countries[0][i] != testArray1[i])
		{
			return false;
		}
	}

	for (int i = 0; i < countries[1].size(); i++)
	{
		if (countries[1][i] != testArray2[i])
		{
			return false;
		}
	}

	for (int i = 0; i < countries[2].size(); i++)
	{
		if (countries[2][i] != testArray3[i])
		{
			return false;
		}
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

	ifstream file("file.txt");

	int numberOfCities = 0;
	int numberOfRoads = 0;
	file >> numberOfCities >> numberOfRoads;
	Graph *graph = readGraphFromFile(file, numberOfCities, numberOfRoads);

	int numberOfCapitals = 0;
	file >> numberOfCapitals;
	int *capitals = readCapitalsFromFile(file, numberOfCapitals);

	file.close();

	vector <int> *countries = apportionToCountries(graph, capitals, numberOfCapitals);
	printCountries(countries, numberOfCapitals);

	deleteGraph(graph);
	delete[] capitals;

	return 0;
}