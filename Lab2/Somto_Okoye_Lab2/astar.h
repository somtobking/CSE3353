#ifndef ASTAR_H
#define ASTAR_H

#include "searchimplementation.h"

#include <vector>
#include <string>
#include <limits>
#include <math.h>

using namespace std;

class AStar : public SearchImplementation
{
public:
    AStar();
    ~AStar();

    int AdjacencyList(
            const vector<vector<int>>& adj_list,
            const vector<vector<double>> &weights,
            const vector<vector<double>> &positions,
            int source,
            int destination);

    int AdjacencyMatrix(
            const vector<vector<int>>& adj_matrix ,
            const vector<vector<double>> &weights,
            const vector<vector<double>> &positions,
            int source,
            int destination);

    string GetName();
    vector<int> GetParents();

private:

    std::vector<int> parents;
};


#endif // ASTAR_H
