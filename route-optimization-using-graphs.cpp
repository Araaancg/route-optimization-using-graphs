#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

const int MAX_CITIES = 8;  // to determine size of vector

unordered_map<string, int> getCitiesNameIndex() {
    unordered_map<string, int> cityIndex;
    vector<string> cities = { "MAD", "CIU", "SAL", "TOL", "ALB", "JAE", "GUA", "CAC" };
    for (int i = 0; i < cities.size(); ++i) {
        cityIndex[cities[i]] = i;
    }
    return cityIndex;
};

vector<vector<int>> createGraph() {
    unordered_map<string, int> cityIndex = getCitiesNameIndex();
    

    vector<vector<int>> graph(MAX_CITIES, vector<int>(MAX_CITIES));

    graph[cityIndex["MAD"]][cityIndex["CIU"]] = 100;
    graph[cityIndex["CIU"]][cityIndex["MAD"]] = 100;

    graph[cityIndex["CIU"]][cityIndex["SAL"]] = 100;
    graph[cityIndex["SAL"]][cityIndex["CIU"]] = 100;

    graph[cityIndex["MAD"]][cityIndex["TOL"]] = 80;
    graph[cityIndex["TOL"]][cityIndex["MAD"]] = 80;

    graph[cityIndex["MAD"]][cityIndex["SAL"]] = 190;
    graph[cityIndex["SAL"]][cityIndex["MAD"]] = 190;

    graph[cityIndex["TOL"]][cityIndex["ALB"]] = 150;
    graph[cityIndex["ALB"]][cityIndex["TOL"]] = 150;

    graph[cityIndex["TOL"]][cityIndex["JAE"]] = 180;
    graph[cityIndex["JAE"]][cityIndex["TOL"]] = 180;

    graph[cityIndex["TOL"]][cityIndex["CIU"]] = 50;
    graph[cityIndex["CIU"]][cityIndex["TOL"]] = 50;

    graph[cityIndex["SAL"]][cityIndex["GUA"]] = 100;
    graph[cityIndex["GUA"]][cityIndex["SAL"]] = 100;

    graph[cityIndex["SAL"]][cityIndex["CAC"]] = 150;
    graph[cityIndex["CAC"]][cityIndex["SAL"]] = 150;

    graph[cityIndex["CAC"]][cityIndex["JAE"]] = 150;
    graph[cityIndex["JAE"]][cityIndex["CAC"]] = 150;

    graph[cityIndex["SAL"]][cityIndex["JAE"]] = 100;
    graph[cityIndex["JAE"]][cityIndex["SAL"]] = 100;
    return graph;
}

string getKeyFromValue(unordered_map<string, int> myMap, int value) {
    for (auto& [key, val] : myMap) {
        if (val == value) {
            return key;
        }
    }
    return "";
}

void printStack(stack<string> myStack) {
    stack<string> copyStack = myStack;
    while (!copyStack.empty()) {
        cout << copyStack.top() << " ";
        copyStack.pop();
    };
    cout << endl;
};

int getRouteDistance(const vector<vector<int>>& graph, vector<string> route) {
    unordered_map<string, int> cityIndex;
    cityIndex = getCitiesNameIndex();
    int distance = 0;

    for (int i = 1; i < route.size(); i++) {
        int twoCitiesDist = graph[cityIndex[route[i]]][cityIndex[route[i - 1]]];
        distance += twoCitiesDist;
    };

    return distance;
};


//vector<string> DFS(const vector<vector<int>>& graph, const string& origin, const string& destination) {
//
//    unordered_map<string, int> cityIndex;
//    cityIndex = getCitiesNameIndex();
//
//    unordered_set<string> visitedNodes;
//    stack<string> myStack;
//    vector<string> path;
//
//    myStack.push(origin);
//
//    while (!myStack.empty()) {
//         printStack(myStack);
//        string node = myStack.top();
//        myStack.pop();
//        if (visitedNodes.find(node) == visitedNodes.end()) {
//            visitedNodes.insert(node);
//            path.push_back(node);
//            for (int i = 0; i < graph[cityIndex[node]].size(); i++) {
//                if (graph[cityIndex[node]][i] != 0) {
//                    string adjacentNode = getKeyFromValue(cityIndex, i);
//                    if (adjacentNode == destination) {
//                        path.push_back(adjacentNode);
//                        return path;
//                    };
//                    myStack.push(adjacentNode);
//                };
//            };
//        };
//    };
//    return {};
//}

vector<vector<string>> DFS(unordered_map<string, int> cityIndex, const vector<vector<int>>& graph, const string& origin, const string& destination) {

    vector<vector<string>> paths;
    vector<string> path = { origin };
    stack<vector<string>> myStack;
    myStack.push(path);

    while (!myStack.empty()) {
        path = myStack.top();
        myStack.pop();
        string node = path.back();
        if (node == destination) {
            paths.push_back(path);
        }
        else {
            for (int i = 0; i < graph[cityIndex[node]].size(); i++) {
                if (graph[cityIndex[node]][i] != 0) {
                    string adjacentNode = getKeyFromValue(cityIndex, i);
                    if (find(path.begin(), path.end(), adjacentNode) == path.end()) {
                        vector<string> newPath = path;
                        newPath.push_back(adjacentNode);
                        myStack.push(newPath);
                    };
                };
            };
        };
    };
    return paths;
};


int main() {    
    vector<vector<int>> adjacencyMatrix = createGraph();

    // Display the adjacency matrix
    /*cout << "adjacency matrix:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int distance : row) {
            cout << distance << "\t";
        }
        cout << endl;
    }*/

    unordered_map<string, int> cityIndex;
    cityIndex = getCitiesNameIndex();

    string startCity = "SAL";
    string endCity = "MAD";


    vector<vector<string>> routes = DFS(cityIndex, adjacencyMatrix, startCity, endCity);

    for (int i =0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            if (j == routes[i].size() - 1) {
                cout << routes[i][j];
            }
            else {
                cout << routes[i][j] << " -> ";
            }
        };
        cout << endl;
        cout << "distance covered: " << getRouteDistance(adjacencyMatrix, routes[i]) << endl;
    };

    return 0;
}


