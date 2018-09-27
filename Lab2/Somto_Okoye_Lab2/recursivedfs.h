#ifndef RECURSIVEDFS_H
#define RECURSIVEDFS_H
#include <stack>

#include "searchimplementation.h"
using namespace std;

class RecursiveDFS : public SearchImplementation
{
public:
    RecursiveDFS();
    ~RecursiveDFS();

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
    void _AdjacencyList(const vector<vector<int>> &adj_list, int current, int destination);
    void _AdjacencyMatrix(const vector<vector<int>> &adj_matrix, int current, int destination);

    stack<int> order;
    vector<int> path_ex;
    vector<int> parents;
    int nodes_explored;
    bool isDestination;
};

#endif // RECURSIVEDFS_H
