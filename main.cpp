#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

#include "dfs.h"
#include "bfs.h"
#include "extra-funcs.h"
#include "graph.h"

using namespace std;

int main() {    
    vector<string> cities = { "MAD", "CIU", "SAL", "JAE", "CAC", "GUA", "TOL", "ALB" };

    unordered_map<string, int> cityIndex = mapCitiesWithIndex(cities);
    vector<vector<int>> adjacencyMatrix = createGraph(cityIndex, cities.size());

    // Display the adjacency matrix
    /*cout << "adjacency matrix:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int distance : row) {
            cout << distance << "\t";
        }
        cout << endl;
    }*/

    displayMenu(cities, "POSSIBLE CITIES");
    int startCityIndex, endCityIndex;
    cout << "Enter the number of the starting city: ";
    cin >> startCityIndex;
    cout << "Enter the number of the destination city: ";
    cin >> endCityIndex;

    string startCity = cities[startCityIndex - 1];
    string endCity = cities[endCityIndex - 1];

    vector<string> routeDFS = DFS(cityIndex, adjacencyMatrix, startCity, endCity);

    for (int i = 0; i < routeDFS.size(); i++) {
        cout << routeDFS[i] << " ";
    }
    cout << endl;
    cout << "distance covered with DFS: " << getRouteDistance(adjacencyMatrix, routeDFS, cityIndex) << endl;

    vector<string> routeBFS = BFS(cityIndex, adjacencyMatrix, startCity, endCity);

    for (int i = 0; i < routeBFS.size(); i++) {
        cout << routeBFS[i] << " ";
    }
    cout << endl;
    cout << "distance covered with BFS: " << getRouteDistance(adjacencyMatrix, routeBFS, cityIndex) << endl;

    /*for (int i =0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            if (j == routes[i].size() - 1) {
                cout << routes[i][j];
            }
            else {
                cout << routes[i][j] << " -> ";
            }
        };
        cout << endl;
        cout << "distance covered: " << getRouteDistance(adjacencyMatrix, routes[i], cityIndex) << endl;
    };*/

    return 0;
}


