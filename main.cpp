#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <sstream>

#include "./headers/dfs.h"
#include "./headers/bfs.h"
#include "./headers/extra-funcs.h"
#include "./headers/graph.h"

using namespace std;

int main() {    
    vector<string> cities = { "MAD", "CIU", "SAL", "JAE", "CAC", "GUA", "TOL", "ALB" }; // all possible cities

    unordered_map<string, int> cityIndex = mapCitiesWithIndex(cities);
    vector<vector<int>> adjacencyMatrix = createGraph(cityIndex, cities.size());

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
    // CONFIRM IF THERE IS A DIRECT ROUTE
    if (adjacencyMatrix[cityIndex[startCity]][cityIndex[endCity]] > 0) {
        // if there is a direct route we finish the programm
        cout << startCity << " " << endCity << endl;
        cout << "distance covered: " << adjacencyMatrix[cityIndex[startCity]][cityIndex[endCity]] << endl;

        return 0;
    }
    else { // if there isn't a direct route with use dfs and bfs
        // APPLY DEEP FIRST SEARCH
        vector<string> routeDFS = DFS(cityIndex, adjacencyMatrix, startCity, endCity);

        for (int i = 0; i < routeDFS.size(); i++) {
            cout << routeDFS[i] << " ";
        }
        cout << endl;
        cout << "distance covered with DFS: " << getRouteDistance(adjacencyMatrix, routeDFS, cityIndex) << endl;

        cout << endl;

        // APPLY BREADTH FIRST SEARCH
        vector<string> routeBFS = BFS(cityIndex, adjacencyMatrix, startCity, endCity);

        for (int i = 0; i < routeBFS.size(); i++) {
            cout << routeBFS[i] << " ";
        }
        cout << endl;
        cout << "distance covered with BFS: " << getRouteDistance(adjacencyMatrix, routeBFS, cityIndex) << endl;

        return 0;

    };

}


