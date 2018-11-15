#include <iostream>
#include <vector>
#include "algorithm.h"
#include "tspdp.h"
#include "tspnaive.h"
#include "graph.h"

using namespace std;
using namespace std::chrono;

// Algo types
const int ALGO_COUNT = 3;
const int TSPNAIVE = 1;
const int TSPDP = 2;
const int ALGO_TYPE[ALGO_COUNT] = {TSPNAIVE, TSPDP};

Algorithm *Algorithm::Algo(int choice)
{
    if (choice == 1)
        return new TspNaive;
    else if (choice == 2)
        return new TspDp;
    else
        return NULL;
}


//Algorithm *Algorithm::Select(int algoId)
//{
//    if (algoId == TSPDP)
//        return new TspDp();
//    else if (algoId == TSPNAIVE)
//        return new TspNaive();
//}

int main()
{
    vector<Algorithm*> type;
    TspNaive tspNa;
    TspDp tspDP;
    Graph gra;


    //int choice;
    for(auto choice: ALGO_TYPE)
        tspNa.Select(choice);
        {
            tspNa.printAlgo();
            tspNa.execute();
            tspDP.printAlgo();
            tspDP.execute();
        }

}



