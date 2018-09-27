#include "recursivebfs.h"

#include <algorithm>

RecursiveBFS::RecursiveBFS()
{

}

RecursiveBFS::~RecursiveBFS()
{
//deconstructor
}

int RecursiveBFS::AdjacencyList(
        const vector<vector<int>>& adj_list,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source, int destination)
{
    order = queue<int>();
    parents.assign(adj_list.size(), -1);
    path_ex.assign(adj_list.size(), 0);
    nodes_explored = 0;
    isDestination = false;

    order.push(source);
    _AdjacencyList(adj_list, destination);

    return nodes_explored;
}

int RecursiveBFS::AdjacencyMatrix(
        const vector<vector<int>>& adj_matrix,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source, int destination)
{
    //BFS uses queue
    order = queue<int>();
    parents.assign(adj_matrix.size(), -1);
    path_ex.assign(adj_matrix.size(), 0);
    nodes_explored = 0;
    isDestination = false;

    order.push(source);
    _AdjacencyMatrix(adj_matrix, destination);

    return nodes_explored;
}


void RecursiveBFS::_AdjacencyList(const vector<vector<int>> &adj_list, int destination)
{
    if (order.empty())
        return;

    int s = order.front();
    order.pop();

    if (!isDestination)
        nodes_explored++;
    if (s == destination)
        isDestination = true;
    if (isDestination)
        return;

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
    _AdjacencyList(adj_list, destination);
}

void RecursiveBFS::_AdjacencyMatrix(const vector<vector<int>> &adj_matrix, int destination)
{
    if (order.empty())
        return;

    int s = order.front();
    order.pop();

    if (!isDestination)
        nodes_explored++;
    if (s == destination)
        isDestination = true;
    if (isDestination)
        return;
    path_ex[s] = 1;

    for (size_t i = 0; i < adj_matrix[s].size(); ++i)
    {
        int j = s;
        if (adj_matrix[s][i] == 1)
            j = i;
        if (path_ex[j] == 0)
        {
            parents[j] = s;
            order.push(j);
        }
    }
    _AdjacencyMatrix(adj_matrix, destination);
}

string RecursiveBFS::GetName()
{
    return "Recursive BFS";
}

vector<int> RecursiveBFS::GetParents()
{
    return parents;
}
