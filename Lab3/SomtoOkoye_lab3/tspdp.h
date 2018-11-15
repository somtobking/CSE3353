#ifndef TSPDP_H
#define TSPDP_H

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <array>
#include <math.h>


#include "algorithm.h"

using namespace std;
using namespace std::chrono;

class TspDp: public Algorithm
{
  public:
    int least(int c);
    void mincost(int city);
    //vector<vector<float> > getData(string filename);
    int execute();
    void printAlgo();
};

#endif // TSPDP_H
