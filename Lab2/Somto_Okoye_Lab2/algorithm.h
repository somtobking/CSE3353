#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
using namespace std;

// In Strategy Pattern Terminology, this is the Strategy class, fixed from the last project
class Algorithm
{
public:
    virtual int Load(string filename) = 0;
    virtual void Execute(int source, int destination) = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Select(int searchId) = 0;
    virtual void Save(string filename) = 0;


    //for sorting algorithm
    //virtual void Execute(vector<TYPENAME>& data) = 0;
    //virtual void Configure() = 0;
};


#endif // ALGORITHM_H
