#pragma once
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> DFS(unordered_map<string, int>& cityIndex, const vector<vector<int>>& graph, const string& origin, const string& destination);