#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>
using namespace std;

typedef int TYPENAME;

// In Strategy Pattern, this is the Strategy
class Algorithm
{
public:

    Algorithm();
    virtual ~Algorithm();
    virtual void Execute(vector<TYPENAME>& data) = 0;
    virtual string GetName() const = 0;
};


#endif // ALGORITHM_H
