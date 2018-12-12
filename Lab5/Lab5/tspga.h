//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_TSPGA_H
#define LAB4_TSPGA_H

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
#include <random>

#include "algorithm.h"
#include "map.h"
#include "solution.h"

#define V 4 //Change Max Values

using namespace std;
using namespace std::chrono;

class TspGa:public Algorithm
{
    int pop_size = 1500;
    void popStart(Map &m);
    vector<Solution> population;
    double mutation_rate = 0.6;
    int numOfPerm = 1000;
    int maxGen = 500;
    int parentNum[2] = {0,0};
    float meanPath = 0;
    Solution minCost();

public:
    //enum for managing the multiple techniques for genetic algorithm
    enum selectGa {
        Scaling,
        Elitist,
        Roulette,
        };

    void selectParents(selectGa type);
    Solution mutate(Solution mut, Map &m);
    void crossover(int p1, int p2, Map &m);

    void execute(Map &m) override;
    void printAlgo() override;

    //double avgPath();



};

#endif //LAB4_TSPGA_H
