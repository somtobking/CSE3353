#ifndef NODE_H
#define NODE_H

#include "algorithm.h"
#include "tspnaive.h"
#include "tspdp.h"

using namespace std;

//Algo types
const int ALGO_COUNT = 3;
const int TSPNAIVE = 1;
const int TSPDP = 2;
const int ALGO_TYPE[ALGO_COUNT] = {TSPNAIVE, TSPDP};

class Node : public Algorithm
{
public:
    Algorithm Algo(int choice);
    Algorithm Select(int algoId);

};



#endif // NODE_H
