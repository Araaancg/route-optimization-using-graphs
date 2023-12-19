#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int getRouteDistance(const vector<vector<int>>& graph, vector<string> route, unordered_map<string, int>& cityIndex) {
    int distance = 0;

    for (int i = 1; i < route.size(); i++) {
        int twoCitiesDist = graph[cityIndex[route[i]]][cityIndex[route[i - 1]]];
        distance += twoCitiesDist;
    };

    return distance;
};

//void printStack(stack<string> myStack) {
//    stack<string> copyStack = myStack;
//    while (!copyStack.empty()) {
//        cout << copyStack.top() << " ";
//        copyStack.pop();
//    };
//    cout << endl;
//};

string getKeyFromValue(unordered_map<string, int>& myObj, int value) {
    for (auto& [key, val] : myObj) {
        if (val == value) {
            return key;
        }
    }
    return "";
}

unordered_map<string, int> mapCitiesWithIndex(vector<string>& allCities) {
    unordered_map<string, int> cityIndex;

    for (int i = 0; i < allCities.size(); ++i) {
        cityIndex[allCities[i]] = i;
    }
    return cityIndex;
};