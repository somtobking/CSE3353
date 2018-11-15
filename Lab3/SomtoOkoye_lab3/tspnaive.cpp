#include "tspnaive.h"
#include "algorithm.h"
#include "graph.h"

using namespace std;
Graph gra;

int TspNaive::travllingSalesmanProblem(double graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    std::array<int,V> temp = {};
    std::array<int,V> path = {};

    int min_path = INT8_MAX;
    do {

        int current_pathweight = 0;

        int k = s;
        temp[0] = k;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            temp[i] = k;
        }
        current_pathweight += graph[k][s];
        if(current_pathweight < min_path)
        {
            std::copy(std::begin(temp), std::end(temp), std::begin(path));
        }

        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    cout << "Path of Nodes(Naive): ";
    cout << s + 1 << "--->";
    for(int k = 0; k < V; ++k)
    {
        cout << path[k] + 1 << "--->";
    }
    cout << endl;
    cout << "Shortest Path(Naive): " ;
    return min_path;
}


int TspNaive::execute()
{

    auto startNaive = high_resolution_clock::now();
    gra.readDataFromFile();
    auto stopnaive = high_resolution_clock::now();
    auto durationNaive = duration_cast<microseconds>(stopnaive - startNaive);
    cout << "Naive Algorithm Execution Time : " << durationNaive.count()<<" miliseconds" << endl;
    cout << "*****************************" << endl;

    return 0;
}

void TspNaive::printAlgo()
{
    cout <<  "Travelling Salesman Brute Force (Naive)" << endl;
}
