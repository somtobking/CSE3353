#include <iostream>
#include <vector>
#include "algorithm.h"
#include "algorithmFact.h"
#include "tspdp.h"
#include "tspnaive.h"
#include "tsptabu.h"
#include "tspga.h"
#include "map.h"
#include "solution.h"


using namespace std;
using namespace std::chrono;

//Change Node values (MAX values in tspNaive.h)
//Change Node Values (MAX Values in tspDp.cpp)
//Change Node values (MAX values in tspTabu.h)
//Change Node values (MAX values in tspGa.h)
//Change Node values (MAX values in tspPso.h)
//Change Node values (MAX values in tspSa.h)

int main()
{

    cout << "**********************************" << endl;
    Algorithm* type;
    AlgorithmFact af;
    Map m;

    //input graph file
    m.readDataFile("input.txt");

    //number of algorithms in the project
    int algo_type = 6;

 for(int i=1; i <= algo_type; i++)
 {
     type = af.typeOfAlgo(i);
     type->printAlgo();
     type->execute(m);
 }

 return 0;
}



