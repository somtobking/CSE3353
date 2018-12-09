//
// Created by Somto Okoye on 2018-12-02.
//

#ifndef LAB5_TSPPO_H
#define LAB5_TSPPO_H


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


class TspPso: public Algorithm{
public:
    void execute(Map &m) override;
    void printAlgo() override;

};
#endif //LAB5_TSPPO_H
