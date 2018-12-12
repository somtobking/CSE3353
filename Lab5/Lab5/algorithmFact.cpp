//
// Created by Somto Okoye on 2018-11-28.
//

#include "algorithmFact.h"


Algorithm* AlgorithmFact::typeOfAlgo(int choice)
{
    if(choice ==1){
        Algorithm *algo = new TspNaive();
        return algo;
    } else if(choice ==2) {
        Algorithm *algo = new TspDp();
        return algo;
    } else if(choice ==3) {
        Algorithm *algo = new TspTabu();
        return algo;
    }else if(choice ==4) {
        Algorithm *algo = new TspGa();
        return algo;
    } else if(choice ==5) {
        Algorithm *algo = new TspSa();
        return algo;
    }else if(choice ==6) {
        Algorithm *algo = new TspPso();
        return algo;
    }
    else
        return NULL ;
}






