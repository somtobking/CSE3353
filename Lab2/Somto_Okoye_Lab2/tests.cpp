////sample test case code obtained from https://rosettacode.org/wiki/A*_search_algorithm

////#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//#include "searchalgo.h"
//#include "astar.h"
//#include "dijkstra.h"
//#include "iterativebfs.h"
//#include "recursivebfs.h"
//#include "iterativedfs.h"
//#include "recursivedfs.h"
//#include <iostream>
//#include <cstring>
//#include <string>
//#include <fstream>


//using namespace std;

////Tests is a class that runs the tests needed for the report, comment after use to run main
//int main(int argc, char *argv[])
//{
//    int source, destination;

//    const int N = 100;
//    const int num_of_implemt = 6;
//    int sd_adjacency_list[N][8][8];
//    int sd_adjacency_matrix[N][8][8];
//    int ds_adjacency_list[N][8][8];
//    int ds_adjacency_matrix[N][8][8];
//    double sd_adjacency_list_norm[N][8][8];
//    double sd_adjacency_matrix_norm[N][8][8];
//    double ds_adjacency_list_norm[N][8][8];
//    double ds_adjacency_matrix_norm[N][8][8];

//    //declare the max values for normalizing the collected data
//    int max_values[N][5];
//    srand(time(0));

//    for (int n = 0; n <= N; n++)
//    {
//        if (argc == 3)
//        {
//            source = stoi(string(argv[1]));
//            destination = stoi(string(argv[2]));

//            SearchAlgo Search;
//            int N = Search.Load(".txt");

//            if (n < 0)
//            {
//                source = 1;
//                destination = 2;
//            }
//            else
//            {
//                source = destination = 1 + rand() / (RAND_MAX / N);
//                while (source == destination)
//                {
//                    destination = 1 + rand() / (RAND_MAX / N);
//                }
//            }

//            //loop through the algorithm
//            for (int i = 1; i <= num_of_implemt; ++i)
//            {
//                Search.Select(i);
//                Search.Execute(source, destination);
//                Search.Save(to_string(i));
//                Search.Stats();
//                cout << "\n";

//                // Collect stats on the Adjacency List and Matrix
//                // Source -> Destination, Adjacency List
//                sd_adjacency_list[n][0][i - 1] = Search.src_dest_list.nodes_path.size(); // nodes in path
//                sd_adjacency_list[n][1][i - 1] = Search.src_dest_list.nodes_explored; // nodes explored
//                sd_adjacency_list[n][2][i - 1] = Search.src_dest_list.cost; // cost
//                sd_adjacency_list[n][3][i - 1] = Search.src_dest_list.distance; // distance
//                sd_adjacency_list[n][4][i - 1] = Search.src_dest_list.total_time; // execution time


//                // Source -> Destination, Adjacency Matrix
//                sd_adjacency_matrix[n][0][i - 1] = Search.src_dest_matrix.nodes_path.size();
//                sd_adjacency_matrix[n][1][i - 1] = Search.src_dest_matrix.nodes_explored;
//                sd_adjacency_matrix[n][2][i - 1] = Search.src_dest_matrix.cost;
//                sd_adjacency_matrix[n][3][i - 1] = Search.src_dest_matrix.distance;
//                sd_adjacency_matrix[n][4][i - 1] = Search.src_dest_matrix.total_time;

//                // Destination -> Source, Adjacency List
//                ds_adjacency_list[n][0][i - 1] = Search.dest_src_list.nodes_path.size();
//                ds_adjacency_list[n][1][i - 1] = Search.dest_src_list.nodes_explored;
//                ds_adjacency_list[n][2][i - 1] = Search.dest_src_list.cost;
//                ds_adjacency_list[n][3][i - 1] = Search.dest_src_list.distance;
//                ds_adjacency_list[n][4][i - 1] = Search.dest_src_list.total_time;

//                // Destination -> Source, Adjacency Matrix
//                ds_adjacency_matrix[n][0][i - 1] = Search.dest_src_matrix.nodes_path.size();
//                ds_adjacency_matrix[n][1][i - 1] = Search.dest_src_matrix.nodes_explored;
//                ds_adjacency_matrix[n][2][i - 1] = Search.dest_src_matrix.cost;
//                ds_adjacency_matrix[n][3][i - 1] = Search.dest_src_matrix.distance;
//                ds_adjacency_matrix[n][4][i - 1] = Search.dest_src_matrix.total_time;

//            }

//            // Collect maximum values
//            // Returned Path
//            max_values[n][0] = *max_element(sd_adjacency_matrix[n][0], sd_adjacency_matrix[n][0] + 6);
//            max_values[n][0] = max(max_values[n][0], *max_element(sd_adjacency_list[n][0], sd_adjacency_list[n][0] + 6));
//            max_values[n][0] = max(max_values[n][0], *max_element(ds_adjacency_matrix[n][0], ds_adjacency_matrix[n][0] + 6));
//            max_values[n][0] = max(max_values[n][0], *max_element(ds_adjacency_list[n][0], ds_adjacency_list[n][0] + 6));

//            // Nodes Explored
//            max_values[n][1] = *max_element(sd_adjacency_matrix[n][1], sd_adjacency_matrix[n][1] + 6);
//            max_values[n][1] = max(max_values[n][1], *max_element(sd_adjacency_list[n][1], sd_adjacency_list[n][1] + 6));
//            max_values[n][1] = max(max_values[n][1], *max_element(ds_adjacency_matrix[n][1], ds_adjacency_matrix[n][1] + 6));
//            max_values[n][1] = max(max_values[n][1], *max_element(ds_adjacency_list[n][1], ds_adjacency_list[n][1] + 6));

//            // Total Cost
//            max_values[n][2] = *max_element(sd_adjacency_matrix[n][2], sd_adjacency_matrix[n][2] + 6);
//            max_values[n][2] = max(max_values[n][2], *max_element(sd_adjacency_list[n][2], sd_adjacency_list[n][2] + 6));
//            max_values[n][2] = max(max_values[n][2], *max_element(ds_adjacency_matrix[n][2], ds_adjacency_matrix[n][2] + 6));
//            max_values[n][2] = max(max_values[n][2], *max_element(ds_adjacency_list[n][2], ds_adjacency_list[n][2] + 6));

//            // Total Distance
//            max_values[n][3] = *max_element(sd_adjacency_matrix[n][3], sd_adjacency_matrix[n][3] + 6);
//            max_values[n][3] = max(max_values[n][3], *max_element(sd_adjacency_list[n][3], sd_adjacency_list[n][3] + 6));
//            max_values[n][3] = max(max_values[n][3], *max_element(ds_adjacency_matrix[n][3], ds_adjacency_matrix[n][3] + 6));
//            max_values[n][3] = max(max_values[n][3], *max_element(ds_adjacency_list[n][3], ds_adjacency_list[n][3] + 6));

//            // Execution Time
//            max_values[n][4] = *max_element(sd_adjacency_matrix[n][4], sd_adjacency_matrix[n][4] + 6);
//            max_values[n][4] = max(max_values[n][4], *max_element(sd_adjacency_list[n][4], sd_adjacency_list[n][4] + 6));
//            max_values[n][4] = max(max_values[n][4], *max_element(ds_adjacency_matrix[n][4], ds_adjacency_matrix[n][4] + 6));
//            max_values[n][4] = max(max_values[n][4], *max_element(ds_adjacency_list[n][4], ds_adjacency_list[n][4] + 6));

//            // store normalized stats
//            for (int j = 0; j < 5; j++)
//            {
//                for (int i = 0; i < num_of_implemt; i++)
//                {
//                    sd_adjacency_list_norm[n][j][i] = (double)sd_adjacency_list[n][j][i] / max_values[n][j];
//                    sd_adjacency_matrix_norm[n][j][i] = (double)sd_adjacency_matrix[n][j][i] / max_values[n][j];
//                    ds_adjacency_list_norm[n][j][i] = (double)ds_adjacency_list[n][j][i] / max_values[n][j];
//                    ds_adjacency_matrix_norm[n][j][i] = (double)ds_adjacency_matrix[n][j][i] / max_values[n][j];
//                }
//            }

//        }
//        else
//        {
//            //no command line input
//            cout << "Error: Source and Destination Nodes not found" << endl;
//        }

//    }

//    //save test data
//    ofstream raw_data;
//    ofstream norm_data;
//    raw_data.open("Raw data Tests.txt");
//    raw_data << "Raw data Output\n";

//    norm_data.open("Normalized Raw data Tests.txt");
//    norm_data << "Normalized Raw data Output\n";

//    for (int n = 0; n < N; n++)
//    {
//        raw_data << "\nTest #" << n + 1 << endl;
//        raw_data << "\nAdjacency Matrix, Source -> Destination\n";
//        raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        norm_data << "\nTest #" << n + 1 << endl;
//        norm_data << "\nAdjacency Matrix, Source -> Destination\n";
//        norm_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        for (int j = 0; j < 5; j++)
//        {
//            if (j == 0) {
//                raw_data << "Returned Path\t";
//                norm_data << "Returned Path\t";
//            }
//            else if (j == 1) {
//                raw_data << "Nodes Explored\t";
//                norm_data << "Nodes Explored\t";
//            }
//            else if (j == 2) {
//                raw_data << "Total Cost\t";
//                norm_data << "Total Cost\t";
//            }
//            else if (j == 3) {
//                raw_data << "Total Distance\t";
//                norm_data << "Total Distance\t";
//            }
//            else if (j == 4) {
//                raw_data << "Execution Time\t";
//                norm_data << "Execution Time\t";
//            }

//            for (int i = 0; i < num_of_implemt; i++)
//            {
//                raw_data << "\t" << sd_adjacency_matrix[n][j][i];
//                norm_data << "\t" << sd_adjacency_matrix_norm[n][j][i];
//            }
//            raw_data << "\n";
//            norm_data << "\n";
//        }

//        raw_data << "\nAdjacency List, Source -> Destination\n";
//        raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        norm_data << "\nAdjacency List, Source -> Destination\n";
//        norm_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        for (int j = 0; j < 5; j++)
//        {
//            if (j == 0) {
//                raw_data << "Returned Path\t";
//                norm_data << "Returned Path\t";
//            }
//            else if (j == 1) {
//                raw_data << "Nodes Explored\t";
//                norm_data << "Nodes Explored\t";
//            }
//            else if (j == 2) {
//                raw_data << "Total Cost\t";
//                norm_data << "Total Cost\t";
//            }
//            else if (j == 3) {
//                raw_data << "Total Distance\t";
//                norm_data << "Total Distance\t";
//            }
//            else if (j == 4) {
//                raw_data << "Execution Time\t";
//                norm_data << "Execution Time\t";
//            }
//            for (int i = 0; i < num_of_implemt; i++)
//            {
//                raw_data << "\t" << sd_adjacency_list[n][j][i];
//                norm_data << "\t" << sd_adjacency_list_norm[n][j][i];
//            }
//            raw_data << "\n";
//            norm_data << "\n";
//        }

//        raw_data << "\nAdjacency List, Source -> Destination\n";
//        raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        norm_data << "\nAdjacency List, Source -> Destination\n";
//        norm_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        for (int j = 0; j < 5; j++)
//        {
//            if (j == 0) {
//                raw_data << "Returned Path\t";
//                norm_data << "Returned Path\t";
//            }
//            else if (j == 1) {
//                raw_data << "Nodes Explored\t";
//                norm_data << "Nodes Explored\t";
//            }
//            else if (j == 2) {
//                raw_data << "Total Cost\t";
//                norm_data << "Total Cost\t";
//            }
//            else if (j == 3) {
//                raw_data << "Total Distance\t";
//                norm_data << "Total Distance\t";
//            }
//            else if (j == 4) {
//                raw_data << "Execution Time\t";
//                norm_data << "Execution Time\t";
//            }
//            for (int i = 0; i < num_of_implemt; i++)
//            {
//                raw_data << "\t" << ds_adjacency_matrix[n][j][i];
//                norm_data << "\t" << ds_adjacency_matrix_norm[n][j][i];
//            }
//            raw_data << "\n";
//            norm_data << "\n";
//        }

//        raw_data << "\nAdjacency List, Source -> Destination\n";
//        raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//        norm_data << "\nAdjacency List, Source -> Destination\n";
//        norm_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";


//        for (int j = 0; j < 5; j++)
//        {
//            if (j == 0) {
//                raw_data << "Returned Path\t";
//                norm_data << "Returned Path\t";
//            }
//            else if (j == 1) {
//                raw_data << "Nodes Explored\t";
//                norm_data << "Nodes Explored\t";
//            }
//            else if (j == 2) {
//                raw_data << "Total Cost\t";
//                norm_data << "Total Cost\t";
//            }
//            else if (j == 3) {
//                raw_data << "Total Distance\t";
//                norm_data << "Total Distance\t";
//            }
//            else if (j == 4) {
//                raw_data << "Execution Time\t";
//                norm_data << "Execution Time\t";
//            }
//            for (int i = 0; i < num_of_implemt; i++)
//            {
//                raw_data << "\t" << ds_adjacency_list[n][j][i];
//                norm_data << "\t" << ds_adjacency_list_norm[n][j][i];
//            }
//            raw_data << "\n";
//            norm_data << "\n";
//        }


//    }
//    raw_data.close();
//    norm_data.close();

//    // average the collected normalized results
//    double sd_adjacency_matrix_aver[8][8];
//    double sd_adjacency_list_aver[8][8];
//    double ds_adjacency_matrix_aver[8][8];
//    double ds_adjacency_list_aver[8][8];

//    for (int n = 0; n < N; n++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            for (int i = 0; i < num_of_implemt; i++)
//            {
//                sd_adjacency_matrix_aver[j][i] += sd_adjacency_matrix_norm[n][j][i] / N;
//                sd_adjacency_list_aver[j][i] += sd_adjacency_list_norm[n][j][i] / N;
//                ds_adjacency_matrix_aver[j][i] += ds_adjacency_matrix_norm[n][j][i] / N;
//                ds_adjacency_list_aver[j][i] += ds_adjacency_list_norm[n][j][i] / N;
//            }
//        }
//    }

//    // print to file normalized raw_data
//    raw_data.open("Average Normalized Data.txt");
//    raw_data << "Average Normalized Data Output\n";

//    raw_data << "******************************************************" << endl;
//    raw_data << "\nAdjacency List, Source -> Destination\n";
//    raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*"<< endl;

//    for (int j = 0; j < 5; j++)
//    {
//        if (j == 0) {
//            raw_data << "Returned Path\t";
//            norm_data << "Returned Path\t";
//        }
//        else if (j == 1) {
//            raw_data << "Nodes Explored\t";
//            norm_data << "Nodes Explored\t";
//        }
//        else if (j == 2) {
//            raw_data << "Total Cost\t";
//            norm_data << "Total Cost\t";
//        }
//        else if (j == 3) {
//            raw_data << "Total Distance\t";
//            norm_data << "Total Distance\t";
//        }
//        else if (j == 4) {
//            raw_data << "Execution Time\t";
//            norm_data << "Execution Time\t";
//        }
//        for (int i = 0; i < num_of_implemt; i++)
//        {
//            //get average normalized
//            raw_data << "\t" << sd_adjacency_list_aver[j][i];
//        }
//        raw_data << "\n";
//    }

//    raw_data << "******************************************************" << endl;
//    raw_data << "\nAdjacency Matrix, Source -> Destination\n";
//    raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//    for (int j = 0; j < 5; j++)
//    {
//        if (j == 0) {
//            raw_data << "Returned Path\t";
//            norm_data << "Returned Path\t";
//        }
//        else if (j == 1) {
//            raw_data << "Nodes Explored\t";
//            norm_data << "Nodes Explored\t";
//        }
//        else if (j == 2) {
//            raw_data << "Total Cost\t";
//            norm_data << "Total Cost\t";
//        }
//        else if (j == 3) {
//            raw_data << "Total Distance\t";
//            norm_data << "Total Distance\t";
//        }
//        else if (j == 4) {
//            raw_data << "Execution Time\t";
//            norm_data << "Execution Time\t";
//        }
//        for (int i = 0; i < num_of_implemt; i++)
//        {
//            //get average normalized
//            raw_data << "\t" << sd_adjacency_matrix_aver[j][i];
//        }
//        raw_data << "\n";
//    }

//    raw_data << "******************************************************" << endl;
//    raw_data << "\nAdjacency List, Destination -> Source\n";
//    raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//    for (int j = 0; j < 5; j++)
//    {
//        if (j == 0) {
//            raw_data << "Returned Path\t";
//            norm_data << "Returned Path\t";
//        }
//        else if (j == 1) {
//            raw_data << "Nodes Explored\t";
//            norm_data << "Nodes Explored\t";
//        }
//        else if (j == 2) {
//            raw_data << "Total Cost\t";
//            norm_data << "Total Cost\t";
//        }
//        else if (j == 3) {
//            raw_data << "Total Distance\t";
//            norm_data << "Total Distance\t";
//        }
//        else if (j == 4) {
//            raw_data << "Execution Time\t";
//            norm_data << "Execution Time\t";
//        }
//        for (int i = 0; i < num_of_implemt; i++)
//        {
//            //get average normalized
//            raw_data << "\t" << ds_adjacency_list_aver[j][i];
//        }
//        raw_data << "\n";
//    }

//    raw_data << "******************************************************" << endl;
//    raw_data << "\nAdjacency Matrix, Destination -> Source\n";
//    raw_data << "\t\tIterative DFS\tRecursive DFS\tIterative BFS\tRecursive BFS\tDijkstra\tA*\n";

//    for (int j = 0; j < 5; j++)
//    {
//        if (j == 0) {
//            raw_data << "Returned Path\t";
//            norm_data << "Returned Path\t";
//        }
//        else if (j == 1) {
//            raw_data << "Nodes Explored\t";
//            norm_data << "Nodes Explored\t";
//        }
//        else if (j == 2) {
//            raw_data << "Total Cost\t";
//            norm_data << "Total Cost\t";
//        }
//        else if (j == 3) {
//            raw_data << "Total Distance\t";
//            norm_data << "Total Distance\t";
//        }
//        else if (j == 4) {
//            raw_data << "Execution Time\t";
//            norm_data << "Execution Time\t";
//        }
//        for (int i = 0; i < num_of_implemt; i++)
//        {
//            //get average normalized
//            raw_data << "\t" << ds_adjacency_matrix_aver[j][i];
//        }
//        raw_data << "\n";
//    }


//    raw_data.close();

//    return 0;
//}

