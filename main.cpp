#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <sstream>

#include "./headers/extra-funcs.h"
#include "./headers/graph.h"
#include "./headers/classRoute.h"

using namespace std;

int main() {
    vector<string> cities = { "Madrid", "Ciudad Real", "Salamanca", "Jaén", "Cáceres", "Guadalajara", "Toledo", "Albacete" }; // all possible cities

    vector<Route> graph;
    loadRoutes(&graph);

    cout << graph[0].origin << endl;

    // USER SELECT CITIES
    displayMenu(cities, "POSSIBLE CITIES");

    int startCityIndex = validateUserInput(cities.size());

    string startCity = cities[startCityIndex - 1];

    cout << "origin: " << startCity << endl;

    int endCityIndex;
    do {
        endCityIndex = validateUserInput(cities.size());
        if (startCityIndex == endCityIndex) {
            cout << "Second city must be different from the first one";
        };
    } while (startCityIndex == endCityIndex);

    string endCity = cities[endCityIndex - 1];

    cout << "destination: " << endCity << endl;
    cout << endl;

    return 0;
};


