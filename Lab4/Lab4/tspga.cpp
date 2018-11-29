//
// Created by Somto Okoye on 2018-11-28.
//

#include "tspga.h"

//initialize start population for genetic algorithm
void TspGa::popStart(Map &m)
{
    population.clear();
    parentNum[0] = 0;
    parentNum[1] = 0;
    for(int i = 0; i < pop_size; i++)
    {
        population.push_back(Solution(m));
    }
}

//minimized distance
Solution TspGa::minCost()
{
    int index = 0;
    float minSize = 100;
    for(int i = 0; i < population.size(); i++)
    {
        if(population[i].getCost() < minSize)
        {
            minSize = population[i].getCost();
            index = i;
        }
    }
    //return the minCost
    return population[index];
}


//create and select the parents from the input
void TspGa::selectParents(TspGa::selectGa type)
{
    //start with randomly generated selection technique for attempted solutions
    if(type == TspGa::selectGa ::Scaling)
    {
        uniform_int_distribution<int> distribution(0,pop_size - 1);
        default_random_engine generator;
        parentNum[0] = distribution(generator);
        parentNum[1] = distribution(generator);
    }

    //try Elitist technique
    else if(type == TspGa::selectGa ::Elitist)
    {
        double bestSoln = 0;
        int first = 0, second = 0;
        for(int i = 0; i < population.size(); i++){
            if(population[i].getCost() > bestSoln){
                second = first;
                first = i;
            }
        }
        parentNum[0] = first;
        parentNum[1] = second;
    }

    //try the biased roulette wheel selection technique
    else if(type == TspGa::selectGa::Roulette)
    {
        vector<float> newPath;
        double sumFitness = 0;
        for(int i = 0; i < population.size(); i++){
            sumFitness += population[i].getCost();
        }
        for(int i = 0; i < population.size(); i++){
            newPath.push_back(population[i].getCost()/sumFitness);
        }
        double ind1 = rand();
        double ind2 = rand();
        float fitness = 0;

        //each individual gets a piece of the wheel, but more fit ones get larger slices
        //than less fit ones.
        for(int i = 0; i < newPath.size(); i++)
        {
            fitness += newPath[i];
            if(ind1 < fitness && parentNum[0] == 0)
            {
                parentNum[0] = i;
            } else if(ind2 < fitness && parentNum[1] ==1)
            {
                parentNum[1] = i;
            }
        }
    }

}

//create a random mutation by swapping
Solution TspGa::mutate(Solution mut, Map &m)
{
    uniform_int_distribution<int> distribution(1,mut.getPath().size()-1);
    default_random_engine generator;
    int mutation1 = distribution(generator);
    int mutation2 = distribution(generator);
    mut.swapSoln(mutation1, mutation2, m);
    return m;
}

//generate a crossover between parents and offsprings
void TspGa::crossover(int p1, int p2, Map& m)
{

    Solution offspring1(m), offspring2(m);
    vector<int> osPath1, osPath2;
    int numOfAttempts = 0;
    vector<int> parent1 = population[p1].getPath();
    vector<int> parent2 = population[p2].getPath();

    uniform_int_distribution<int> distribution(1,offspring1.getPath().size()-1);
    default_random_engine generator;

    //assign the cutoff to a randomly generated number
    int cutoff = distribution(generator);
    for(int i = 0; i < parent1.size(); i++)
    {
        numOfAttempts++;

        if(i < cutoff)
        {
            osPath1.push_back(parent1[i]);
            osPath2.push_back(parent2[i]);
        }
        else
            {
            osPath1.push_back(parent2[i]);
            osPath2.push_back(parent1[i]);
        }
    }

    //another technique for mutation using the mutation rate value given
    int mutation = rand() % 100 + 1;
    if(mutation < mutation_rate)
    {
        offspring1 = mutate(offspring1,m);
    }
    //else
//    {
//        offspring2 = mutate(offspring2,m);
//    }
    offspring1.setPath(osPath1);
    offspring2.setPath(osPath2);

    if(offspring1.isEmpty()){
        population.push_back(offspring1);
        population.erase(population.begin() + p1);
    }
    if(offspring2.isEmpty()){
        population.push_back(offspring1);
        population.erase(population.begin() + p2);
    }
}


double TspGa::avgPath()
{
    return meanPath/numOfPerm;
}

void TspGa::execute(Map &m)
{
    auto startGA = high_resolution_clock::now();

    //create the population with the nodes input
    popStart(m);

    for(int i = 0; i < maxGen; i++)
    {
//        function for testing multiple selection techniques
//        options are:  Random , Elitist and Roulette

            //set elitist selection to default selection technique
        selectParents(selectGa ::Elitist);
        crossover(parentNum[0], parentNum[1], m);
    }

    Solution best = minCost();
    meanPath += best.getCost();
    numOfPerm++;

    cout << "Path of Nodes(Genetic Algorithm): ";
    for (int i = 0; i < best.getPath().size(); i++)
    {
        cout << best.getPath()[i] << "--->";
    }
    cout << "\nShortest Path(Genetic Algorithm): " << best.getCost() << endl;

    auto stopGA = high_resolution_clock::now();
    auto durationNaive = duration_cast<microseconds>(stopGA - startGA);
    cout << "Genetic Algorithm Execution Time : " << durationNaive.count()<<" microseconds" << endl;
    cout << "*****************************" << endl;
}

void TspGa::printAlgo()
{
    cout <<  "Travelling Salesman Genetic Algorithm" << endl;
}
