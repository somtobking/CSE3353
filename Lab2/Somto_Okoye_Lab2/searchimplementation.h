#ifndef SEARCHIMPLEMENTATION_H
#define SEARCHIMPLEMENTATION_H
#include <vector>
#include <string>

using namespace std;

//Search Implementation is an abstract class for search algo
class SearchImplementation
{
public:
    virtual ~SearchImplementation() {}

    // Search functions return the number of nodes explored
    virtual int AdjacencyList(
            const vector<vector<int>>& adj_list,
            const vector<vector<double>> &weights,
            const vector<vector<double>> &positions,
            int source,
            int destination) = 0;

    virtual int AdjacencyMatrix(
            const vector<vector<int>>& adj_matrix,
            const vector<vector<double>> &weights,
            const vector<vector<double>> &positions,
            int source,
            int destination) = 0;

    virtual string GetName() = 0;
    virtual vector<int> GetParents() = 0;
};


#endif // SEARCHIMPLEMENTATION_H
