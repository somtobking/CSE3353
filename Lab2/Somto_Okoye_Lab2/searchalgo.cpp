#include "searchalgo.h"
#include "astar.h"
#include "dijkstra.h"
#include "iterativebfs.h"
#include "recursivebfs.h"
#include "iterativedfs.h"
#include "recursivedfs.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

SearchAlgo::SearchAlgo() : selected_Id(0), implementation(nullptr)
{

}

SearchAlgo::~SearchAlgo()
{
    //deconstructor
    if(implementation)
        delete implementation;
}

int SearchAlgo::Load(string filetype)
{
    adj_list.clear();
    adj_matrix.clear();
    weights.clear();
    positions.clear();

    // Read the sample graph file
    ifstream graph_file;
    graph_file.open("graph" + filetype);
    string line;
    while (getline(graph_file, line))
    {
        istringstream line_stream(line);
        string temp;
        getline(line_stream, temp, ',');
        int node = stoi(temp);

        while(getline(line_stream, temp, ','))
        {
            int child = stoi(temp);

            int max_id = max(node, child);
            if (max_id > adj_list.size())
            {
                adj_list.resize(max_id);
                adj_matrix.resize(max_id, vector<int>(max_id, 0));
                for (size_t i = 0; i < adj_matrix.size(); ++i)
                    adj_matrix[i].resize(max_id, 0);
            }

            adj_list[node-1].push_back(child-1); // -1 because program indexes start at 0
            adj_matrix[node-1][child-1] = 1;
        }
    }

    weights.assign(adj_list.size(), vector<double>(adj_list.size(), 0));
    positions.assign(adj_list.size(), {0, 0, 0});

    // read the weights file from sample graph
    ifstream weights_file;
    weights_file.open("weights" + filetype);
    while (getline(weights_file, line))
    {
        istringstream line_stream(line);
        string temp;
        //read in the file by line
        getline(line_stream, temp, ',');
        //convert to integer
        int node = stoi(temp);
        getline(line_stream, temp, ',');
        int child = stoi(temp);
        getline(line_stream, temp, ',');
        double weight = stod(temp);

        weights[node-1][child-1] = weight;
    }

    //read positions file from sample graph
    ifstream positions_file;
    positions_file.open("positions" + filetype);
    while (getline(positions_file, line))
    {
        istringstream line_stream(line);
        string temp;

        getline(line_stream, temp, ',');
        int node = stoi(temp);
        getline(line_stream, temp, ',');
        double x = stod(temp);
        getline(line_stream, temp, ',');
        double y = stod(temp);
        getline(line_stream, temp, ',');
        double z = stod(temp);

        positions[node-1] = {x, y, z};
    }

    for (int i = 0; i < 100; ++i)
        ran_src_dest.push_back(make_pair(rand()%adj_list.size(), rand()%adj_list.size()));
    return adj_list.size();
}

void SearchAlgo::Execute(int source, int destination)
{
    if (!implementation)
        return;

    source--;
    destination--;

    //collect execution time
    using namespace chrono;
    {
        high_resolution_clock::time_point t1 = high_resolution_clock::now(); // start time
        src_dest_list.nodes_explored = implementation->AdjacencyList(adj_list, weights, positions, source, destination);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); //end time
        auto elapsed = duration_cast<microseconds>(t2-t1);
        src_dest_list.total_time = elapsed.count() + 1;

        vector<int> parents_list = implementation->GetParents();
        ComputePaths(src_dest_list, parents_list, source, destination);

        t1 = high_resolution_clock::now();
        src_dest_matrix.nodes_explored = implementation->AdjacencyMatrix(adj_matrix, weights, positions, source, destination);
        t2 = high_resolution_clock::now();
        elapsed = duration_cast<microseconds>(t2-t1);
        src_dest_matrix.total_time = elapsed.count() + 1;

        vector<int> parents_matrix = implementation->GetParents();
        ComputePaths(src_dest_matrix, parents_matrix, source, destination);
    }
    {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();  // start time
        dest_src_list.nodes_explored = implementation->AdjacencyList(adj_list, weights, positions, source, destination);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();  // end time
        auto elapsed = duration_cast<microseconds>(t2-t1);
        dest_src_list.total_time = elapsed.count() + 1;

        vector<int> parents_list = implementation->GetParents();
        ComputePaths(dest_src_list, parents_list, source, destination);

        t1 = high_resolution_clock::now();
        dest_src_matrix.nodes_explored = implementation->AdjacencyMatrix(adj_matrix, weights, positions, source, destination);
        t2 = high_resolution_clock::now();
        elapsed = duration_cast<microseconds>(t2-t1);
        dest_src_matrix.total_time = elapsed.count() + 1;

        vector<int> parents_matrix = implementation->GetParents();
        ComputePaths(dest_src_matrix, parents_matrix, source, destination);
    }

}

void SearchAlgo::Display()
{
    //intnetionally left blank
}

void SearchAlgo::Stats()
{
    cout << "******************************************************" << endl;
    const neighbor& data = src_dest_list;
    cout << "\n";
    cout << implementation->GetName() << " | Source --> Destination | Adjancency list" << endl;
    cout << "Returned Path: ";

    for (size_t i = 0; i < data.nodes_path.size(); ++i)

        cout << data.nodes_path[i]+1 << " ";
    cout << "\nNumber of nodes in returned path: " << data.nodes_path.size() << endl;
    cout << "Cost of the path: " << data.cost << endl;
    cout << "Total Distance of path: " << data.distance << endl;
    cout << "Number of nodes explored in path: " << data.nodes_explored << endl;
    cout << "Execution time to find path: " << data.total_time << "nsec" << endl;
    cout << "\n";

}

void SearchAlgo::Select(int searchId)
{
    delete implementation;
    selected_Id = searchId;
    //switch between the search algos
    switch (selected_Id)
    {
    case 1:
        implementation = new IterativeDFS;
        break;
    case 2:
        implementation = new RecursiveDFS ;
        break;
    case 3:
        implementation = new IterativeBFS ;
        break;
    case 4:
        implementation = new RecursiveBFS;
        break;
    case 5:
        implementation = new Dijkstra;
        break;
    case 6:
        implementation = new AStar;
        break;
    default:
        implementation = nullptr;
        break;
    }
}

void SearchAlgo::Save(string filename)
{
    //intentionally left blank

}

void SearchAlgo::ComputePaths(SearchAlgo::neighbor &data, const vector<int> &parents, int source, int destination)
{
    // calculated the path out of array of parents given source and destination
    data.nodes_path.clear();
    data.nodes_path.push_back(destination);
    for (int i = parents[destination]; i != source; i = parents[i])
    {
        //no path exists
        data.nodes_path.push_back(i);
        if (i == -1)
        {
            data.nodes_path.clear();
            break;
        }
    }
    //add the source to vector data
    data.nodes_path.push_back(source);
    reverse(data.nodes_path.begin(), data.nodes_path.end());

    data.cost = 0;
    for (size_t i = 0; i < data.nodes_path.size()-1; ++i)
        data.cost += weights[data.nodes_path[i]][data.nodes_path[i+1]];
    data.distance = 0;
    for (size_t i = 0; i < data.nodes_path.size()-1; ++i)
    {
        int v = i, to = i + 1;
        double distance = sqrt((positions[v][0]-positions[to][0]) * (positions[v][0]-positions[to][0])
                + (positions[v][1]-positions[to][1]) * (positions[v][1]-positions[to][1])
                + (positions[v][2]-positions[to][2]) * (positions[v][2]-positions[to][2]));
        data.distance += distance;
    }
}
