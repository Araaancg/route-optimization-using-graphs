#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>


using namespace std;

int getRouteDistance(const vector<vector<int>>& graph, vector<string> route, unordered_map<string, int>& cityIndex) {
    int distance = 0;

    for (int i = 1; i < route.size(); i++) {
        int twoCitiesDist = graph[cityIndex[route[i]]][cityIndex[route[i - 1]]];
        distance += twoCitiesDist;
    };

    return distance;
};

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

void displayMenu(const vector<string>& cities, string title) {
    cout << title << ": " << endl;
    for (int i = 0; i < cities.size(); i++) {
        std::cout << i + 1 << ". " << cities[i] << endl;
    }
}

int validateUserInput(int menuLength) {
    string userInput;
    bool valid = false;

    while (!valid) {
        cout << "> ";
        cin >> userInput;

        istringstream iss(userInput); // Try to convert the input to an integer
        int option;
        if (iss >> option) {
            if (option >= 1 && option <= menuLength) { // Check if the input is a number within the valid range
                return option;
            }
            else {
                std::cout << "Invalid input. Please enter a number between 1 and " << menuLength << "." << endl;
            }
        }
        else {
            std::cout << "Invalid input. Please enter a number." << endl;
        };
    };
};
