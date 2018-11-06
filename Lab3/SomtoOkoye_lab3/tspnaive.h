#ifndef TSPNAIVE_H
#define TSPNAIVE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <limits>
#include <fstream>
#include <sstream>
#include <array>
#include <math.h>

#include "algorithm.h"

#define V 4 //Change Max Values

using namespace std;
using namespace std::chrono;

class TspNaive: public Algorithm
{
  public:
    void readDataFromFile();
    int travllingSalesmanProblem(double graph[][V], int s);
    int execute();
    void printAlgo();
};

#endif // TSPNAIVE_H
