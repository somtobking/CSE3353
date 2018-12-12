//
// Created by Somto Okoye on 2018-12-02.
//

#include "tspsa.h"

using namespace std;


double TspSa::randProb() {
    double p = (rand() / (RAND_MAX + 1.0));
    return p;
}

double TspSa::eval(Solution soln) {

    return soln.getCost();
}

void TspSa::execute(Map &m) {
    auto startSa = high_resolution_clock::now();

    Solution tem = Solution(m);
    for(int i = 1; i < m.getVertex(); i++){
        for(int j = 1; j < m.getVertex(); j++){
          tem.swapSoln(i,j,m);
            }
        }
    Solution best = m;
    minTour = best.computeCost(m);

    for (int i=0; i< pr_size; i++){
        path.push_back(i);
        random_shuffle(path.begin(), path.end());
       double tCost = best.computeCost(m);
       if(tCost < minTour){
           best = tem;
           minTour = tCost;
       }
    }

    tem = best;
    double prob, expP, deltaE;

    //temperature function
    for (double T = temp; T > 0.01; T *= 0.5){

        for(int i =0; i < 10; i++){
            Solution num = Solution(m);
            for(int i = 1; i < m.getVertex(); i++){
                for(int j = 1; j < m.getVertex(); j++){
                    num.swapSoln(i,j,m);
                }
            }

            deltaE = eval(tem) - eval(num);
            deltaE /= T;
            prob = 1 / (1 + exp(-1*deltaE));
            expP = randProb();

            //move to the new solution
            if(expP < prob){
                tem = num;
               double tCost = best.computeCost(m);
               if(tCost < minTour){
                    best = tem;
                    minTour = tCost;
               }
            }
        }
    }

    cout << "Path of Nodes(Simulated Annealing): ";
    for (int i = 0; i < best.getPath().size(); i++)
    {
        cout << best.getPath()[i] << "--->";
    }
    cout << "\nShortest Path(Simulated Annealing): " <<  best.getCost() << endl;

    auto stopSa = high_resolution_clock::now();
    auto durationSa = duration_cast<microseconds>(stopSa - startSa);
    cout << "Simulated Annealing Algorithm Execution Time : " << durationSa.count()<<" microseconds" << endl;
    cout << "*****************************" << endl;

}


void TspSa::printAlgo()
{
    cout <<  "Travelling Salesman Simulated Annealing" << endl;
}