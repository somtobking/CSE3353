#include "graph.h"
#include "tspnaive.h"
#include "tspdp.h"

#define V 4
int completed[V] = {}, n = V , cost = 0;
double graph[V][V];

TspNaive tsn;

void Graph::readDataFromFile()
{
    ifstream inFile;
    inFile.open("input.txt");
    string line;
    float in_matrix[V][V];
    int i = 0 , j = 0;
    while(getline(inFile,line))
    {
        std::stringstream linestream(line);
        std::string value;

        while(getline(linestream,value,','))
        {
            in_matrix[i][j] = ::atof(value.c_str());
            ++j;
        }
        j = 0;
        ++i;
    }
    for(int i = 0; i < V; ++i)
    {
        for(int j = 0; j < V; ++j)
        {
            graph[i][j] = sqrt((in_matrix[i][1] - in_matrix[j][1]) * (in_matrix[i][1] - in_matrix[j][1]) + (in_matrix[i][2] - in_matrix[j][2]) * (in_matrix[i][2] - in_matrix[j][2]) + (in_matrix[i][3] - in_matrix[j][3]) * (in_matrix[i][3] - in_matrix[j][3]));
        }
    }
    for(int i = 0; i < V; ++i)
    {
        for(int j = 0; j < V; ++j)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
        int s = 0;
        cout << tsn.travllingSalesmanProblem(graph, s) << endl;
    }
}
