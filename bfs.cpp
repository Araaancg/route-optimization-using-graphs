#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

#include "extra-funcs.h"

using namespace std;

vector<string> BFS(unordered_map<string, int>& cityIndex, const vector<vector<int>>& graph, const string& origin, const string& destination) {
    vector<string> path;
    queue<vector<string>> myQueue;
    unordered_set<string> visitedNodes;
    vector<string> startPath = { origin };
    myQueue.push(startPath);
    visitedNodes.insert(origin);

    while (!myQueue.empty()) {
        vector<string> path = myQueue.front();
        myQueue.pop();
        string node = path.back();
        if (node == destination) {
            return path;
        }
        else {
            for (int i = 0; i < graph[cityIndex[node]].size(); i++) {
                if (graph[cityIndex[node]][i] != 0) {
                    string adjacentNode = getKeyFromValue(cityIndex, i);
                    if (visitedNodes.find(adjacentNode) == visitedNodes.end()) {
                        visitedNodes.insert(adjacentNode);
                        vector<string> newPath = path;
                        newPath.push_back(adjacentNode);
                        myQueue.push(newPath);
                    };
                };
            };
        };
    };
    return {};
}
