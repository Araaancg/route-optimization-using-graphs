#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

#include "./headers/dfs.h"
#include "./headers/extra-funcs.h"
#include "./headers/graph.h"

using namespace std;

int main() {    
    vector<string> cities = { "MAD", "CIU", "SAL", "TOL", "ALB", "JAE", "GUA", "CAC" };

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

    string startCity = "MAD";
    string endCity = "GUA";


    vector<string> route = DFS(cityIndex, adjacencyMatrix, startCity, endCity);

    for (int i = 0; i < route.size(); i++) {
        cout << route[i] << " "; 
    }
    cout << endl;
    cout << "distance covered: " << getRouteDistance(adjacencyMatrix, route, cityIndex) << endl;

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


