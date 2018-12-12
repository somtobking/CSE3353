//
// Created by Somto Okoye on 2018-11-28.
//

#ifndef LAB4_MAP_H
#define LAB4_MAP_H

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


using namespace std;
using namespace std::chrono;


class Map{
public:
    int getVertex();
    void readDataFile(string filename);
    double getDis(int d1, int d2);


protected:
    int numOfVertex =0;

    struct Node{
        int id;
        float coordinates[3];
    };
    vector<Node> nodes;


};

#endif //LAB4_MAP_H
