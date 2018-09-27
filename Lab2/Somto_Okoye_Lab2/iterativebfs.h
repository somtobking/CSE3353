#ifndef ITERATIVEBFS_H
#define ITERATIVEBFS_H

#include "searchimplementation.h"

using namespace std;


class IterativeBFS : public SearchImplementation
{
public:
    IterativeBFS();
    ~IterativeBFS();

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
#endif // ITERATIVEBFS_H
