#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

#include "extra-funcs.h"

using namespace std;

vector<string> BFS(unordered_map<string, int>& cityIndex, const vector<vector<int>>& graph, const string& origin, const string& destination) {
    
    vector<string> path;
    queue<string> myQueue;
    unordered_set<string> visitedNodes;
    myQueue.push(origin);

    while (!myQueue.empty()) {
        string node = myQueue.front();
        myQueue.pop();

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
                    myQueue.push(adjacentNode);
                };
            };
        };
    };
    return {};
}
