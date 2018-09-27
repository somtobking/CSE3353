#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "searchimplementation.h"

using namespace std;

class Dijkstra : public SearchImplementation
{
public:
    Dijkstra();
    ~Dijkstra();

    int AdjacencyList(const vector<vector<int>>& adj_list,
            const vector<vector<double>> &weights,
            const vector<vector<double>> &positions,
            int source,
            int destination);

    int AdjacencyMatrix(
            const vector<vector<int>>& adj_matrix,
            const vector<vector<double>> &weights,
            const vector<vector<double>> &positions,
            int source,
            int destination);

    string GetName();
    vector<int> GetParents();
private:

    vector<int> parents;
};
#endif // DIJKSTRA_H
