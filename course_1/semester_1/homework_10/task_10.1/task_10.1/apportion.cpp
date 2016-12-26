#include "apportion.h"
#include <iostream>
#include <vector>

using namespace std;

bool *createVisitedCitiesArray(int numberOfCities)
{
	bool *visitedCities = new bool[numberOfCities];
	for (int i = 0; i < numberOfCities; i++)
	{
		visitedCities[i] = false;
	}
	return visitedCities;
}

bool everyCityIsVisited(bool *visitedCities, int numberOfCities)
{
	for (int i = 0; i < numberOfCities; i++)
	{
		if (!visitedCities[i])
		{
			return false;
		}
	}
	return true;
}

bool isInCountry(vector <int> country, int city)
{
	for (int i = 0; i < country.size(); i++)
	{
		if (country[i] == city)
		{
			return true;
		}
	}

	return false;
}

void addNewCity(vector <int> &country, Graph *graph, bool *visitedCities)
{
	int minRoadLength = 0;

	int numberOfCities = graphNumberOfCities(graph);
	int **graphArray = graphsArray(graph);

	int newCity = 0;
	for (int i = 0; i < numberOfCities; i++)
	{
		for (int j = 0; j < numberOfCities; j++)
		{
			if (isInCountry(country, i) && !visitedCities[j] && graphArray[i][j] != 0 && (minRoadLength == 0 || graphArray[i][j] < minRoadLength))
			{
				minRoadLength = graphArray[i][j];
				newCity = j;
			}
		}
	}
	
	if (minRoadLength != 0)
	{
		visitedCities[newCity] = true;
		country.push_back(newCity);
	}
}

vector <int> *apportionToCountries(Graph *graph, int *capitals, int numberOfCapitals)
{
	bool *visitedCities = createVisitedCitiesArray(graphNumberOfCities(graph));
	for (int i = 0; i < numberOfCapitals; i++)
	{
		visitedCities[capitals[i]] = true;
	}

	vector <int> *countries = new vector <int>[numberOfCapitals];
	for (int i = 0; i < numberOfCapitals; i++)
	{
		countries[i].push_back(capitals[i]);
	}

	while (!everyCityIsVisited(visitedCities, graphNumberOfCities(graph)))
	{
		for (int i = 0; i < numberOfCapitals; i++)
		{
			addNewCity(countries[i], graph, visitedCities);
		}
	}

	delete[] visitedCities;

	return countries;
}

void printCountries(vector <int> *countries,  int numberOfCapitals)
{
	for (int i = 0; i < numberOfCapitals; i++)
	{
		cout << i + 1 << " country: ";
		for (int j = 0; j < countries[i].size(); j++)
		{
			cout << countries[i][j] << " ";
		}
		cout << endl;
	}
}