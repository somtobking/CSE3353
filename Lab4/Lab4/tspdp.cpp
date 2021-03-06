//
// Created by Somto Okoye on 2018-11-28.
//

#include "tspdp.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <array>
#include <math.h>
#include "tspdp.h"

using namespace std;

#define V 8

int completed[V] = {}, n = V, cost = 0;
double graph[V][V];

void TspDp::takeInput()
{
    ifstream inFile;
    inFile.open("input.txt");
    string line;
    float in_matrix[V][4];
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
           // cout<<graph[i][j]<<"\t";
        }
        //cout<<endl;
    }
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

void TspDp::mincost(int city)
{
    int i,ncity;

    completed[city]=1;

    cout<< city+1 << "--->";
    ncity=least(city);

    if(ncity == 999)
    {
        ncity = 0;
        cout << ncity+1;
        cost += graph[city][ncity];

        return;
    }

    mincost(ncity);
}


void TspDp::execute(Map &m)
{
    auto startNaive = high_resolution_clock::now();

    takeInput();
    cout << "Path of Nodes(DP): ";
    mincost(0); //passing 0 because starting vertex

    cout << "\nShortest Path(DP): "<< cost;
    auto stopnaive = high_resolution_clock::now();

    auto durationNaive = duration_cast<microseconds>(stopnaive - startNaive);
    cout << "\nDynamic Programming Execution Time : " << durationNaive.count() << " microseconds" << endl;
    cout << "*****************************" << endl;

}

void TspDp::printAlgo()
{
    cout << "Travelling Salesman Dynamic Programming" << endl;
}

