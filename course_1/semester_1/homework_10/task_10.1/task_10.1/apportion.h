#pragma once
#include "graph.h"
#include <vector>

// apportion cities to countries
std::vector <int> *apportionToCountries(Graph *graph, int *capitals, int numberOfCapitals);

// print list of cities of every country
void printCountries(std::vector <int> *countries, int numberOfCapitals);
