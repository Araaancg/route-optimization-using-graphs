#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <unordered_map>

using namespace std;

const int MAX_CITIES = 10;  // to determine size of vector

// function to create an adjacency matrix for the given cities and distances
vector<vector<int>> createGraph() {
    // map city names to unique indices
    unordered_map<string, int> cityIndex;

    vector<string> cities = { "Madrid", "Guadalajara", "Toledo", "Caceres", "Ciudad Real", "Jaen", "Salamanca", "Albacete" };

    // initialize the adjacency matrix with all distances set to 0 -> no connection between cities
    vector<vector<int>> graph(MAX_CITIES, vector<int>(MAX_CITIES));

    // Assign unique indices to cities
    for (int i = 0; i < cities.size(); ++i) {
        cityIndex[cities[i]] = i;
    }

    // Add distances to the adjacency matrix
    graph[cityIndex["Madrid"]][cityIndex["Ciudad Real"]] = 100;
    graph[cityIndex["Ciudad Real"]][cityIndex["Madrid"]] = 100;

    graph[cityIndex["Ciudad Real"]][cityIndex["Salamanca"]] = 100;
    graph[cityIndex["Salamanca"]][cityIndex["Ciudad Real"]] = 100;

    graph[cityIndex["Madrid"]][cityIndex["Toledo"]] = 80;
    graph[cityIndex["Toledo"]][cityIndex["Madrid"]] = 80;

    graph[cityIndex["Madrid"]][cityIndex["Salamanca"]] = 190;
    graph[cityIndex["Salamanca"]][cityIndex["Madrid"]] = 190;

    graph[cityIndex["Toledo"]][cityIndex["Albacete"]] = 150;
    graph[cityIndex["Albacete"]][cityIndex["Toledo"]] = 150;

    graph[cityIndex["Toledo"]][cityIndex["Jaén"]] = 180;
    graph[cityIndex["Jaén"]][cityIndex["Toledo"]] = 180;

    graph[cityIndex["Toledo"]][cityIndex["Ciudad Real"]] = 50;
    graph[cityIndex["Ciudad Real"]][cityIndex["Toledo"]] = 50;

    graph[cityIndex["Salamanca"]][cityIndex["Guadalajara"]] = 100;
    graph[cityIndex["Guadalajara"]][cityIndex["Salamanca"]] = 100;

    graph[cityIndex["Salamanca"]][cityIndex["Caceres"]] = 150;
    graph[cityIndex["Caceres"]][cityIndex["Salamanca"]] = 150;

    graph[cityIndex["Caceres"]][cityIndex["Jaen"]] = 150;
    graph[cityIndex["Jaén"]][cityIndex["Caceres"]] = 150;

    graph[cityIndex["Salamanca"]][cityIndex["Jaen"]] = 100;
    graph[cityIndex["Jaen"]][cityIndex["Salamanca"]] = 100;

    return graph;
}

vector<tuple<string, list<string>>> DFS(const vector<vector<int>>& graph, const string& startCity, const string& endCity) {
    vector<tuple<string, list<string>>> route;

    vector<pair<string, vector<string>>> stack;
    stack.push_back({ startCity, {startCity} });

    cout << "Stack: ";
    for (const auto& entry : stack) {
        cout << "(" << entry.first << ", [";
        for (const string& city : entry.second) {
            cout << city;
        }
        cout << "]) ";
    }
    cout << "\n";

    return route;
}

int main() {    
    vector<vector<int>> adjacencyMatrix = createGraph();

    // Display the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int distance : row) {
            cout << distance << "\t";
        }
        cout << endl;
    }

    string startCity = "Madrid";
    string endCity = "Caceres";

    DFS(adjacencyMatrix, startCity, endCity);



    return 0;
}


