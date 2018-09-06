#include <iostream>
#include <fstream>
using namespace std;

#include "Sort.h"


Sort::Sort()
{
}

//Takes a filename as and can read input data file]
void Sort::Load(string filename)
{
    data.clear();
    ifstream in(filename);
    int i;
    while (in >> i)
        data.push_back(i);
}

//Executes the algorithm]
void Sort::Execute()
{
    sorted = data;
    start = high_resolution_clock::now();
    algo(sorted);
    end = high_resolution_clock::now();

}

//Prints original array and solution to screen
void Sort::Display()
{
    cout << "Starting Array: " ;
    for (const auto& i : data)
    cout << i << " ";
    cout << endl;

    cout<< "Ending Array: ";
    for (const auto& i : sorted)
    cout << i << " ";
    cout << endl;
}

//print out stats-time using chrono
void Sort::Stats()
{
    if (algo)
    {
        cout << name << endl;
        duration<double> elapsed = duration_cast<duration<double>>(end - start);
        cout << "Time Elapsed: " << elapsed.count() << "sec" << endl;
        cout << "DataSet Size: " << data.size() << endl << endl;
    }
}

void Sort::Select(int algoId)
{
    // Select sorting algorithm
    if (algoId == BUBBLE)
    {
        name = ALGO_NAME[BUBBLE];
        algo = &SortingAlgo::BubbleSort<int>;
    }
    else if (algoId == INSERTION)
    {
        name = ALGO_NAME[INSERTION];
        algo = &SortingAlgo::InsertionSort<int>;
    }
    else if (algoId == MERGE)
    {
        name = ALGO_NAME[MERGE];
        algo = &SortingAlgo::MergeSort<int>;
    }
}

//save results to the output file
void Sort::Save(string filename)
{
    ofstream out(filename);
    if (out)
    {
        for (const auto& i : sorted)
            out << i << endl;
    }
}

void Sort::Configure()
{
    //intentionally left blank, for future use
}
