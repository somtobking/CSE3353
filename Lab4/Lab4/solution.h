//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_SOLUTION_H
#define LAB4_SOLUTION_H



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
#include <string>
#include<vector>
#include <math.h>

#include "map.h"

using namespace std;
using namespace std::chrono;

class Solution {
    vector<int> path;
    float cost;
public:
    Solution (Map &m);
    void inSoln(Map &m);
    void computeCost(Map &m);
    int getVertex();
    int getCost();
    vector<int> getPath();
    void setPath(vector<int> &newPath);
    void swapSoln(int i, int j, Map &m);
    bool isEmpty();

    //overload operator function
    bool operator ==(const Solution& rhs) const;

};


#endif //LAB4_SOLUTION_H


