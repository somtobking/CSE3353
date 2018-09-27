#include "iterativedfs.h"

#include <stack>
#include <algorithm>

IterativeDFS::IterativeDFS()
{

}

IterativeDFS::~IterativeDFS()
{
//deconstructor
}

int IterativeDFS::AdjacencyList(
        const vector<vector<int>>& adj_list,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source, int destination)
{
    parents.assign(adj_list.size(), -1);
    vector<int> path_ex(adj_list.size(), 0);
    int exploredNode = 0;

    //DFS uses stack
    stack<int> order;
    order= stack<int>();
    order.push(source);
    while(!order.empty())
    {
        exploredNode++;

        int s = order.top();
        order.pop();

        if (s == destination)
            break;
        path_ex[s] = 1;

        for (size_t i = 0; i < adj_list[s].size(); ++i)
        {
            int to = adj_list[s][i];
            if (path_ex[to] == 0)
            {
                parents[to] = s;
                order.push(to);
            }
        }
    }

    return exploredNode;
}

int IterativeDFS::AdjacencyMatrix(
        const vector<vector<int>>& adj_matrix,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source, int destination)
{
    parents.assign(adj_matrix.size(), -1);
    vector<int> path_ex(adj_matrix.size(), 0);
    int exploredNode = 0;

    stack<int> order;
    order= stack<int>();
    order.push(source);
    while(!order.empty())
    {
        exploredNode++;

        int s = order.top();
        order.pop();

        if (s == destination)
            break;
        path_ex[s] = 1;

        for (size_t i = 0; i < adj_matrix[s].size(); ++i)
        {
            int j = source;
            if (adj_matrix[s][i] == 1)
                j = i;
            if (path_ex[j] == 0)
            {
                parents[j] = s;
                order.push(j);
            }
        }
    }

    return exploredNode;
}

string IterativeDFS::GetName()
{
    return "Iterative DFS";
}

vector<int> IterativeDFS::GetParents()
{
    return parents;
}
