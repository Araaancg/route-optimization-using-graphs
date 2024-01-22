#pragma once

#include <iostream>

using namespace std;

class Route {
public:
	string origin;
	string destination;
	int distance;

	Route(std::string o, std::string d, int dist) {
		origin = o;
		destination = d;
		distance = dist;
	};
};