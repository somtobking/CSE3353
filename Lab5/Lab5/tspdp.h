//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_TSPDP_H
#define LAB4_TSPDP_H

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
    void takeInput();
    void execute(Map &m) override;
    void printAlgo() override;

};

#endif //LAB4_TSPDP_H
