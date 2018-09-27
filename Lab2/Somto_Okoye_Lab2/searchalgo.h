#ifndef SEARCHALGO_H
#define SEARCHALGO_H

#include "algorithm.h"
#include "searchimplementation.h"

using namespace std;
#include <string>
#include <vector>

//SearchAlgo context inherits from the Strategy and overrides the base functionality of the searchImplementation abstract class
class SearchAlgo : public Algorithm
{
public:
    SearchAlgo();
    ~SearchAlgo();

    int Load(string filetype);
    void Execute(int source, int destination);
    void Stats();
    void Select(int searchId);
    void Display();
    void Save(string filename);

    //use a strcut to define the variables used in the execute function
    struct neighbor
    {
        vector<int> nodes_path;
        int nodes_explored;
        double cost, distance;
        long long total_time;

    };

    neighbor src_dest_list, src_dest_matrix, dest_src_list, dest_src_matrix;

private:
    SearchImplementation *implementation;
    int selected_Id;
    vector<vector<double>> weights;
    vector<vector<double>> positions;

    vector<pair<int, int>> ran_src_dest;
    vector<vector<int>> adj_list;
    vector<vector<int>> adj_matrix;
    void ComputePaths(neighbor& data, const vector<int> &parents, int source, int destination);
};
#endif // SEARCHALGO_H
