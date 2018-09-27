//Sample code help obtained from https://rosettacode.org/wiki/Dijkstra%27s_algorithm
#include "dijkstra.h"

#include <limits> // for numeric_limits

Dijkstra::Dijkstra()
{

}

Dijkstra::~Dijkstra()
{
    //deconstructor
}

int Dijkstra::AdjacencyList(
        const vector<vector<int>>& adj_list,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source, int destination)
{
    parents.assign(adj_list.size(), -1);

    vector<int> usedNode(adj_list.size(), 0);
    vector<double> cost(adj_list.size(), numeric_limits<double>::max());
    int exploredNode = 0;

    cost[source] = 0;
    for (size_t i = 0; i < adj_list.size(); ++i)
    {
        int s = -1;
        for (size_t j = 0; j < adj_list.size(); ++j)
        {
            if (usedNode[j] == 0 && (s == -1 || cost[j] < cost[s]))
                s = j;
        }
        if (cost[s] == numeric_limits<double>::max())
            break;
        usedNode[s] = 1;
        exploredNode++;

        for (size_t j = 0; j < adj_list[s].size(); ++j)
        {
            int to = adj_list[s][j];
            double weight = weights[s][j];
            if (cost[s] + weight < cost[to])
            {
                cost[to] = cost[s] + weight;
                parents[to] = s;
            }
        }
    }

    return exploredNode;
}

int Dijkstra::AdjacencyMatrix(const vector<vector<int>>& adj_matrix,
                              const vector<vector<double>> &weights,
                              const vector<vector<double>> &positions,
                              int source, int destination)
{
    parents.assign(adj_matrix.size(), -1);

    vector<int> usedNode(adj_matrix.size(), 0);
    vector<double> cost(adj_matrix.size(), numeric_limits<double>::max());
    int exploredNode = 0;

    cost[source] = 0;
    for (size_t i = 0; i < adj_matrix.size(); ++i)
    {
        int s = -1;
        for (size_t j = 0; j < adj_matrix.size(); ++j)
        {
            if (usedNode[j] == 0 && (s == -1 || cost[j] < cost[s]))
                s = j;
        }
        if (cost[s] == numeric_limits<double>::max())
            break;
        usedNode[s] = 1;
        exploredNode++;

        for (size_t j = 0; j < adj_matrix[s].size(); ++j)
        {
            int a = s;
            if (adj_matrix[s][j] == 1)
                a = j;
            else
                continue;
            double weight = weights[s][a];

            if (cost[s] + weight < cost[a])
            {
                cost[a] = cost[s] + weight;
                parents[a] = s;
            }
        }
    }

    return exploredNode;
}

string Dijkstra::GetName()
{
    return "Dijkstra";
}

vector<int> Dijkstra::GetParents()
{
    return parents;
}
