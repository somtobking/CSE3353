//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_ALGORITHMFACT_H
#define LAB4_ALGORITHMFACT_H


#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include<queue>

#include "algorithm.h"
#include "tspdp.h"
#include "tspnaive.h"
#include "tsptabu.h"
#include "tspga.h"

using namespace std;

class AlgorithmFact
{
public:
    //Factory Method
    Algorithm* typeOfAlgo(int choice);

};

#endif //LAB4_ALGORITHMFACT_H
