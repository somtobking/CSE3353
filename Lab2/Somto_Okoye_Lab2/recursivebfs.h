#ifndef RECURSIVEBFS_H
#define RECURSIVEBFS_H
#include <queue>

#include "searchimplementation.h"

using namespace std;

class RecursiveBFS : public SearchImplementation
{
public:
    RecursiveBFS();
    ~RecursiveBFS();

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
    void _AdjacencyList(const vector<vector<int>> &adj_list, int destination);
    void _AdjacencyMatrix(const vector<vector<int>> &adj_matrix, int destination);

    queue<int> order;
    vector<int> path_ex;
    vector<int> parents;
    int nodes_explored;
    bool isDestination;


};

#endif // RECURSIVEBFS_H
