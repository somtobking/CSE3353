//Author: Somto Okoye
//Class: CSE 3353

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <string>

#include "searchalgo.h"

#define TEST false

using namespace std;

int main( int argc, char* const argv[] )
{
    //After test is complete, uncomment and run. Maybe put test in sample graph folder
    int source = 1, destination = 2, number_of_impl = 6;
    if (argc == 3)
    {
        source = stoi(string(argv[1]));
        destination = stoi(string(argv[2]));
    }

    SearchAlgo Search;
    Search.Load(".txt");
    for (int i = 1; i <= number_of_impl; ++i)
    {
        Search.Select(i);
        Search.Execute(source, destination);
        Search.Save(to_string(i));
        Search.Stats();
    }

    return 0;
}

