#include "tspdp.h"

#include "graph.h"

using namespace std;
Graph gra;

#define V 4

int completed[V] = {}, n = V , cost = 0;
double graph[V][V];

void TspDp::mincost(int city)
{
    int ncity;
    completed[city]=1;
    cout<< city + 1 <<"--->";
    ncity=least(city);
    //Now we call the sort function

    if(ncity == 999)
    {
        ncity = 0;
        cout << ncity+1;
        cost += graph[city][ncity];
        //std::sort(city, city + V);

        return;
    }

    mincost(ncity);
}

int TspDp::least(int c)
{
    int i, nc=999;
    double min=999,kmin;

    for(i=0; i<n; ++i)
    {
        if((graph[c][i] > 0) && (completed[i] == 0))
            if(graph[c][i] + graph[i][c] < min)
            {
                min = graph[i][0] + graph[c][i];
                kmin = graph[c][i];

                nc = i;
            }
    }

    if(int(min) != 999)
        cost += kmin;

    return nc;
}



int TspDp::execute()
{
    auto startNaive = high_resolution_clock::now();
    gra.readDataFromFile();
    cout << "Path of Nodes(DP): ";
    mincost(0); //passing 0 due to the starting vertex of node 1
    cout << endl;
    cout << "Shortest Path(DP): " << cost << endl;


    auto stopnaive = high_resolution_clock::now();
    auto durationNaive = duration_cast<microseconds>(stopnaive - startNaive);
    cout << "Dynamic Programming Algorithm Execution Time : " << durationNaive.count()<<" miliseconds" << endl;
    cout << "*****************************" << endl;

    return 0;
}

void TspDp::printAlgo()
{
    cout << "Travelling Salesman Dynamic Programming" << endl;
}
