#ifndef ALGORITHM_H
#define ALGORITHM_H

#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include<queue>

using namespace std;

class Algorithm
{
  public:
    // Abstract class, Factory method
    static Algorithm *Algo(int choice);
    static Algorithm *Select(int algoId);
    virtual void printAlgo() = 0;

};


#endif // ALGORITHM_H


