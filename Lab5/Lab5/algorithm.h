//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_ALGORITHM_H
#define LAB4_ALGORITHM_H


#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include<queue>

#include "map.h"

using namespace std;

class Algorithm
{
public:
    //Abstract class
    virtual void execute(Map &m) =0;
    virtual void printAlgo() =0;
    vector<int> path;

};

#endif //LAB4_ALGORITHM_H
