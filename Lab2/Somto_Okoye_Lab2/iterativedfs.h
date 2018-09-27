#ifndef ITERATIVEDFS_H
#define ITERATIVEDFS_H

using namespace std;
#include "searchimplementation.h"

class IterativeDFS :  public SearchImplementation
{
public:
    IterativeDFS();
    ~IterativeDFS();

    int AdjacencyList(
            const vector<vector<int>>& adj_list,
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
#endif // ITERATIVEDFS_H
