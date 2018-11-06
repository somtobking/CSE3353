#include "tspnaive.h"

using namespace std;

int TspNaive::travllingSalesmanProblem(double graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    std::array<int,V> temp = {};
    std::array<int,V> path = {};

    int min_path = INT8_MAX;
    do {

        int current_pathweight = 0;

        int k = s;
        temp[0] = k;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            temp[i] = k;
        }
        current_pathweight += graph[k][s];
        if(current_pathweight < min_path)
        {
            std::copy(std::begin(temp), std::end(temp), std::begin(path));
        }

        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    cout << "Path of Nodes(Naive): ";
    cout << s + 1 << "--->";
    for(int k = 0; k < V; ++k)
    {
        cout << path[k] + 1 << "--->";
    }
    cout << endl;
    cout << "Shortest Path(Naive): " ;
    return min_path;
}

void TspNaive::readDataFromFile()
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
    double graph[V][V];
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
    }
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;

}

int TspNaive::execute()
{
    readDataFromFile();
    auto startNaive = high_resolution_clock::now();
    auto stopnaive = high_resolution_clock::now();
    auto durationNaive = duration_cast<microseconds>(stopnaive - startNaive);
    cout << "Naive Algorithm Execution Time : " << durationNaive.count()<<" miliseconds" << endl;
    cout << "*****************************" << endl;

    return 0;
}

void TspNaive::printAlgo()
{
    cout <<  "Travelling Salesman Brute Force (Naive)" << endl;
}
