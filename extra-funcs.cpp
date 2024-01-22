#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

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