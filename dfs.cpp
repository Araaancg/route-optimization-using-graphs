#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

#include "./headers/extra-funcs.h"

using namespace std;

vector<string> DFS(unordered_map<string, int>& cityIndex, const vector<vector<int>>& graph, const string& origin, const string& destination) {

    unordered_set<string> visitedNodes;
    stack<string> myStack;
    vector<string> path;

    myStack.push(origin);

    while (!myStack.empty()) {
        string node = myStack.top();
        myStack.pop();
        if (visitedNodes.find(node) == visitedNodes.end()) {
            visitedNodes.insert(node);
            path.push_back(node);
            for (int i = 0; i < graph[cityIndex[node]].size(); i++) {
                if (graph[cityIndex[node]][i] != 0) {
                    string adjacentNode = getKeyFromValue(cityIndex, i);
                    if (adjacentNode == destination) {
                        path.push_back(adjacentNode);
                        return path;
                    };
                    myStack.push(adjacentNode);
                };
            };
        };
    };
    return {};
}