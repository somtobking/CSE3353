#ifndef SORT_H
#define SORT_H

#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "SortingAlgo.h"

//Define the pointer to the sort function
typedef void (*Algorithm)(vector<int>&);

// Algo types
const int ALGO_COUNT = 3;

const int BUBBLE = 0;
const int INSERTION = 1;
const int MERGE = 2;

const int ALGO_TYPE[ALGO_COUNT] = { BUBBLE, INSERTION, MERGE };

const string ALGO_NAME[ALGO_COUNT] =
{
    "Bubble Sort",
    "Insertion Sort",
    "Merge Sort"
};

// In Strategy Pattern , this is the Context class
class Sort
{
public:
    Sort();

    void Load(string filename);
    void Execute();
    void Display();
    void Stats();
    void Select(int algoId);
    void Save(string filename);
    void Configure();

private:
    string name;							 // name of sort algo
    Algorithm algo;							 // pointer to the sort function
    high_resolution_clock::time_point start; // start time
    high_resolution_clock::time_point end;   // end time
    vector<int> data;						 // initial data
    vector<int> sorted;						 // data to sort
};


#endif // SORT_H
