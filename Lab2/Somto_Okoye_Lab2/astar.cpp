//sample code help obtained from https://rosettacode.org/wiki/A*_search_algorithm
#include "astar.h"

AStar::AStar()
{

}


AStar::~AStar()
{
//deconstructor
}

int AStar::AdjacencyList(
        const vector<vector<int>>& adj_list,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source, int destination)
{
    parents.assign(adj_list.size(), -1);

    vector<int> usedNode(adj_list.size(), 0);
    vector<double> head(adj_list.size(), numeric_limits<double>::max());
    vector<double> heuristic(adj_list.size(), numeric_limits<double>::max());
    int exploredNode = 0;

    usedNode[source] = 1;
    head[source] = 0;

    //heuristic =  F(n) = distance ( 1 + cost)
    heuristic[source] = numeric_limits<double>::max()-1;

    while(1)
    {
        int s = -1;
        for (size_t i = 0; i < adj_list.size(); ++i)
        {
            if (usedNode[i] == 1)
            {
                if (s == -1 || heuristic[i] < heuristic[s])
                    s = i;
            }
        }
        if (s == -1)
            break;
        if (s == destination)
            break;

        usedNode[s] = 2;

        exploredNode++;

        for (size_t i = 0; i < adj_list[s].size(); ++i)
        {
            int j = adj_list[s][i];
            double cost = weights[s][i];
            if (usedNode[j] == 2)
                continue;

            double temp = head[s] + cost;

            if (usedNode[j] != 1)
                usedNode[j] = 1;
            else if (temp >= head[j])
                continue;

            parents[j] = s;
            head[j] = temp;
            double distance = sqrt((positions[s][0]-positions[j][0]) * (positions[s][0]-positions[j][0])
                    + (positions[s][1]-positions[j][1]) * (positions[s][1]-positions[j][1])
                    + (positions[s][2]-positions[j][2]) * (positions[s][2]-positions[j][2]));

             //For A* only: execute using a heuristic that combines cost with distance
            heuristic[j] = head[j] + distance*(1 + cost);
        }
    }

    return exploredNode;
}

int AStar::AdjacencyMatrix(
        const vector<vector<int>>& adj_matrix,
        const vector<vector<double>> &weights,
        const vector<vector<double>> &positions,
        int source,int destination)
{
    parents.assign(adj_matrix.size(), -1);

    vector<int> usedNode(adj_matrix.size(), 0);
    vector<double> head(adj_matrix.size(), numeric_limits<double>::max());
    vector<double> heuristic(adj_matrix.size(), numeric_limits<double>::max());
    int exploredNode = 0;

    usedNode[source] = 1;
    head[source] = 0;
    //heuristic =  F(n) = distance ( 1 + cost)
    heuristic[source] = numeric_limits<double>::max()-1;

    while(1)
    {
        int s = -1;
        for (size_t i = 0; i < adj_matrix.size(); ++i)
        {
            if (usedNode[i] == 1)
            {
                if (s == -1 || heuristic[i] < heuristic[s])
                    s = i;
            }
        }
        if (s == -1)
            break;
        if (s == destination)
            break;

        usedNode[s] = 2;

        exploredNode++;

        for (size_t i = 0; i < adj_matrix[s].size(); ++i)
        {
            int j = s;
            if (adj_matrix[s][i] == 1)
                j = i;
            else
                continue;
            double cost = weights[s][j];

            if (usedNode[j] == 2)
                continue;

            double temp = head[s] + cost;

            if (usedNode[j] != 1)
                usedNode[j] = 1;
            else if (temp >= head[j])
                continue;

            parents[j] = s;
            head[j] = temp;
            double distance = sqrt((positions[s][0]-positions[j][0]) * (positions[s][0]-positions[j][0])
                    + (positions[s][1]-positions[j][1]) * (positions[s][1]-positions[j][1])
                    + (positions[s][2]-positions[j][2]) * (positions[s][2]-positions[j][2]));

            //For A* only: execute using a heuristic that combines cost with distance
            heuristic[j] = head[j] + distance *(1 + cost);
        }
    }

    return exploredNode;
}

string AStar::GetName()
{
    return "AStar(A*)";
}

vector<int> AStar::GetParents()
{
    return parents;
}
