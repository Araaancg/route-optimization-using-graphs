#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> createGraph(unordered_map<string, int>& cityIndex, int vectorSize) {

    vector<vector<int>> graph(vectorSize, vector<int>(vectorSize));

    graph[cityIndex["MAD"]][cityIndex["CIU"]] = 100;
    graph[cityIndex["CIU"]][cityIndex["MAD"]] = 100;

    graph[cityIndex["CIU"]][cityIndex["SAL"]] = 100;
    graph[cityIndex["SAL"]][cityIndex["CIU"]] = 100;

    graph[cityIndex["MAD"]][cityIndex["TOL"]] = 80;
    graph[cityIndex["TOL"]][cityIndex["MAD"]] = 80;

    graph[cityIndex["MAD"]][cityIndex["SAL"]] = 190;
    graph[cityIndex["SAL"]][cityIndex["MAD"]] = 190;

    graph[cityIndex["TOL"]][cityIndex["ALB"]] = 150;
    graph[cityIndex["ALB"]][cityIndex["TOL"]] = 150;

    graph[cityIndex["TOL"]][cityIndex["JAE"]] = 180;
    graph[cityIndex["JAE"]][cityIndex["TOL"]] = 180;

    graph[cityIndex["TOL"]][cityIndex["CIU"]] = 50;
    graph[cityIndex["CIU"]][cityIndex["TOL"]] = 50;

    graph[cityIndex["SAL"]][cityIndex["GUA"]] = 100;
    graph[cityIndex["GUA"]][cityIndex["SAL"]] = 100;

    graph[cityIndex["SAL"]][cityIndex["CAC"]] = 150;
    graph[cityIndex["CAC"]][cityIndex["SAL"]] = 150;

    graph[cityIndex["CAC"]][cityIndex["JAE"]] = 150;
    graph[cityIndex["JAE"]][cityIndex["CAC"]] = 150;

    graph[cityIndex["SAL"]][cityIndex["JAE"]] = 100;
    graph[cityIndex["JAE"]][cityIndex["SAL"]] = 100;
    return graph;
}

