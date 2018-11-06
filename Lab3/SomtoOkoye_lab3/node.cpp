#include "node.h"


Node::Algorithm::Algo(int choice)
{
    if (choice == 1)
        return new TspNaive;
    else if (choice == 2)
        return new TspDp;
    else
        return NULL;
}

Node::Algorithm::Algorithm::Select(int algoId)
{
    if (algoId == TSPDP)
        return new TspDp();
    else if (algoId == TSPNAIVE)
        return new TspNaive();

}
