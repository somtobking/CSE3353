#include "recursivedfs.h"
#include <algorithm>

RecursiveDFS::RecursiveDFS()
{

}

RecursiveDFS::~RecursiveDFS()
{
//deconstructor
}

int RecursiveDFS::AdjacencyList(
        const vector<vector<int>>& adj_list,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source,int destination)
{
    parents.assign(adj_list.size(), -1);
    path_ex.assign(adj_list.size(), 0);
    nodes_explored = 0;
    isDestination = false;

    _AdjacencyList(adj_list, source, destination);

    return nodes_explored;
}

int RecursiveDFS::AdjacencyMatrix(
        const vector<vector<int>>& adj_matrix,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source,int destination)
{
    parents.assign(adj_matrix.size(), -1);
    path_ex.assign(adj_matrix.size(), 0);
    nodes_explored = 0;
    isDestination = false;

    _AdjacencyMatrix(adj_matrix, source, destination);

    return nodes_explored;
}

void RecursiveDFS::_AdjacencyList(const vector<vector<int>> &adj_list, int head, int destination)
{
    path_ex[head] = 1;
    if (!isDestination)
        nodes_explored++;
    if (head == destination)
        isDestination = true;
    if (isDestination)
        return;

    for (size_t i = 0; i < adj_list[head].size(); ++i)
    {
        int to = adj_list[head][i];
        if (path_ex[to] == 0)
        {
            parents[to] = head;
            _AdjacencyList(adj_list, to, destination);
        }
    }
}

void RecursiveDFS::_AdjacencyMatrix(const vector<vector<int>> &adj_matrix, int head, int destination)
{
    path_ex[head] = 1;
    if (!isDestination)
        nodes_explored++;
    if (head == destination)
        isDestination = true;
    if (isDestination)
        return;

    for (size_t i = 0; i < adj_matrix[head].size(); ++i)
    {
        int j = head;
        if (adj_matrix[head][i] == 1)
            j = i;

        if (path_ex[j] == 0)
        {
            parents[j] = head;
            _AdjacencyMatrix(adj_matrix, j, destination);
        }
    }
}

string RecursiveDFS::RecursiveDFS::GetName()
{
    return "Recursive DFS";
}

vector<int> RecursiveDFS::GetParents()
{
    return parents;
}
