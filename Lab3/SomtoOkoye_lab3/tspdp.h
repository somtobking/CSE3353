#ifndef TSPDP_H
#define TSPDP_H

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <fstream>

#include "algorithm.h"


using namespace std;
using namespace std::chrono;

class TspDp: public Algorithm
{
  public:
    int least(int c);
    void mincost(int city);
    int execute();
    void takeInput();
    void printAlgo();
};

#endif // TSPDP_H
