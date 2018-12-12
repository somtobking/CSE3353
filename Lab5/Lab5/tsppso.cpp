//
// Created by Somto Okoye on 2018-12-02.
//

#include "tsppso.h"


double TspPso::randProb() {
    double p = (rand() / (RAND_MAX + 1.0));
    return p;
}


double TspPso::eval(Solution soln){

    return soln.getCost();
}

void TspPso::execute(Map &m) {
    auto startPso = high_resolution_clock::now();

    //uniform_int_distribution<> randDouble(0, 1);

    Solution best = Solution(m);
    Solution tem = Solution(m);

    //shuffle
    for (int i = 0; i < num_part; i++) {
        for (int j = 1; j < best.getPath().size(); j++)
            path.push_back(j + 1);
        random_shuffle(path.begin(), path.end());
        position = best.computeCost(m);
        p_best = position;

    }

    //main for loop
    for (int t = 0; t < num_iterations; t++) {

        for (int i = 0; i < best.getPath()[i] ; i++) {
            if (best.getPath()[p_best] < best.getPath()[g_best])
                g_best = best.getPath()[p_best];
        }


        for (int i = 1; i < m.getVertex(); i++) {
            for (int j = 1; j < m.getVertex(); j++) {
                tem.swapSoln(i, j, m);
            }

            m.getDis(alpha, beta);
            tem = best;

            // update velocity
            for (int j = 0; tem.getVertex(); j++) {
                double rand = randProb();
                if (alpha > rand) {
                    velocity = p_best;
                    velocity = tem.computeCost(best);
                }
            }

            for (int j = 0; best.getVertex(); j++) {
                double rand = randProb();
                if (beta > rand) {
                    velocity = g_best;
                    velocity = tem.computeCost(best);
                }
            }

            // check for max_velocity
            if (tem.getPath().size() > max_velSize) {
                velocity += velocity + max_velSize / 2;
            }

            // update position
            for (int i = 0; i < best.getPath().size(); i++) {
                int temp = best.getPath()[i] ;
                best.getPath()[i]  = path[position];
                path[position] = temp;
            }

            if (best.getPath()[i] < p_best)
                p_best = best.getPath()[i] ;

        }

    }


    cout << "Path of Nodes(Particle Swarm Optimization): ";
    for (int i = 0; i < best.getPath().size(); i++) {
        cout << best.getPath()[i] << "--->";
    }
    cout << "\nShortest Path(Particle Swarm Optimization): " << best.getCost() << endl;

    auto stopPso = high_resolution_clock::now();
    auto durationPso = duration_cast<microseconds>(stopPso - startPso);
    cout << "Particle Swarm Optimization Algorithm Execution Time : " << durationPso.count() << " microseconds"
         << endl;
    cout << "*****************************" << endl;

}


void TspPso::printAlgo()
{
    cout <<  "Travelling Salesman Particle Swarm Optimization" << endl;
}