#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int getRouteDistance(const vector<vector<int>>& graph, vector<string> route, unordered_map<string, int>& cityIndex);
string getKeyFromValue(unordered_map<string, int>& myObj, int value);
unordered_map<string, int> mapCitiesWithIndex(vector<string>& allCities);