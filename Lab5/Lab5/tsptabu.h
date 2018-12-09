//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_TABU_H
#define LAB4_TABU_H

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
#include "map.h"
#include "solution.h"

#define V 8 //Change Max Values

using namespace std;
using namespace std::chrono;

class TspTabu: public Algorithm{
    vector<Solution> tabu_list;
    Solution getShortestPath();
    Solution getNearestNode(Solution bestSoln, Map &m);
    bool exists(Solution s);

    //tabuList size modifications
    int listSize = 10;
    int numOfPerm = 1000;

    // void setTabuListSize(int num);

public:
    vector<int> path;
    void execute(Map &m) override;
    void printAlgo() override;




};



#endif //LAB4_TABU_H
