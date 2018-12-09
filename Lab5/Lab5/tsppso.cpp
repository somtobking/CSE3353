//
// Created by Somto Okoye on 2018-12-02.
//

#include "tsppso.h"



void TspPso::execute(Map &m) {
    auto startPso = high_resolution_clock::now();

//    Solution best = Solution(m);
//
//    best = getShortestPath();
//    cout << "Path of Nodes(Particle Swarm Optimization): ";
//    for (int i = 0; i < best.getPath().size(); i++)
//    {
//        cout << best.getPath()[i] << "--->";
//    }
//    cout << "\nShortest Path(Particle Swarm Optimization): " << best.getCost() << endl;

    auto stopPso = high_resolution_clock::now();
    auto durationPso = duration_cast<microseconds>(stopPso - startPso);
    cout << "Simulated Annealing Algorithm Execution Time : " << durationPso.count()<<" microseconds" << endl;
    cout << "*****************************" << endl;

}

void TspPso::printAlgo()
{
    cout <<  "Travelling Salesman Particle Swarm Optimization" << endl;
}