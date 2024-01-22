#include <iostream>
#include <vector>
#include "./headers/classRoute.h"

using namespace std;

void loadRoutes(vector<Route>* routes) {	
    routes->push_back(Route("Madrid", "Ciudad Real", 100));
    routes->push_back(Route("Ciudad Real", "Salamanca", 100));
    routes->push_back(Route("Madrid", "Toledo", 80));
    routes->push_back(Route("Madrid", "Salamanca", 190));
    routes->push_back(Route("Toledo", "Albacete", 150));
    routes->push_back(Route("Toledo", "Ciudad Real", 50));
    routes->push_back(Route("Salamanca", "Guadalajara", 100));
    routes->push_back(Route("Salamanca", "C�ceres", 150));
    routes->push_back(Route("C�ceres", "Ja�n", 150));
    routes->push_back(Route("Salamanca", "Ja�n", 100));
};

