//
// Created by Somto Okoye on 2018-11-28.
//

#include <iostream>
#include "solution.h"

Solution::Solution(Map &m)
{
    inSoln(m);
}

void Solution::inSoln(Map &m)
{

    for(int i = 2; i <= m.getVertex(); i++)
        path.push_back(i);
    random_shuffle(path.begin(), path.end());
    path.push_back(1);
    path.insert(path.begin(), 1);
    computeCost(m);
}

void Solution::computeCost(Map &m)
{
    cost = 0;
    for(int i = 0; i < path.size() - 1; i++){
        cost += m.getDis(path[i], path[i + 1]);
    }
}

int Solution::getVertex()
{
    return path.size();
}

int Solution::getCost()
{
    return cost;
}

//getter for path
vector<int> Solution::getPath()
{
    return path;
}

//setter for path
void Solution::setPath(vector<int> &newPath)
{
    path = newPath;
}


void Solution::swapSoln(int i, int j, Map &m)
{
    int temp = path[i];
    path[i] = path[j];
    path[j] = temp;
    computeCost(m);
}


bool Solution::isEmpty() {
    if(path[0] != 1 || path[path.size() - 1] != 1)
        return false;
    int count;
    for(int i = 2; i < path.size(); i++){
        count  = 0;
        for(int j = 2; j < path.size(); j++){
            if(path[j] == i)
                count++;
        }
        if(count > 1)
            return false;
    }
    return true;
}


//overload operator function
bool Solution::operator==(const Solution &rhs) const {
    return (this->path == rhs.path);
}