#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
using namespace std;

// In Strategy Pattern Terminology, this is the Strategy
class Algorithm
{
public:
    Algorithm() {}
    virtual ~Algorithm() {}

    virtual void Load(string filename) = 0;
    virtual void Execute() = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Select(int algoId) = 0;
    virtual void Save(string filename) = 0;
    virtual void Configure() = 0;
};


#endif // ALGORITHM_H
