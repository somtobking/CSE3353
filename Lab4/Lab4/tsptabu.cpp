//
// Created by Somto Okoye on 2018-11-28.
//

#include "tsptabu.h"

using namespace std;

Solution TspTabu::getShortestPath(){
    float min = 1000;
    int minIndex = 0;
    for(int i = 0; i < tabu_list.size(); i++){
        if(tabu_list[i].getCost() < min){
            minIndex = i;
        }
    }
    return tabu_list[minIndex];
}

Solution TspTabu::getNearestNode(Solution bestSoln, Map &g) {
    Solution temp = bestSoln;
    for(int i = 1; i < g.getVertex(); i++){
        for(int j = 1; j < g.getVertex(); j++){
            temp.swapSoln(i,j,g);
            if((temp.getCost() < bestSoln.getCost()) && !exists(temp)){
                bestSoln = temp;
            }
        }
    }
    return bestSoln ;
}

bool TspTabu::exists(Solution s) {
    for(int i = 0; i < tabu_list.size(); i++){
        if(s == tabu_list[i])
            return true;
    }
    return false;
}


void TspTabu::setTabuListSize(int num) {
    listSize = num;
}

void TspTabu::execute(Map &m) {
    auto startTabu = high_resolution_clock::now();
    path.clear();
    tabu_list.clear();
    Solution best = Solution(m);
    tabu_list.push_back(best);
    int numAttempts = 0;
    while(numAttempts < numOfPerm) {
        best = getNearestNode(best, m);
        tabu_list.push_back(best);

        if(tabu_list.size() > listSize){
            tabu_list.erase(tabu_list.begin());
        }
        numAttempts++;
    }

    best = getShortestPath();
    cout << "Path of Nodes(Tabu Search): ";
    for (int i = 0; i < best.getPath().size(); i++)
    {
        cout << best.getPath()[i] << "--->";
    }
    cout << "\nShortest Path(Tabu Search): " << best.getCost() << endl;

    auto stopTabu = high_resolution_clock::now();
    auto durationNaive = duration_cast<microseconds>(stopTabu - startTabu);
    cout << "Tabu Search Algorithm Execution Time : " << durationNaive.count()<<" microseconds" << endl;
    cout << "*****************************" << endl;
}

void TspTabu::printAlgo()
{
    cout <<  "Travelling Salesman Tabu Search" << endl;
}

